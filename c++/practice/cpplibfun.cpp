#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
  string x;
  cout<<"Insert your msg: "<<endl;
  getline(cin, x); // gets is deprecated, instead use getline: it read until you hit enter
  // puts("Your adress is: "); // puts can use for string, change line auto
  cout<< "\n Your adress is: "<< x<<endl;
}
