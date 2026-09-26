#include <iostream>

class BankAccount {
private:
  double balance;
  bool isBlocked;
  const double fee = 20.0;
  const double maxWithdraw = 50000;

public:
  BankAccount(double balance){
    isBlocked = false;
    if(balance<= 0){
      std::cout << "0 or less than 0 balance can't add\n";
      this->balance = 0;
      return;
    }

    this->balance = balance;
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
      return;
    }

    if(amount <= 0){
      std::cout << "Invalid deposit amount\n";
      return;
    }

    balance += amount;
  }

  void withdraw(double amount){

    if(isBlocked){
       std::cout << "Account is blocked\n";
       return;
    }

    if (amount <= 0){
      std::cout<<"Invalid withdrawal amount\n";
      return;
    }

    double totleDeduction = amount + fee;
    if( totleDeduction > balance){
      std::cout<<"Insufficient balance\n";
      return;
    }

    if(amount > maxWithdraw){
      std::cout << "Transaction Failed. Maximum withdrawal limit is 50,000 PKR.\n";
      return;
    }

    double remainingBalance = balance - totleDeduction;
    if(remainingBalance < 500){
      std::cout<<"Transaction Failed. A minimum balance of 500 PKR must be maintained in your account. \n";
      return;
    }

    balance -=  totleDeduction;
    std::cout<<"withdrawal Balance: "<< amount << " with fee of: "<<fee << '\n';
  }

  double getBalance(){
   return balance;
  }
};

int main() {
  BankAccount b(1000);


  // const clc = new calc(12.3, 16.4)
  b.deposit(500);
  std::cout << "Balance: " << b.getBalance() << '\n';

  b.withdraw(990);
  std::cout << "Balance: " << b.getBalance() << '\n';
  return 0;
}
