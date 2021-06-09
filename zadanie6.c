#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char* argv[]){


    pid_t pid;
    int ret, status;
    pid_t ch_pid;
    pid = fork();

    if(pid==-1){
        perror("fork");
        _exit(1);
    }
    if(pid == 0){
        ret = execl("/bin/ls", "ls", "-l", NULL);
        if(ret==-1){

        perror("exec");
        return 1;
        }

    }
    if(pid > 0){
        ch_pid = wait(&status);
        if(WIFEXITED(status)){
            printf("Exit status %d\n", WEXITSTATUS(status));
        }

    }

    return 0;


}