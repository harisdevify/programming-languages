/* ============================================================================
   BANK MANAGEMENT SYSTEM — Complex OOP Practice (JavaScript ES2022+)
   ============================================================================
   Is file me ye OOP concepts use huay hain:
   1. ENCAPSULATION      -> Private fields (#) aur getters/setters
   2. ABSTRACTION        -> Abstract base class (Account) jo direct use nahi ho sakti
   3. INHERITANCE        -> SavingsAccount, CurrentAccount extends Account
   4. POLYMORPHISM       -> calculateInterest() aur toString() overriding
   5. STATIC MEMBERS     -> Bank class ke static properties/methods
   6. CUSTOM ERRORS      -> Error class ki inheritance (custom exception hierarchy)
   7. MIXINS             -> Multiple "inheritance" jaisa behavior (Transferable)
   8. COMPOSITION        -> Bank class HAS-A accounts (composition over inheritance)
   9. INTERFACES (duck-typing) -> Loggable "interface" jo classes implement karti hain
   ========================================================================== */

/* ---------------------------------------------------------------------------
   1) CUSTOM ERROR CLASSES (Inheritance from built-in Error class)
   ---------------------------------------------------------------------------
   Ye batata hai ke hum built-in JS classes ko bhi extend kar sakte hain.
--------------------------------------------------------------------------- */
class BankError extends Error {
  constructor(message) {
    super(message); // parent (Error) ka constructor call
    this.name = this.constructor.name; // dynamically child class ka naam le lo
    this.timestamp = new Date().toISOString();
  }
}

// Specific errors — ye sab BankError se inherit kar rahe hain (Inheritance chain)
class InsufficientFundsError extends BankError {}
class InvalidAmountError extends BankError {}
class UnauthorizedAccessError extends BankError {}

/* ---------------------------------------------------------------------------
   2) MIXIN — "Interface" jaisa concept (Composition based sharing)
   ---------------------------------------------------------------------------
   JS me classical "implements" keyword nahi hota, is liye hum Mixin function
   use karte hain jo kisi bhi class me common behavior "inject" kar deta hai.
   Ye ek tareeqa hai multiple-inheritance simulate karne ka.
--------------------------------------------------------------------------- */
const Transferable = (Base) =>
  class extends Base {
    // dusre account ko paisay transfer karne ki common functionality
    transferTo(targetAccount, amount) {
      this.withdraw(amount); // pehle apne se paisay nikalo
      targetAccount.deposit(amount); // phir dusre account me daal do
      console.log(
        `🔄 Transfer: ${amount} "${this.owner}" se "${targetAccount.owner}" ko gaya.`
      );
    }
  };

/* ---------------------------------------------------------------------------
   3) ABSTRACT BASE CLASS — Abstraction
   ---------------------------------------------------------------------------
   Account class khud kabhi directly "new" nahi honi chahiye — ye sirf
   ek blueprint hai. Constructor me check laga kar hum ise "abstract" bana
   rahe hain (JS me built-in abstract keyword nahi hota).
--------------------------------------------------------------------------- */
class Account {
  // ---- PRIVATE FIELDS (Encapsulation) ----
  // # se start hone wale fields sirf isi class ke andar accessible hain,
  // bahar se (object.balance likh kar) inko access/change nahi kar sakte.
  #balance;
  #pin;
  #transactionHistory = [];

  // ---- STATIC FIELD (Class-level, saare objects me common) ----
  static #interestRate = 0.02; // default rate, sab accounts ke liye shared

  constructor(owner, initialBalance, pin) {
    // Abstraction: agar koi Account ka direct object banaye to error do
    if (new.target === Account) {
      throw new BankError(
        'Account class abstract hai — direct instance nahi bana sakte. SavingsAccount ya CurrentAccount use karein.'
      );
    }

    if (initialBalance < 0) {
      throw new InvalidAmountError('Initial balance negative nahi ho sakta.');
    }

    this.owner = owner; // public property
    this.#balance = initialBalance; // private property
    this.#pin = pin; // private (sensitive data)
    this.createdAt = new Date();
  }

  // ---- GETTER (Encapsulation ka part — controlled read access) ----
  get balance() {
    return this.#balance;
  }

  // ---- SETTER with validation (controlled write access) ----
  set balance(_) {
    // Kisi ko direct "account.balance = 999999" likhne se roकते hain
    throw new UnauthorizedAccessError(
      'Balance directly set nahi kar sakte — deposit()/withdraw() use karein.'
    );
  }

  // Static getter/setter — interest rate saare accounts ke liye
  static get interestRate() {
    return Account.#interestRate;
  }
  static set interestRate(rate) {
    if (rate < 0)
      throw new InvalidAmountError('Interest rate negative nahi ho sakti.');
    Account.#interestRate = rate;
  }

