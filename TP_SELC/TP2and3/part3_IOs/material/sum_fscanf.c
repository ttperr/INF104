#include <stdio.h>

int main(int argc, char *argv[])
{

  if (argc != 2)
  {
    printf("Wrong usage : expected ./sum_fscanf file_name");
    return -1;
  }

  FILE *f = fopen(argv[1], "rw");
  if (f == NULL)
  {
    printf("Errur lors de l'ouverture du fichier...!\n");
    return -2;
  }

  int somme;
  int arg1;
  while (1)
  {
    int ret = fscanf(f, "%d", &arg1);
    if (ret == EOF)
    {
      break;
    }
    if (ret == 1)
    {
      somme += arg1;
    }
  }
  printf("Result : %d\n", somme);

  FILE *fres = fopen(argv[1], "rw");
  if (fres == NULL)
  {
    printf("Errur lors de l'ouverture du fichier...!\n");
    return -3;
  }

  fprintf(fres, "%d\n", somme);
  return 0;
}
