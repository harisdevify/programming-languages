#include <iostream>
using namespace std;

void funct(int x){
  cout<<"func x is: "<<x<<endl;
  x = 6;
  cout<<"assigned to x is: "<<x<<endl;
}

int Addone(int &x){
  return (x++);
}

int main(){
  int x =5;
  int z=55;
  cout<<"refrence z before: "<< z<<endl;
  cout<<"before: "<< x<<endl;
  funct(x); // passing arg by value
  funct(8); // passing arg by constant
  Addone(z); // passing arg by refrence
  cout<<"after: "<< x<<endl;
  cout<<"refrence z after: "<< z<<endl;
  return 0;
}



