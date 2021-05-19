#include <stdio.h>
#include <errno.h> //biblioteka do errorów

int main(int argc, char *argv[]){

    FILE *wp;
    unsigned long counter = 0;
    int ch;

    if(argc != 2){
        fprintf(stderr, "Usage: %s file_names\n", argv[0]);
        return 1;
    }
    

    wp = fopen(argv[1], "r");

    if(!wp){
        perror(argv[1]);
        perror("\nTestt druga linia\n");
        return 2;
    }

    while((ch = fgetc(wp))!=EOF){

        counter ++;
        fputc(ch, stdout);
    }
    fclose(wp);

    printf("\n\n File %s contains %lu characters\n", argv[1], counter);
    return 0;
}
