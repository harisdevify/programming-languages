#include <iostream>
using namespace std;
int main(){
  int A[10]={1,2,3,4,5,6,7,8,9,10};
  for(int i=0; i<10; i++){
    if(A[i]%2!=0){
      cout<< A[i]<< endl;
    }
   }
  return 0;
}
