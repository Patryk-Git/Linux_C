#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

static void sig_usr(int signo);
int main(int argc, char* argv[]){

    int pid;

    if(signal(SIGUSR1, sig_usr) == SIG_ERR){

        perror("sigusr1");
        return 1;
    }
    if(signal(SIGUSR2, sig_usr) == SIG_ERR){
        perror("sigusr2");
        return 2;
    }
    file = fopen((char)getpid(), "w");

    return 0;
}


static void sig_usr(int signo){

    if(signo == SIGUSR1){
        fprintf(file, "PPID %d\n", getppid());

    }else if(signo == SIGUSR2){
        file = fopen((char)getpid(), "w");
    }else{
        printf("Get another signal: %d\n", signo);
    }
    if(fclose(file) != 0)
    {
            perror("fclose");
            _exit(1);
    }
}