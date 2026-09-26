#include <iostream>
using namespace std;


void demo(){
  int automatic_var = 0;
  static int static_var = 0;

  cout<< "auto: "<< automatic_var<<endl;
  cout<< "static: "<< static_var<<endl;
  ++automatic_var;
  ++static_var;
}

int main(){
  int x;
  for(int x=0;x<3;x++){
     demo();
  }

}


