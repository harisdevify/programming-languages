#include <iostream>
using namespace std;
int main(){
  int A[5];
  A[0]=1;
  A[1]=2;
  cout<<"enter: ";
  cin>> A[2];
  cout<<"enter: ";
  cin>> A[3];
  for(int i=0; i<5; i++){
     cout<<"arr["<<i<<"]"<<"="<< A[i]<<endl;
   }
  return 0;
}
