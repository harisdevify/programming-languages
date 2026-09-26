#include <iostream>
using namespace std;
int main(){
  int n = 50;
  int *Pn = &n;
  int value = *Pn;
  cout<<&n<<endl;
  cout<<Pn<<endl;
  cout<<value<<endl;
  return 0;
}
