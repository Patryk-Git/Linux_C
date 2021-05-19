#include <stdio.h>

#define BUF_SIZE 41

int main(int argc, char *argv[]){

    FILE *wp;
    char word[BUF_SIZE];
    wp = fopen("slowa.txt", "a+");

    if(wp == NULL){
        fprintf(stderr, "Blad!");
        return 1;
    }

    puts("Provide words to add them to a file");
    fputs("To end enter: #\n", stdout);

    while((fscanf(stdin, "%40s", word) == 1) &&  (word[0] != '#')){

        fprintf(wp, "%s", word);
        fprintf(wp, "%s", " ");
    }
    printf("Content of file:\n");
    rewind(wp);
    while (fscanf(wp, "%s", word) == 1)
    {
        puts(word);
    }
    puts("\nDone");
    if(fclose(wp)!=0){
        fprintf(stderr, "Error while closing file");
        return 2;
    }


    return 0;
}
