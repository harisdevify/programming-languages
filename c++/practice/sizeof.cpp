#include <iostream>
using namespace std;
int main(){
  int A[10]={1,2,3,4,5,6,7,8,9,10};
  int totleElm = sizeof(A)/sizeof(A[0]);
  cout<<"size of Arr is: "<< totleElm<<endl;
  return 0;
}
