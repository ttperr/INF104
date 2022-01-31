#include <stdio.h>
#include <string.h> 

void display_message(char * message)
{
  printf(message);
}

char isCharInteger(char c);
char stringToInteger(char * c);


int main(int argc, char *argv[]) {
  if(argc != 3) {
    display_message("Wrong usage, 2 parameters expected: ./sum param1 param2\n");
    return -1;
  } else {
    char * chaine = argv[1]; 
    while(*chaine != '\0') {
      if(!isCharInteger(*chaine)) {
        display_message("Wrong usage, parameter param1 should be integers when executing ./sum param1 param2\n");
        return -2;
      }
    chaine++;
    }

    char * chaine2 = argv[1];
    while(*chaine2 != '\0') {
      if(!isCharInteger(*chaine2)) {
        display_message("Wrong usage, parameter param2 should be integers when executing ./sum param1 param2\n");
        return -2;
      }
    chaine2++;
    }
  }

  int arg1 = stringToInteger(argv[1]);
  int arg2 = stringToInteger(argv[2]);

  printf ("Result : %d\n", arg1+arg2);
  return 0;
}

char isCharInteger(char c) {
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

char charToInteger(char c) {
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
  return -1;
}

char stringToInteger(char * c) { 
  int signe = 1;
  if (*c == '-') {
    signe = -1;
    c++;
  }
  char res = 0;
  while(*c != '\0') {
    char val = charToInteger(*c);
    res = res * 10 + val;
    c++;
  }
  return signe*res;
}
