#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONGEST_WORD 10
#define WORD_COUNT 85406 //number of lines in words.txt file
#define MAX_NAMES 92
#define CHARS 4

char wordsArray[WORD_COUNT][LONGEST_WORD];
unsigned long long count=0;

void compare(char word[]){
        for(int w=0;w<WORD_COUNT;w++){
            if(strcmp(word,wordsArray[w])==0){
                printf("%s\n",wordsArray[w]);
                FILE * write = fopen("wordMatches.txt","a");
                fprintf(write,"%s\n",wordsArray[w]);
                fclose(write);
            }
            count++;
        }
}

void printPairs(char arr[MAX_NAMES][CHARS], int length)
{
        char joined[CHARS*2]="\0";
        strcat(joined,arr[0]);
        strcat(joined,arr[1]);
        compare(joined);
}
void printTriples(char arr[MAX_NAMES][CHARS], int length)
{
        char joined[CHARS*3]="\0";
        strcat(joined,arr[0]);
        strcat(joined,arr[1]);
        strcat(joined,arr[2]);
        compare(joined);
}

void permutation(char arr[MAX_NAMES][CHARS], int start, int end)
{

    if(start==1)compare(arr[0]);
    if(start==2)   printPairs(arr, end+1);
    if(start==3) //return after 3 so max word length is 9 letters, otherwise calculation takes ~MAX_NAMES times longer
    {
        
        printTriples(arr, end+1);
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
    FILE * wordsFile = fopen("words.txt","r");
    for(int i=0;i<WORD_COUNT;i++){
    fgets(line,LONGEST_WORD,wordsFile);
        line[strlen(line)-1]='\0';
        strcpy(wordsArray[i],line);
    }
    fclose(wordsFile);


    char nams[MAX_NAMES][CHARS] = {"AIT","ALB","ALG","ALO","BAD","BAR","BIA","BOT","BOU","BUE","BUT","CHA","CHI","COU","DAM","DAV","DIG","DIR","DLR","DOO","ERI","FIS","FIT","FMO","FRI","GAS","GIO","GLO","GRO","GUT","HAM","HAR","HEI","HUL","IDE","KAR","KLI","KOB","KOV","KUB","KVY","LAT","LEC","LIU","LOT","MAG","MAL","MAS","MAZ","MER","MON","MSC","NAK","NAS","NOR","OCO","PAL","PER","PET","PIC","PIQ","PIZ","RAI","RIC","ROS","RSS","RUS","SAI","SAT","SCH","SEN","SIR","SPE","STE","STR","SUT","TMO","TRU","TSU","VAN","VDG","VER","VET","VIL","WEB","WEH","WIN","WUR","YAM","ZHO","ZON","ZHO"};

    //construct array from string
    //char string[] = "HAM,HEI,ROS,ALO,KOV,NAK,BOU,RAI,KUB,GLO,SAT,PIQ,MAS,COU,TRU,SUT,WEB,BUT,DAV,VET,FIS,BAR,SCH,LIU,WUR,SPE,ALB,WIN,YAM,MSC,MON,KLI,TMO,IDE,VIL,FMO,DLR,DOO,KAR,FRI,ZON,PIZ,BUE,BAD,MAG,ALG,GRO,KOB,GAS,HUL,PET,DIG,SEN,CHA,MAL,DIR,PER,DAM,RIC,PIC,CHI,GUT,BOT,VDG,BIA,MAG,KVY,LOT,ERI,STE,VER,NAS,SAI,MER,RSS,PAL,WEH,HAR,VAN,OCO,STR,GIO,HAR,LEC,SIR,NOR,RUS,ALB,LAT,FIT,AIT,TSU,MAZ,MSC,ZHO";
    // char nams[MAX_NAMES][CHARS];
    // int i=0; //for string
    // int j=0; // for each name
    // int b=0; //for char in word
    // while(string[i] != '\0'){
    //     if(string[i] != ','){
    //         nams[j][b]=string[i];
    //     }else{
    //         nams[j][b]='\0';
    //         j++;
    //         b=-1;
    //     }
    //     b++;
    //     i++;
    // }
    // nams[j][b]='\0';

    permutation(nams,0,MAX_NAMES-1);

    printf("completed %llu comparisons\n",count);
    return 0;
}