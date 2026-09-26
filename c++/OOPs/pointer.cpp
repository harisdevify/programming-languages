#include <iostream>
using namespace std;

int main(){

  // dynamic allocation
  // int* p = new int(321);

  int x=4;
  int*ptr = &x;
  cout<<"x is the value: "<<x<<endl;
  cout<<"&x is the adress: "<<&x<<endl;
  cout<<"Hold adress: "<<ptr<<endl;
  cout<<"print value at the adress: "<<*ptr<<endl;
  return 0;
}
