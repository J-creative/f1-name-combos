#include <stdio.h>
#include <stdlib.h>

#define LONGEST_WORD 10

int main(int argc, char *argv[]){
    if(argc < 3){
        printf("Please enter source-file and destination-file as arguments\n");
    }
    char line[256];
    FILE * read = fopen(argv[1],"r");
    FILE * write = fopen(argv[2],"w");

    while (fgets(line, sizeof(line), read) != NULL) {
        int count=0;
        char c=line[count];
        while(c != '\0'){
            c=line[count];
            count++;
        }
        if((count - 2) % 3 == 0 && count <LONGEST_WORD+3) fprintf(write,"%s",line);
    }
    fclose(read);
    fclose(write);
    return 0;
}