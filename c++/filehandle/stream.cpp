#include <iostream>
#include <fstream>
using namespace std;

int main() {
  char ch;
  ifstream file("prac.txt");
  while(!file.eof()){
    file.get(ch);
    cout<<ch;
  }

  file.close();
  return 0;
}
