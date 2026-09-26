#include <iostream>
#include <cstring>
using namespace std;
int main(){
   // 1
  // string str("Hello, ");
  // string str1("I'm Haris khan mmsd");


  //  2
  // char s1[50], s2[50];
  // cout<<"Enter: ";
  // cin.getline(s1, 50);
  // cout<<"Enter again: ";
  // cin.getline(s2, 50);
  // strcat(s1,s2);
  // cout<<s1<<endl;

  // 3 (CPP string )
  // string str = "Hello, I'm Haris to talk with you!";
  // cout<< "str: "<<str<<endl;
  // char x[50];
  // str.copy(x, 7, 0);
  // cout<<"copied: "<<x;

  // 4
  // string str = "Hello, I'm Haris to talk with you!";
  // cout<< "str: "<<str<<endl;
  // char x[50];
  // str.copy(x, 7, 0);
  // cout<<"copied: "<<x;

  // coping string
  // string str = "Programming";
  // char str1[13];
  // str.copy(str1,11, 0);
  // cout<<"copied: "<<str1<<endl;

  // find some in strinf
  // string str = "C++ Progagramming is Better than Python!";
  // int loc1, loc2;
  // loc1 = str.find("C++");
  // cout<<"cpp found on position: "<<loc1+1<<endl;
  // loc2 = str.find("g");
  // cout<<"g found on position: "<<loc2<<endl;

  // sting length
  // string str = "C++ Progagramming is Better than Python! hhh";
  // cout<<str.length();

  // string str;
  // cout<<"Enter some to find Length: ";
  // getline(cin, str);
  // int len = str.length();
  // cout<<"text you given length is: "<< len<<endl;


  // swap(interchange)
  string str1 = "hello";
  string str2 = "world";
  str1.swap(str2);
  cout<<str1;

  return 0;
}
