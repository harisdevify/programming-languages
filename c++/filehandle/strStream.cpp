#include <iostream>
#include <fstream>
using namespace std;

int main() {

  char filename[]="prac.txt";
  ifstream file(filename);
  if(!file){
    cout<<"Fail to open file!";
    exit(1);
  }
  string name;
  getline(file, name);
  cout<<name<<endl;
  return 0;
}
