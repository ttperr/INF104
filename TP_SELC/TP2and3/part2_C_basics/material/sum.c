#include <stdio.h>
#include <string.h>
#include <math.h>

void display_message(char * message)
{
  printf(message);
}

char isCharInteger(char c);


int main(int argc, char *argv[]) {
  int op = 1;
  if(argc != 3) {
    display_message("Wrong usage, 2 parameters expected: ./sum param1 param2\n");
    return -1;
  } else {
    int i;
    for(i = 1; i < argc; i++) {
      char * chaine = argv[i];
      while(*chaine != '\0') {
        if(*chaine == '-') {
          op = -1;
        } else if(!isCharInteger(*chaine)) {
          display_message("Wrong usage, parameters param1 and param2 should be integers when executing ./sum param1 param2\n");
          return -2;
        }
      chaine++;
      }
    }

  }

  /* arguments have been checked, we can proceed to the sum:
     1 - convert string into an integer value
     2 - sum obtained values
  */

  return 0;
}

char isCharInteger(char c)
{
  switch (c) {
    case '0' :
    case '1' :
    case '2' :
    case '3' :
    case '4' :
    case '5' :
    case '6' :
    case '7' :
    case '8' :
    case '9' :
      return 1;
  }
  return 0;
}

char charToInteger(char c)
{
  switch (c) {
    case '0' :
      return 0;
    case '1' :
      return 1;
    case '2' :
      return 2;
    case '3' :
      return 3;
    case '4' :
      return 4;
    case '5' :
      return 5;
    case '6' :
      return 6;
    case '7' :
      return 7;
    case '8' :
      return 8;
    case '9' :
      return 9;
  }
  return 0;
}

char stringToInteger(char * c)
{ 
  int exp = 0;
  int s = 0;
  while(*c != '\0') {
    s += charToInteger(*c)*pow(10, exp);
    exp++;
  }
  return 0;
}
