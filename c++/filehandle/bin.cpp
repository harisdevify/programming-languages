#include <iostream>
#include <fstream>
using namespace std;

int main() {
  char filename[]= "data.bin";
  fstream file(filename, ios::binary | ios::out);
  if(!file){
    cout<<"File path name not found!";
    exit(1);
  }
  int num = 100;
  file.write((char*)&num, sizeof(num));
  cout<< "the number: "<<num<<endl;
  return 0;
}
