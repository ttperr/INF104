#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define LINEMAX 512

int main(int argc, char *argv[])
{
    char cmdline[LINEMAX];
    char ** cmdargs;
    int nbargs;

    while(1) {
        printf("$ ");
        fgets(cmdline, LINEMAX, stdin);
        // printf("%s\n", cmdline);
        cmdargs = (char **) malloc(sizeof(16*sizeof(char *)));
        nbargs = 0;
        int maxargs = 16;
        cmdargs[nbargs] = strtok(cmdline, " \n");
        while(cmdargs[nbargs] != NULL) {
            nbargs++;
            if(nbargs == maxargs) {
                maxargs += 16;
                cmdargs = realloc(cmdargs,maxargs*sizeof(char *));
            }
            cmdargs[nbargs] = strtok(NULL, " \n");
        }
        pid_t res = fork();
        switch(res) {
            case -1 :
                printf("Erreur lors du fork\n");
                return -1;
            case 0 :
                execvp(cmdargs[0], cmdargs);
                printf("Erreur lors de l'exec\n");
                return -1;
        }
    }

    return 0;
}