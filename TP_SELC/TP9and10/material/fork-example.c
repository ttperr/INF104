#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main (){
  pid_t ret;
  printf("printf-0 Before fork : executing process number: %d\n", (int)getpid());
  ret = fork();
  if (ret == 0) sleep (4);
  printf("printf-1 Forked, returned value is: %d\n", (int)ret);
  sleep(0);
  printf("printf-2 Executing process number: %d\n", (int)getpid());
  return 0;
}
