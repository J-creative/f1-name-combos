#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc < 3){
        printf("Please enter source-file and destination-file as arguments\n");
    }
    char line[50];
    FILE * read = fopen(argv[1],"r");
    FILE * write = fopen(argv[2],"w");
    //printf("%s",wordsArray[4]);
    while (fgets(line, sizeof(line), read) != NULL) { // tsin is FILE* input
        int count=0;
        char c=line[count];
        while(c != '\0'){
        //printf("%c",line[count]);
            c=line[count];
            count++;
        }
        //printf("%d",count);

        if((count - 2) % 3 == 0) fprintf(write,"%s",line);
    }
    fclose(read);
    fclose(write);
    return 0;
}