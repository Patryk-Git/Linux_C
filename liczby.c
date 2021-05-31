#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include <unistd.h>
#include <time.h>
//snprintf
#define BUF_SIZE 1024

int main(int argc, char *argv[]){

   
    int fd, a;
    int j;
    time_t t;
    char buffer[BUF_SIZE];
    fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if(argc != 2){
        printf("Usage: %s file_origin file_destination", argv[0]);
        return 1;
    }
    if(fd == -1){
        perror(argv[1]);
        return 1;
    }

    srand((unsigned) time(&t));
	
    for(int i = 0; i < 10; i++){
        a = rand() % 50;
	j += sprintf(buffer+j, "%d\n", a);
        
    }

    write(fd, buffer, 40);



}

