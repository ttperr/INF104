#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void on_signal_reception(int);

int main(int argc, char *argv[])
{
  int Nb_Sig;
  printf("NSIG = %d\n", NSIG);
  sleep(3);
  for (Nb_Sig = 1; Nb_Sig < NSIG; Nb_Sig++)
  {
    if (signal(Nb_Sig, SIG_IGN) == SIG_ERR)
      printf("signal(%d, SIG_IGN) failed\n", Nb_Sig);
  }
  while (1)
  {
    sleep(5);
  } /* Wait for receiving signals */
  return 0;
}

void on_signal_reception(int sig_number)
{
  printf("Here we go, signal %d received!\n", sig_number);
}
