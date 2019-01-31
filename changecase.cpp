#include <iostream>
using namespace std;

void changeCase(char myStr[], int size)
{
  for(int i = 0; i < size; i++)
    if(myStr[i] < 97)
      myStr[i] = myStr[i]+32;
    else
      myStr[i] = myStr[i]-32;

  cout << myStr;
}

int main() {
  char myString[] = "GetRowdy";
  int size = sizeof(myString)-1;

  changeCase(myString,size);

  return 0;
}
