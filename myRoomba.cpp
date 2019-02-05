/*
   roomba.cpp
   Josh Latham
   ID#: 23740149
   Spring 2019, CSC211
   1100
   Instructor: Dr. Azhar 
   
   this program demonstrates a simple robot (called "roomba")
   wandering around in a simulated room. the robot can move in any of
   four directions (forward, backward, left or right) within a "grid"
   so that any move changes the robot's location by one grid square.
   for example, if the robot starts at location (0,0) and moves forward,
   it will end up at location (0,1).

*/


// section 1: include C++ library definitions
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;


// section 2: declare variables
int x;
int y;
char uChoice;

// section 2.5: declare function prototypes

void autoClean();
void goHome();

// section 3: declare methods
int display() { //displays Roomba location and builds display
  cout << "the roomba is at location (";
  cout << x;
  cout << ",";
  cout << y;
  cout << ")\n";
  for(int i = 11; i>=0; i--)
  { 
      cout << (i-1);
      if(i < 10 && i >=0)
        cout << " ";
      if(i == 10)
        cout << " ";
    
    for(int j = 0; j<=10; j++)
    {
      if(i == 0)
      {
        if(j >= 0)
        {
          cout << "" << j << "  ";
        }

      }
      else if(j == x && i-1 == y)
        {
          cout << "[X]";
        }
      else
        cout << "[ ]";
      if(j == 10)
        cout << endl;
    }
  }
  return 0;
} // end of display()


int moveForward() {
  cout << "moving forward...\n";
  if(y >= 10)
  {
    cout << "ERROR: Hit north wall. Cannot move." << endl;
    return 1;
  }
  y = y + 1;
  return 0;
} // end of moveForward()


int moveBackward() {
  cout << "moving backward...\n";
  if(y <= 0)
  {
    cout << "ERROR: Hit south wall. Cannot move." << endl;
    return 1;
  }
  y = y - 1;
  return 0;
} // end of moveBackward()


int moveLeft() {
  cout << "moving left...\n";
  if(x <= 0)
  {
    cout << "ERROR: Hit west wall. Cannot move." << endl;
    return 1;
  }
  x = x - 1;
  return 0;
} // end of moveLeft()


int moveRight() {
  cout << "moving right...\n";
  if(x >= 10)
  {
    cout << "ERROR: Hit east wall. Cannot move." << endl;
    return 1;
  }
  x = x + 1;
  return 0;
} // end of moveRight()

int wallForward() { //move to north wall

  for(int i = y; i<10; i++)
        {
          moveForward();
          display();
        }

  return 0;
}

int wallBackward() { //move to south wall

    for(int i=y; i>0; i--)
        {
          moveBackward();
          display();
        }
  return 0;
}

int wallLeft() { //move to west wall

    for(int i=x; i>0; i--)
        {
          moveLeft();
          display();
        }
  return 0;
}

int wallRight() { //move to east wall

    for(int i = x; i<10; i++)
        {
          moveRight();
          display();
        }
  return 0;
}

int uMove(char uDir) //takes user input to determine direction
{
    if(uDir == 'n')
      {
        moveForward();
        display();
      }
    else if(uDir == 'N') //wallForward
      {
        wallForward();
      }
    else if(uDir =='w')
      {
        moveLeft();
        display();
      }
    else if(uDir == 'W') //wallLeft
      {
        wallLeft();
      }
    else if(uDir == 'e')
      {
        moveRight();
        display();
      }
    else if(uDir == 'E') //wallRight
      {
        wallRight();
      }
    else if(uDir == 's')
      {
        moveBackward();
        display();
      }
    else if(uDir == 'S') //wallBackward
      {
        wallBackward();
      }
    else if(uDir =='A')
    {
      autoClean();
    }
}// end of uMove()

void autoClean() //returns Roomba home, begins efficient cleaning pattern.
{
  cout << "Roomba is auto cleaning...\nSetting efficient path." << endl;
  goHome();

  cout << "Starting vacuum route!" << endl;
  
  for(int i = 0; i <= 10; i++)
  {
    for(int j = 0; j<1; j++)
      {
      if(y==0)
        {
          wallForward();
        }
      else if(y==10)
        {
          wallBackward();
        }
      }
    moveRight();
  }

  cout << "Auto-clean complete! Returning home..." << endl;
  goHome();

}

void goHome()
{
  wallBackward();
  wallLeft();
}

int drawMenu()
{
  cout << "\nPlease enter a command or (Q) to exit:" << endl;
  cout << "||=====================================================||" << endl
       << "|| n or (N) - Move Roomba 1 Unit North (to North Wall) ||" << endl
       << "|| s or (S) - Move Roomba 1 Unit South (to South Wall) ||" << endl
       << "|| w or (W) - Move Roomba 1 Unit West (to West Wall)   ||" << endl
       << "|| e or (E) - Move Roomba 1 Unit East (to East Wall)   ||" << endl
       << "||   A      - NEW AUTOCLEANING FEATURE! Try it!        ||" << endl
       << "||   H      - Send Roomba home to recharge.            ||" << endl
       << "||=====================================================||" << endl;
}

// section 4: define main method
int main() {
  x = 5;
  y = 5;

  while(uChoice != 'Q')
  {
    drawMenu();
    cin >> uChoice;
    uMove(uChoice);

  }

} // end of main()
