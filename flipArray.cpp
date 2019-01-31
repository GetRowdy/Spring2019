#include <iostream>

using namespace std;

//for question 1
void flipArray(char str[], int strLength)
{
     char newArray[strLength] = "";

    for(int x=0; x<strLength; x++)
    {
      for(int i=strLength-1; i>=0; i--)
      {
        newArray[x] = str[i];
        x++;
      }
    }

    cout<<"\nfrom function call: "<< newArray <<endl;
    

}

int main()
{

  char myStr[]="rowdy";
  int size = sizeof(myStr)-1;
  int myLen = size;

  //cout << "Please enter a word: " << endl;
  //cin >> myStr;
  
  cout << myStr;

  cout << endl << "String Size: " << size;

  flipArray(myStr, myLen);

}
