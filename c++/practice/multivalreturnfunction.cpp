#include <iostream>
using namespace std;

int refrence(int num, int &square, int &cube){
  square = num * num;
  cube = num * num * num;
  return num;
}


int main(){

  int number = 5;
  int sq, cu;
  int orignal= refrence(number, sq, cu); // number: pass arg by val and sq, cu by refrence
  cout<<orignal<<endl;
  cout<<"square: "<<sq<<endl;
  cout<<"cube: "<<cu<<endl;
  return 0;
}



