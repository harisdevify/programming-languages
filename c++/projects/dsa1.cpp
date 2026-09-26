#include <iostream>
using namespace std;

int main()
{
  int n;
  cin>> n;
  int count = 2;

  for (int i = 0; i < count; i++)
  {
    if(count < (n-1)){
      if(n%2==0){
       cout <<"this is not prime number" << endl;
       count++;
      }
    }else{
       cout <<"this is prime number"<< endl;
    }
  }

}