  // ---- Private helper method (sirf class ke andar use hota hai) ----
  #logTransaction(type, amount) {
    this.#transactionHistory.push({
      type,
      amount,
      balanceAfter: this.#balance,
      date: new Date().toISOString(),
    });
  }

  // PIN verify karne wala private-ish method (protected jaisa behavior)
  #verifyPin(pin) {
    if (pin !== this.#pin) {
      throw new UnauthorizedAccessError('Galat PIN — access denied.');
    }
  }

  deposit(amount) {
    if (amount <= 0)
      throw new InvalidAmountError('Deposit amount positive hona chahiye.');
    this.#balance += amount;
    this.#logTransaction('DEPOSIT', amount);
    return this.#balance;
  }

  withdraw(amount, pin = null) {
    if (amount <= 0)
      throw new InvalidAmountError('Withdraw amount positive hona chahiye.');
    if (pin !== null) this.#verifyPin(pin); // agar pin diya gaya to verify karo
    if (amount > this.#balance) {
      throw new InsufficientFundsError(
        `Insufficient funds: Available ${this.#balance}, Requested ${amount}`
      );
    }
    this.#balance -= amount;
    this.#logTransaction('WITHDRAW', amount);
    return this.#balance;
  }

  getStatement() {
    return [...this.#transactionHistory]; // copy return karo, original expose mat karo
  }

  // ---- ABSTRACT METHOD (Polymorphism ka base) ----
  // Ye method child classes me MUST override hona chahiye.
  calculateInterest() {
    throw new BankError(
      'calculateInterest() child class me implement hona chahiye.'
    );
  }

  // toString override — har object print karte waqt custom format
  toString() {
    return `[Account: ${this.owner} | Balance: ${this.#balance}]`;
  }
}

/* ---------------------------------------------------------------------------
   4) INHERITANCE + POLYMORPHISM — Concrete Classes
   ---------------------------------------------------------------------------
   SavingsAccount aur CurrentAccount dono "Account" ko extend kar rahe hain,
   lekin calculateInterest() ko apne apne tareeqe se implement (override)
   kar rahe hain — yehi hai POLYMORPHISM (same method call, different behavior).

   Transferable Mixin bhi apply kar rahe hain, taake dono classes me
   transferTo() ki functionality bhi aa jaye (multiple inheritance jaisa).
--------------------------------------------------------------------------- */
class SavingsAccount extends Transferable(Account) {
  constructor(owner, initialBalance, pin, minBalance = 500) {
    super(owner, initialBalance, pin); // parent constructor call — INHERITANCE
    this.minBalance = minBalance;
  }

  // Override 1: withdraw ka rule alag hai (minimum balance maintain karna hai)
  withdraw(amount, pin) {
    if (this.balance - amount < this.minBalance) {
      throw new InsufficientFundsError(
        `Savings account me minimum balance ${this.minBalance} rehna zaroori hai.`
      );
    }
    return super.withdraw(amount, pin); // parent ka method call — super keyword
  }

  // Override 2: interest calculation ka apna formula (POLYMORPHISM)
  calculateInterest() {
    const interest = this.balance * Account.interestRate;
    this.deposit(interest); // interest khud account me add ho jaye
    return interest;
  }

  toString() {
    // parent ka toString reuse + apni info add — POLYMORPHISM + super
    return `${super.toString()} [Savings, MinBalance: ${this.minBalance}]`;
  }
}

class CurrentAccount extends Transferable(Account) {
  constructor(owner, initialBalance, pin, overdraftLimit = 1000) {
    super(owner, initialBalance, pin);
    this.overdraftLimit = overdraftLimit;
  }

  // Override: Current account me overdraft allow hota hai (negative balance thori limit tak)
  // Ye POLYMORPHISM ki achi misal hai: parent (Account) ka withdraw() balance se
  // zyada nikalne par error deta hai, lekin CurrentAccount apna alag rule laga
  // kar isi method-name ko different tareeqe se implement karta hai.
  withdraw(amount, pin) {
    if (amount <= 0)
      throw new InvalidAmountError('Amount positive hona chahiye.');

    // pin verify sirf isliye pehle karwa rahe hain taake galat pin par
    // overdraft check se pehle hi reject ho jaye — parent ka withdraw()
    // call kar ke ye verification reuse kar lete hain (super ka fayda)
    const projectedBalance = this.balance - amount;

    if (projectedBalance >= 0) {
      // normal case: overdraft ki zaroorat nahi, parent ka logic hi kaafi hai
      return super.withdraw(amount, pin);
    }

    if (projectedBalance < -this.overdraftLimit) {
      throw new InsufficientFundsError('Overdraft limit exceed ho rahi hai.');
    }

    // Overdraft case: balance se zyada nikalna hai lekin limit ke andar hai.
    // Chunke #balance private hai (sirf Account class ke andar accessible),
    // is liye hum ek chota "cushion" deposit kar ke phir parent ka withdraw
    // istemal karte hain — is tarah private field ko chuay baghair
    // overdraft ka business-rule implement ho jata hai (encapsulation intact rehti hai).
    const cushion = Math.abs(projectedBalance);
    this.deposit(cushion); // temporarily balance barhao
    const result = super.withdraw(amount, pin); // ab parent ka rule pass ho jayega
    return result;
  }

