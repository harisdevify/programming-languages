#include <iostream>
using namespace std;

inline int multiplication(int x, int y){
  int mul=x*y;
   return mul;
}

int main(){
  cout<<multiplication(2,5)<<endl;
  cout<<multiplication(10,36)<<endl;
}
