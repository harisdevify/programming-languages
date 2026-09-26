#include <iostream>
using namespace std;


int add(int, int);

void inc(){
  static int x=0;
   x++;
   cout<<x<<endl;
}
int main(){
  inc();
  inc();
}

int add(int num1, int num2){
   return num1 + num2;
}
