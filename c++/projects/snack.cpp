#include <iostream>
#include <unistd.h>
using namespace std;


const int WIDTH = 30;
const int HEIGHT = 20;

struct Point{
   int x, y;
};

int main(){
  cout<<"Snack game is starting..."<<endl;


  Point snakeHead = {WIDTH / 2, HEIGHT / 2};
  cout << "Snake head at: (" << snakeHead.x << ", " << snakeHead.y << ")"<< endl;

  bool gameOver = false;
  int frame = 0;

  while(!gameOver){
     cout<<"Frame: "<< frame<<endl;
     frame++;
     usleep(500000);
     if(frame >= 5){
        gameOver = true;
     }
     cout<<"Game Over!"<<endl;
  }
  return 0;
}
