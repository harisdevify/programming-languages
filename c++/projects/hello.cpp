#include <iostream>

int main() {
  int n; //3
  std::cin>> n;
  int count=1;// 2
  int sum=0;//1,3
  for (int i = 0; i < count; i++)
  {
    if(count < n){ // 1<3 -> true 2<3->true
      sum +=count; // 0+1,1+2
      count++; //1+1=2+1=3
    }
  }

  std::cout<<"this is sum from 1 to "<< n <<" " << ": " <<sum << std::endl;
}
