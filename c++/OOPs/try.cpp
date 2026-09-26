#include <iostream>
using namespace std;

class Student{
public:
  string name;
  int age;
  bool matPass;

  Student(string name, int age, bool matPass){
    this-> name = name;
    this-> age = age;
    this-> matPass= matPass;
  }

  void print(string name){
    cout<<this->name<<" "<< age<<", "<< "City: "<< name << (matPass == true ? ", 10 Passed" : "10 failed")<<endl;
  }

  ~Student(){}
};

void change(Student* s){
  //  (*s).name = "M Haris khan mmd";
   s-> name = "M Haris khan mmd";

}

int main(){
  Student s("M haris", 20, true);
  cout<<"before change: "<< s.name<<endl;
  change(&s);
  cout<<"after change: "<< s.name<<endl;
  return 0;
}
