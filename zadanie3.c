#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]){

    FILE *wp;
    FILE *wp2;
    if(argc != 2){
        fprintf(stderr, "Usage: %s file_names\n", argv[0]);
        return 1;
    }
    
    wp = fopen(argv[1], "r");
    
    if(!wp){
        perror(argv[1]);
        return 2;
    }
    wp2 = fopen("test.txt", "w+");
    int i = 0;
    int ch;
    while((ch = fgetc(wp))!=EOF){
        if(i % 3 == 0){
            fputc(ch, wp2);
        }
        i++;
    }
    fclose(wp);
    puts("\nWykonane");
    if(fclose(wp2)!=0){
        fprintf(stderr, "Błąd przy zamykaniu");
        return 2;
    }

    return 0;
}
