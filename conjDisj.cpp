/*
conjDisj.cpp
Josh Latham
ID: 23740149
Spring 2019, CSC231
1720
Instructor: Prof. Eckman

Description:
------------
Given the truth values of the propositions p and q, write two functions that find the 
truth value of both the disjunction and conjunction of p and q.  The functions should 
have the following signatures:

    boolean find_conjunction(boolean p, boolean q)
    boolean find disjunction(boolean p, boolean q)

Additionally, write a main() driver functions that will display a valid truth table of
p and q for both and and or.
*/

#include <iostream>

using namespace std;

bool findConj(bool p, bool q) { //checks for Conjunction of inputted values, returns true or false
  if(p == true && q == true)
    return true;
  else
    return false;
}
bool findDisj(bool p, bool q) { //checks for Disjunction of inputted values, returns true or false
  if(p == true || q == true)
    return true;
  else
    return false;
}

int main() {
  cout << "p      q       &&      ||" << endl;
  cout << "-------------------------" << endl;
  cout << "1      1        " << findConj(1,1) << "       " << findDisj(1,1) << endl;
  cout << "1      0        " << findConj(1,0) << "       " << findDisj(1,0) << endl;
  cout << "0      1        " << findConj(0,1) << "       " << findDisj(0,1) << endl;
  cout << "0      0        " << findConj(0,0) << "       " << findDisj(0,0) << endl;
}