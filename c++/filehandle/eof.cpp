#include <iostream>
#include <fstream>
using namespace std;

int main() {
  string name;
  int idnum;

  char filename[]= "file.dat";
  ifstream file(filename);
  if(!file){
  cout<<"Opening file not found!";
  exit(1);
  }

  string line;
  getline(file, line);
  while (!file.eof())
  {
    file>> name >> idnum;
    cout << name << "\t" << idnum << endl;
  }
  file.close();
  return 0;
}
