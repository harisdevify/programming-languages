#include <iostream>
using namespace std;
class Student{
public:
  string name;
  int age;
  bool matPass;

  //constructor
  Student(string name, int age, bool matPass){
    this->name = name;
    this->age = age;
    this->matPass= matPass;
  }

  //distructor
  ~Student(){}
};


int main(){
  int x=4;
  int*ptr = &x;
  cout<<"x is the value: "<<x<<endl;
  cout<<"&x is the adress: "<<&x<<endl;
  cout<<"Hold adress: "<<ptr<<endl;
  cout<<"print value at the adress: "<<*ptr<<endl;
  *ptr = 100; //dereference oprater
  cout<<"changed value of x: "<<x<<endl;

  return 0;
}
