#include <iostream>
using namespace std;

int main(){
  char ch;
  cout<<"Wrtie ch: ";
  cin>>ch;


char lowerCh = tolower(ch);
  if(lowerCh=='a' || lowerCh=='e' || lowerCh=='i' || lowerCh=='o' || lowerCh=='u') cout<< "Vowol"<<endl; else cout<<"Consonant"<<endl;
  return 0;
}


