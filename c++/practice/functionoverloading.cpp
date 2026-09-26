#include <iostream>
using namespace std;

int overloading(int a){
    return a;
}
void overloading(){
   cout<<"Wellcome"<<endl;
}
float overloading(float a, float b){
  return (a * b);
}

// char foo(){
//   return 'a';
// }
// int foo(){
//   return 10;
// }

int main(){
  int res = overloading(100);
  cout<<res<<endl;
  overloading();

  float fl = overloading(1.1, 2.2);
  cout<<fl;

  // char x = foo();
  //cout<< x; // error: functions that differ only in their return type cannot be overloaded
  return 0;
}
