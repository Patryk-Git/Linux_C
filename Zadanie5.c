#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char* argv[]){

    pid_t pid;
    int status;
    pid_t ch_pid;

    pid = fork();
    if(pid==-1){
        perror("fork");
        _exit(1);
    }
    if(pid == 0){

        FILE* file;

        file = fopen("numbers.txt", "w");
        if(!file)
        {
            perror("fopen");
            _exit(1);
        }

        for(int i = 1; i <= 99; i++){

            if(i % 3 == 0){
                fprintf(file, "%d\n", i);
            }

        }
        if(fclose(file) != 0)
        {
            perror("fclose");
            _exit(1);
        }
        _exit(0);
    }
    if(pid > 0){
        ch_pid = wait(&status);
        if(WIFEXITED(status)){
            printf("Exit status %d\n", WEXITSTATUS(status));
        }

    }

    return 0;
}