#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>




int main(int argc, char *argv[]){

    pid_t pid, ch_pid;
    int status, size = 0;
    DIR* dir;
    FILE* file;
    struct dirent* dir_ent;
    struct stat statbuf;
    char path[40];
    
    if(argc != 3){
        
        perror("Należy podać dwa argumenty!\n");
        return 1;
    }
    pid = fork();
    
    if(pid == 0){

        if((file = fopen(argv[1], "w")) == NULL){

                perror("Błąd tworzenia/otwieranie pliku");
                return 2;
        }

        if((dir = opendir(argv[2])) == NULL){

                perror("Błąd otwarcia katalogu");
                return 3;
        }
        rewinddir(dir);
        while(dir_ent = readdir(dir))
        {   
            strcpy(path, argv[2]);
            stat(strcat(path, dir_ent->d_name), &statbuf);
            if(S_ISREG(statbuf.st_mode) || S_ISLNK(statbuf.st_mode)){

                fprintf(file, "Plik: %s ma wielkosc: %d bajtow\n",dir_ent->d_name, (int) statbuf.st_size);
                size += (int)statbuf.st_size;
            }
            
        }

        if (closedir(dir) != 0){
            perror("Błąd zamykania katalogu");
            return 4;
        }

        if (fclose(file) != 0){
            perror("Błąd zamykania pliku");
            return 5;
        }

        if(size > 1000){
            return 10;
        }else{
            return 1;
        }

        
    }
        
     if(pid > 0){
        ch_pid = wait(&status);
        if(WIFEXITED(status)){
            printf("\nStatus wyjścia %d\n Program zakończony", WEXITSTATUS(status));
        }

    }
    return 0;
}