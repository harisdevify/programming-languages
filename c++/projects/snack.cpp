#include <iostream>
#include <unistd.h>
#include <vector>
#include <string>

using namespace std;

const int WIDTH = 30;
const int HEIGHT = 20;

struct Point{
   int x, y;
};

enum Direction {UP, DOWN, LEFT, RIGHT};


void darwGrid(Point snakeHead){
   vector<string> grid(HEIGHT, string(WIDTH, ' '));
   for(int x=0; x < WIDTH; x++){
      grid[0][x] = '#';
      grid[HEIGHT - 1][x] = '#';
   }
   for(int y=0; y < HEIGHT; y++){
      grid[y][0] = '#';
      grid[y][WIDTH - 1] = '#';
   }

   grid[snakeHead.y][snakeHead.x]= '0';
   cout << "\033[H\033[J";
   for (auto &row : grid)
    cout << row << "\n";
}


int main(){
   cout<<"game is starting..."<<endl;

   Point snakeHead = {WIDTH / 2, HEIGHT / 2};

   Direction dir = UP;
   bool gameOver = false;


   while(!gameOver){

      switch(dir){
         case UP: snakeHead.y--; break;
         case DOWN: snakeHead.y++; break;
         case LEFT: snakeHead.x--; break;
         case RIGHT: snakeHead.x++; break;

         default:
           break;
      }

      if(snakeHead.x <= 0 || snakeHead.x >= WIDTH - 1 ||
         snakeHead.y <= 0 || snakeHead.y >= HEIGHT - 1){
         cout<<"Game hit!";
         gameOver = true;
         break;
      }

      cout << "snake head at: (" << snakeHead.x << ", " << snakeHead.y << ")"<< endl;

      darwGrid(snakeHead);
      usleep(500000);
   }
   cout<<" Start again!"<<endl;

  return 0;
}
