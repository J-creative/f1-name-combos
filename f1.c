#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONGEST_WORD 25
#define WORD_COUNT 58109
#define MAX_NAMES 30
#define CHARS 4

char wordsArray[WORD_COUNT][LONGEST_WORD];
unsigned long long count=0;

void compare(char word[]){
        for(int w=0;w<WORD_COUNT;w++){
            if(strcmp(word,wordsArray[w])==0){
                printf("%s\n",wordsArray[w]);
            }
            count++;
        }
}

void printPairs(char arr[MAX_NAMES][CHARS], int length)
{
        char joined[CHARS*2]="";
        strcat(joined,arr[0]);
        strcat(joined,arr[1]);
        compare(joined);
}
void printTriples(char arr[MAX_NAMES][CHARS], int length)
{
        char joined[CHARS*3]="";
        strcat(joined,arr[0]);
        strcat(joined,arr[1]);
        strcat(joined,arr[2]);
        compare(joined);
}
void printQuads(char arr[MAX_NAMES][CHARS], int length)
{
        char joined[CHARS*3]="";
        strcat(joined,arr[0]);
        strcat(joined,arr[1]);
        strcat(joined,arr[2]);
        compare(joined);
}

void permutation(char arr[MAX_NAMES][CHARS], int start, int end)
{

    if(start==1)compare(arr[0]);
    if(start==2)printPairs(arr, end+1);   
    if(start==3) //we can return after 3 because t
    {
        printTriples(arr, end+1);
        //return;
    }
    if(start==4) //we can return after 3 because t
    {
        printQuads(arr, end+1);
        return;
    }
    int i;
    for(i=start;i<=end;i++)
    {
        // swapping numbers
        char temp[CHARS];
        strcpy(temp,arr[i]);
        strcpy(arr[i],arr[start]);
        strcpy(arr[start],temp);

        //recursive call on adjusted array
        permutation(arr, start+1, end);
        
        char temp2[CHARS];
        strcpy(temp2,arr[i]);
        strcpy(arr[i],arr[start]);
        strcpy(arr[start],temp2);
    }
}



int main(){
    char line[LONGEST_WORD];
    FILE * wordsFile = fopen("words5.txt","r");
    for(int i=0;i<WORD_COUNT;i++){
    fgets(line,LONGEST_WORD,wordsFile);
        line[strlen(line)-1]='\0';
        strcpy(wordsArray[i],line);
    }
    //printf("%s",wordsArray[4]);
    fclose(wordsFile);


    //construct array
    char string[] = "HAM,HEI,ROS,ALO,KOV,NAK,BOU,RAI,KUB,GLO,SAT,PIQ,MAS,COU,TRU,SUT,WEB,BUT,DAV,VET,FIS,BAR,SCH,LIU,WUR,SPE,ALB,WIN,YAM,MSC,MON,KLI,TMO,IDE,VIL,FMO,DLR,DOO,KAR,FRI,ZON,PIZ,BUE,BAD,MAG,ALG,GRO,KOB,BIA,GAS,HUL,PET,DIG,SEN,CHA,MAL,DIR,PER,DAM,RIC,VER,PIC,CHI,GUT,BOT,VDG,BIA,MAG,KVY,LOT,ERI,STE,VER,NAS,SAI,MER,RSS,PAL,WEH,HAR,VAN,OCO,STR,GIO,HAR,LEC,SIR,NOR,RUS,ALB,LAT,FIT,AIT,TSU,MAZ,MSC,ZHO";
    char nams[MAX_NAMES][CHARS];
    int i=0; //for string
    int j=0; // for each name
    int b=0; //for char in word
    while(string[i] != '\0'){
        if(string[i] != ','){
            nams[j][b]=string[i];
        }else{
            nams[j][b]='\0';
            j++;
            b=-1;
        }
        b++;
        i++;
    }
    nams[j][b]='\0';
    permutation(nams,0,j);

    printf("completed %llu comparisons\n",count);
    return 0;
}