#include <iostream>
using namespace std;

class Time{
  int hour,min, sec;
  public:
  Time(int h, int m, int s){
    hour=h;
    min=m;
    sec=s;
  }

  void display(){
    cout<<"Time: "<<hour<<":"<<min<<":"<<sec<<endl;
  }
};

int main(){
  Time t(1,52,23);
  t.display();
  return 0;
}


