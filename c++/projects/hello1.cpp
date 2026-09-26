#include <iostream>
using namespace std;
int main()
{
  // char ch;
  // cout<<"Enter an alphabate here: ";
  // cin>>ch;

  // if(ch >= 'a' && ch <= 'z'){
  //   cout<<"Lowercase\n";
  // } else{
  //   cout<<"UpperCase\n";
  // }

  // int n = 50;
  // int count = 1;

  // while (count <= n)
  // {
  //   cout<< count<< "";
  //   count++;
  // }

  // int n;
  // cout<< "enter number: ";
  // cin>> n;
  // int sum = 0;
  // for( int count = 1; count <= n; count++){
  //   sum += count;
  // }
  // cout<<"totle sum from 1 to "<<n<<"= " << sum;

  // int n;
  // cout<< "enter number: ";
  // cin>> n;
  // int sum = 0;
  // for(int i = 1; i <= n; i++){
  //   if(i % 2 != 0){
  //       sum +=i;
  //   }
  // }
  // cout<<"totle Odd sum from 1 to "<<n<<"= " << sum;

  // int n = 5;
  // for(int i =1; i <= n; i++){
  //   cout<< "*";
  //   int m = 5;
  //   for(int i=1; i<= m; i++){
  //     cout<< "*";
  //   }
  //   cout<<endl;
  // }

  // int n = 65;
  // for(int i =1; i <= n; i++){

  //   char ch = 'A';
  //   for(int j=0; j<= n; j++){
  //     cout << ch;
  //     ch++;
  //   }
  //   cout<<endl;
  // }

  // int n = 10;
  // for (int i = 0; i < n; i++){
  //   for (int j = 1; j <= i + 1; j++){
  //     cout <<j;
  //   }
  //   cout<< endl;
  // }


  int n = 10;
  for (int i = 0; i < n; i++){
    for (int j =i+1 ; j>0; j--){
      cout <<j;
    }
    cout<< endl;
  }

  return 0;
}
