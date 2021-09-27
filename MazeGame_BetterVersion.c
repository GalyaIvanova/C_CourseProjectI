#include <stdio.h>

#include <unistd.h>

#include <conio.h>

#include <stdlib.h>

#include <time.h>

void mazeGen(char maze[21][21], char traversed[21][21]);
void recur(char maze[21][21], char traversed[21][21], int xpos, int ypos);
void PrintMaze(int xpos, int ypos);
void Generate();
void clrscr();
//Stores the maze

char maze[21][21] = {
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
                    {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#'},
                    {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'}};
                     //Keeps track of areas that have already been traversed and/or never will be traversed
                   char traversed[21][21] =
                   {{'#','#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#'},
                    {'#',' ' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'#'},
                    {'#','t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#'},
                    {'#','t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'#'},
                    {'#','t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#'},
                    {'#','t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'#'},
                    {'#','t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#'},
                    {'#','t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'#'},
                    {'#','t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#'},
                    {'#','t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'#'},
                    {'#','t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#'},
                    {'#','t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'#'},
                    {'#','t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#'},
                    {'#','t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'#'},
                    {'#','t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#'},
                    {'#','t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'#'},
                    {'#','t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#'},
                    {'#','t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'#'},
                    {'#','t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#' ,'t' ,'#'},
                    {'#','t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'t' ,'#'},
                    {'#','#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#' ,'#'}};

int xpos, ypos;


int main(int argc, char** argv){

printf("1.Enter the maze from a random location generated by the computer.\n\n2.You enter the maze from any place generated by the computer as you are also\n shown the 8 nearby cells (top, bottom, left, right, anddiagonal), the walls of the labyrinth are always marked S.\n\n3.The aim of the game is to guide the direction of movement through the maze \nthroughthe ‘A’ ‘S’ ‘D’ ‘W’ buttons as respectively each button moves to a specificdirection - left right top down.\n");
printf("\n\n\t\t!!Press ENTER!!\n\n");
  Generate();
  while (1) {
    int ch1, ch2;

    ch1 = getch();
    ch2 = 0;
    if (ch1 == 0xE0) { // a scroll key was pressed
      ch2 = getch();
      // determine what it was
      switch (ch2) {

      case 72: //UP WAS PRESSED

        if (maze[xpos - 1][ypos] != '#' && xpos > 0) xpos--;

        break;
      case 80: //DOWN WAS PRESSED
        if (maze[xpos + 1][ypos] != '#' && xpos < 20) xpos++;

        break;
      case 75: //LEFT WAS PRESSED
        if (maze[xpos][ypos - 1] != '#' && ypos > 0) ypos--;
        break;
      case 77: //RIGHT WAS PRESSED
        if (maze[xpos][ypos + 1] != '#' && ypos < 20) ypos++;
        break;

      default:
        printf("SOME OTHER SCROLL KEY PRESSED: %d %d\n", ch1, ch2);
        break;
      };
    }
    if (ypos == 19 && xpos == 19) {
      clrscr();
      printf("\n\n\t\t!!WIN!!\n\n");
      return 0;
    }

    PrintMaze(xpos, ypos);
    //kogato igrata beshe hubava -galya

  }
getch();
  return 0;
}

//Prim's Algorithm

void Generate() {
  mazeGen(maze, traversed);

}

void mazeGen(char maze[21][21], char traversed[21][21]) {

  srand(time(NULL));
  xpos = 1+rand() % 20;
  ypos = 1+rand() % 20;

  //Sets the first cell to the marker indicating a starting point.
  maze[xpos][ypos] = 'O';
  //Calls the recursion function to generate maze.
  ///recur(maze, traversed, xpos, ypos);
  recur(maze, traversed, 1, 1);
  //After the recursion function is finished, marks the destination

  //Prints the finished maze
  for (int n = 0; n < 21; n++) {
    for (int k = 0; k < 21; k++) {
      if (maze[n][k] == '#') printf("S ");
      else if (xpos == n && ypos == k) printf("O ");
      else if (n == 19 && k == 19) printf("X ");
      else printf("  ", maze[n][k]);
    }
    printf("%c", '\n');
  }
}

void recur(char maze[21][21], char traversed[21][21], int xpos, int ypos) {



  //This loop runs while there are any empty spaces surrounding the coordinates in said location
  while (traversed[xpos - 1][ypos - 1] == 't' || traversed[xpos][ypos - 1] == 't' ||
    traversed[xpos + 1][ypos - 1] == 't' || traversed[xpos - 1][ypos] == 't' || traversed[xpos][ypos] == 't' ||
    traversed[xpos + 1][ypos] == 't' || traversed[xpos - 1][ypos + 1] == 't' || traversed[xpos][ypos + 1] == 't' || traversed[xpos + 1][ypos + 1] == 't') {

    int randomnumber = rand() % 4;
    //Generates a random number between 0 and 3 inclusive.


    //Determines a random direction in which to draw the path(either up, down, left, or right)



    //If the random number is zero, try to draw a path left
    if (randomnumber == 0) {
      if ((xpos > 1) && (traversed[xpos - 2][ypos] == 't')) {
        //Take the x position to the wall
        xpos--;
        //Tear down said wall and mark as visited
        maze[xpos][ypos] = ' ';
        //Calls the recursion function for the next cell
        traversed[xpos][ypos] = ' ';
        //Set coordinates to interior of next cell
        xpos--;
        //Mark cell as visited and as path as the wall is certain to be empty
        traversed[xpos][ypos] = ' ';
        //Calls this function(recursion) for the next cell

        recur(maze, traversed, xpos, ypos);
        //Resets any changes made to the ypos value in the previous statements within this if statement so the loop can continue to check the same cell until all the surrounding areas are full.
        xpos += 2;
      }
      //If drawing the path would create a loop(according to Prim's algorithm), leave the wall and mark the area as traversed.
      else if (traversed[xpos - 2][ypos] != 't') {
        traversed[xpos - 1][ypos] = '#';
      }
    }
    //If the random number is one, try to draw the path right
    else if (randomnumber == 1) {
      if ((xpos < 19) && (traversed[xpos + 2][ypos] == 't')) {

        //Take the x position to the wall
        xpos++;
        //Tear down said wall and mark as visited
        maze[xpos][ypos] = ' ';
        traversed[xpos][ypos] = ' ';
        //Set coordinates to interior of next cell
        xpos++;
        //Mark cell as visited and as path as the wall is certain to be empty
        traversed[xpos][ypos] = ' ';
        //Calls this function(recursion) for the next cell
        recur(maze, traversed, xpos, ypos);
        //Resets any changes made to the ypos value in the previous statements within this if statement so the loop can continue to check the same cell until all the surrounding areas are full.
        xpos -= 2;
      }
      //If drawing the path would create a loop(according to Prim's algorithm), leave the wall and mark the area as traversed.
      else if (traversed[xpos + 2][ypos] != 't') {
        traversed[xpos + 1][ypos] = '#';
      }
    }
    //If the random number is two, try to draw the path up
    else if (randomnumber == 2) {
      if ((ypos > 1) && (traversed[xpos][ypos - 2] == 't')) {
        //Take the y position to the wall
        ypos--;
        //Tear down said wall and mark as visited
        maze[xpos][ypos] = ' ';
        traversed[xpos][ypos] = ' ';
        //Set coordinates to interior of next cell
        ypos--;
        //Mark cell as visited and as path as the wall is certain to be empty
        traversed[xpos][ypos] = ' ';
        //Calls this function(recursion) for the next cell
        recur(maze, traversed, xpos, ypos);
        //Resets any changes made to the ypos value in the previous statements within this if statement so the loop can continue to check the same cell until all the surrounding areas are full.
        ypos += 2;
      }
      //If drawing the path would create a loop(according to Prim's algorithm), leave the wall and mark the area as traversed.
      else if (traversed[xpos][ypos - 2] != 't') {
        traversed[xpos][ypos - 1] = '#';
      }
    }


    else if (randomnumber == 4) {
      if ((xpos < 19) && (traversed[xpos + 2][ypos] == 't')) {

        //Take the x position to the wall
        xpos++;
        //Tear down said wall and mark as visited
        maze[xpos][ypos] = ' ';
        traversed[xpos][ypos] = ' ';
        //Set coordinates to interior of next cell
        xpos++;
        //Mark cell as visited and as path as the wall is certain to be empty
        traversed[xpos][ypos] = ' ';
        //Calls this function(recursion) for the next cell
        recur(maze, traversed, xpos, ypos);
        //Resets any changes made to the ypos value in the previous statements within this if statement so the loop can continue to check the same cell until all the surrounding areas are full.
        xpos -= 2;
      }
      //If drawing the path would create a loop(according to Prim's algorithm), leave the wall and mark the area as traversed.
      else if (traversed[xpos + 2][ypos] != 't') {
        traversed[xpos + 1][ypos] = '#';
      }
    }


    //If the random number is three, try to draw the path down
    else {
      if ((ypos < 19) && (traversed[xpos][ypos + 2] == 't')) {
        //Take the y position to the wall
        ypos++;
        //Tear down said wall and mark as visited
        maze[xpos][ypos] = ' ';
        traversed[xpos][ypos] = ' ';
        //Set coordinates to interior of next cell
        ypos++;
        //Mark cell as visited and as path as the wall is certain to be empty
        traversed[xpos][ypos] = ' ';
        //Calls this function(recursion) for the next cell
        recur(maze, traversed, xpos, ypos);
        //Resets any changes made to the ypos value in the previous statements within this if statement so the loop can continue to check the same cell until all the surrounding areas are full.
        ypos -= 2;
      }
      //If drawing the path would create a loop(according to Prim's algorithm), leave the wall and mark the area as traversed.
      else if (traversed[xpos][ypos + 2] != 't') {

        traversed[xpos][ypos + 1] = '#';
      }
    }
  }
}

void clrscr() {
  system("@cls||clear");
}
void PrintMaze(int xpos, int ypos) {
  clrscr();
  for (int n = 0; n < 21; n++) {
    for (int k = 0; k < 21; k++) {
      if (maze[n][k] == '#') printf("S ");
      else if (xpos == n && ypos == k) printf("O ");
      else if (n == 19 && k == 19) printf("X ");
      else printf("  ", maze[n][k]);
    }
    printf("%c", '\n');
  }

}


