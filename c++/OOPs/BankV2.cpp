#include <iostream>

class BankAccount {
private:
  double balance;
  bool isBlocked;

public:
  BankAccount(double balance){
    isBlocked = false;
    if(balance<= 0){
      std::cout << "0 or less than 0 balance can't add\n";
      this->balance = 0;
    }else
    {
      this->balance = balance;
    }
  }

  void blockAccount() {
    isBlocked = true;
  }

  void unblockAccount(){
    isBlocked = false;
  }

  void deposit(double amount){
    if(isBlocked){
      std::cout << "Account is blocked\n";
    }
    else
      {
        if(amount <= 0){
        std::cout << "Invalid deposit amount\n";
      }
      else
      {
        this->balance += amount;
      }
    }

  }

  void withdraw(double amount){
    const double fee = 20.0;
    const double maxWithdraw = 50000;
    if(isBlocked){
       std::cout << "Account is blocked\n";
    }else{
      if (amount <= 0)
    {
      std::cout<<"Invalid withdrawal amount\n";
    }
    else  if(amount > this->balance){
      std::cout<<"Insufficient balance\n";
    }
    else if(amount < this->balance){
      double totlededuction = amount + fee;
      double calc = this->balance - totlededuction;
      if(calc < 500){
        std::cout<<"Transaction Failed. A minimum balance of 500 PKR must be maintained in your account. \n";
      }
      else{
        if(amount > maxWithdraw){
          std::cout << "Transaction Failed. Maximum withdrawal limit is 50,000 PKR.\n";
        }else
        {
          this->balance -= totlededuction;
          std::cout<<"withdrawal Balance: "<< amount << " with fee of: "<<fee << '\n';
        }
      }
    }
    else
    {
      std::cout << "Transaction Failed. A minimum balance of 500 PKR must be maintained.\n";
    }
    }
  }

  double getBalance(){
   return balance;
  }

};

int main() {
  BankAccount b(10000);

  b.blockAccount();

  b.deposit(500);
  std::cout << "Balance: " << b.getBalance() << '\n';

  b.withdraw(300);
  std::cout << "Balance: " << b.getBalance() << '\n';

  b.unblockAccount();

  b.deposit(500);
  std::cout << "Balance: " << b.getBalance() << '\n';

  b.withdraw(300);
  std::cout << "Balance: " << b.getBalance() << '\n';

  return 0;
}
