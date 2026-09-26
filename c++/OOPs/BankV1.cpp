#include <iostream>

class BankAccount {
private:
  double balance;

public:
  BankAccount(double balance){

    if(balance<= 0){
      std::cout << "0 or less than 0 balance can't add\n";
      this->balance = 0;
    }else
    {
      this->balance = balance;
    }

  }

  void deposit(double amount){
    if(amount <= 0){
      std::cout << "Invalid deposit amount\n";
    }else
    {
      this->balance += amount;
    }
  }

  void withdraw(double amount){
    if(amount > this->balance){
      std::cout<<"Insufficient balance\n";
    }else if (amount <= 0)
    {
      std::cout<<"Invalid withdrawal amount\n";
    }else{
      this->balance -= amount;
    }

  }

  double getBalance(){
   return balance;
  }

};

int main() {
  BankAccount b(0);
  std::cout<<"The Initial Balance: "<< b.getBalance() << '\n';
  b.deposit(500);
  std::cout<<"After Deposit Balance: "<< b.getBalance() << '\n';
  b.withdraw(300);
  std::cout<<"After withdraw Balance: "<< b.getBalance() << '\n';

  return 0;
}