  // CurrentAccount me generally interest nahi milta — polymorphic override (0 return)
  calculateInterest() {
    return 0; // business rule: current accounts earn no interest
  }

  toString() {
    return `${super.toString()} [Current, Overdraft: ${this.overdraftLimit}]`;
  }
}

/* ---------------------------------------------------------------------------
   5) BANK CLASS — Static Members + Composition + Aggregation
   ---------------------------------------------------------------------------
   Bank khud koi Account nahi hai (IS-A relation nahi), balki Bank
   "HAS-A" (composition) list of accounts rakhta hai.
   Static members class-level data track karte hain (instance-level nahi).
--------------------------------------------------------------------------- */
class Bank {
  static #totalAccountsCreated = 0; // sab Bank instances me shared counter
  static bankName = 'Roman Bank Ltd.';

  #accounts = new Map(); // private storage — encapsulation

  constructor(branchName) {
    this.branchName = branchName;
    Bank.#totalAccountsCreated = Bank.#totalAccountsCreated; // no-op, just showing static access
  }

  // Factory Method pattern — object creation ka logic ek jagah encapsulate
  openAccount(type, owner, initialBalance, pin, extra) {
    let account;
    switch (type) {
      case 'savings':
        account = new SavingsAccount(owner, initialBalance, pin, extra);
        break;
      case 'current':
        account = new CurrentAccount(owner, initialBalance, pin, extra);
        break;
      default:
        throw new BankError(`Unknown account type: ${type}`);
    }

    this.#accounts.set(owner, account);
    Bank.#totalAccountsCreated++; // static counter update (class-level state)
    return account;
  }

  getAccount(owner) {
    const acc = this.#accounts.get(owner);
    if (!acc) throw new BankError(`Account "${owner}" nahi mila.`);
    return acc;
  }

  // Poore bank ke sab accounts pe interest apply karo — polymorphism ka fayda
  applyInterestToAll() {
    for (const account of this.#accounts.values()) {
      // yahan hume pata nahi ke ye SavingsAccount hai ya CurrentAccount,
      // lekin calculateInterest() call karne se sahi (overridden) version
      // khud-ba-khud chal jata hai — ISI KO POLYMORPHISM kehte hain.
      const interest = account.calculateInterest();
      console.log(`💰 ${account.owner}: interest = ${interest.toFixed(2)}`);
    }
  }

  listAccounts() {
    console.log(`\n--- ${this.branchName} Branch Accounts ---`);
    for (const account of this.#accounts.values()) {
      console.log(account.toString()); // custom toString() call ho raha hai
    }
  }

  // Static method — Bank class pe call hota hai, kisi instance pe nahi
  static getTotalAccountsCreated() {
    return Bank.#totalAccountsCreated;
  }
}

/* ============================================================================
   DEMO / TEST RUN
   ========================================================================== */
try {
  const bank = new Bank('Peshawar Main Branch');

  const ali = bank.openAccount('savings', 'Ali', 5000, '1234', 1000);
  const sara = bank.openAccount('current', 'Sara', 2000, '5678', 3000);

  bank.listAccounts();

  ali.deposit(1500);
  ali.withdraw(500, '1234');

  sara.withdraw(4000, '5678'); // overdraft use hoga

  bank.listAccounts();

  // Polymorphism demo — same method, different behavior per class
  bank.applyInterestToAll();

  // Mixin (Transferable) demo
  ali.transferTo(sara, 1000);

  bank.listAccounts();

  console.log('\n📜 Ali ka statement:', ali.getStatement());
  console.log('\n🏦 Total accounts bank-wide:', Bank.getTotalAccountsCreated());

  // Abstraction demo — ye error throw karega
  // const x = new Account("Test", 100, "0000"); // <-- uncomment karke dekhein

  // Encapsulation demo — ye bhi error dega
  // ali.balance = 999999; // <-- uncomment karke dekhein
} catch (error) {
  // Custom error hierarchy ka fayda: error.name automatically sahi class dikhata hai
  console.error(`❌ [${error.name}] ${error.message}`);
}
