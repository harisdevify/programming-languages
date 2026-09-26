#include <iostream>
using namespace std;

int cal_bil(int, int, int, int); // func prototype
int sum(int, int); // func prototype

int main(){
  int bill;
  int rice = 20;
  int chiken = 35;
  int fruit = 59;

  bill = cal_bil(rice, chiken, fruit, sum(1,2)); // actual parameters
  cout<<"bill is: "<<bill<<endl;
}

int cal_bil(int rice, int chiken, int fruit, int sum){ // formal parameters
  int totle;
  totle = rice + chiken + fruit + sum;
  return totle;
}


int sum(int x, int y){
  int sum;
  sum = x + y;
  return sum;
}



// int main(){
//   cout<< sum(2, 3);
// }
