#include <stdio.h>

int main(int argc, char *argv[]) {
  /* To be completed */
  int arg1, arg2;

  printf("Enter first number :\n");
  int ret = scanf("%d", &arg1);
  if (ret != 1) {
    printf ("Error when reading input, make sure you write an integer value\n");
    return -1;
  }

  printf ("Enter second number :\n");
  ret = scanf("%d", &arg2);
  if (ret != 1) {
    printf ("Error when reading input, make sure you write an integer value\n");
    return -1;
  }

  printf ("%d + %d = %d\n", arg1, arg2, arg1+arg2);
  return 0;
}