#include <stdio.h>
#include <string.h>

void display_message(char * message)
{
  printf(message);
}

// declare function before using it
char isCharInteger(char c);

int main(int argc, char * argv[]) {
  // first, check that the number of parameters is correct
  if(argc != 3) {
    display_message("Wrong usage, 2 parameters expected: ./sum param1 param2\n");
  } else {
    int i;
    for(i = 1; i < argc; i++) {
      char * chaine = argv[i];
      while(*chaine != '\0') {
        if(!isCharInteger(*chaine)) {
          display_message("Wrong usage, parameters param1 and param2 should be integers when executing ./sum param1 param2\n");
        } else {
          display_message("a basic message\n");
        }
      chaine++;
      }
    }
  }

  // now, check that parameters represent integer values
  // declare, implement, and use function isCharInteger

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
