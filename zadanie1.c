#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//snprintf
#define BUF_SIZE 1024

int main(int argc, char *argv[]){

    int input_fd, output_fd, i;
    ssize_t ret_in;
    char buffer[BUF_SIZE];

    i = 1;
    input_fd = open(argv[1], O_RDONLY);

   if(argc != 2){
       printf("Usage: %s file_origin file_destination", argv[0]);
       return 1;
    }
    if(input_fd == -1){
        perror(argv[1]);
        return 1;
    }

    char a[] = ".red";
    char b[40];
    strcpy(b, argv[1]);
    strcat(b, a);
    output_fd = open(b, O_CREAT | O_TRUNC | O_WRONLY, 0644);

    while((ret_in = read(input_fd, &buffer, 1)) > 0 ){

        if(i % 3 == 0){
		printf("%d",i);
            write(output_fd, &buffer, ret_in);
      }
        i = i+1;

    }
}

