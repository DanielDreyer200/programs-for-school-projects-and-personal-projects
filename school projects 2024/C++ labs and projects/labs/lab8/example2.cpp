#include <iostream>
using namespace std;

int main()
{
  char *temp = "Reinhardt"; //To fix, change to char temp[] = "Reinhardt";
  int i = 0;
  temp[4]='f';
  for (i =0 ; i < 9; i++ )
    cout << temp[i] << endl;
  return 0; 
}
