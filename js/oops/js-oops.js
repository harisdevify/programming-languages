class bank {
  #balance;
  constructor(balance) {
    this.#balance = balance;
  }

  deposit(amount) {
    return (this.#balance += amount);
  }

  getbalance() {
    return console.log(this.#balance);
  }
}

const obj1 = new bank(1000);
obj1.getbalance();
obj1.deposit(300);
obj1.getbalance();
