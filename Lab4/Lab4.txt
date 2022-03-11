#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CLEARSCREEN system("cls")

int getRandNum(int);
void oneSecond(void);

void track(int harePos, int tortPos);
int winnerCheck(int harePos, int tortPos);
int getHareGo(void);
int getTortGo(void);

int main(){
    srand(time(0));
    
    int harePos=1, tortPos=1;
    int winnerYes = 0;
    
    printf("BANG !!!!!\n");
    oneSecond();
    printf("AND THEY'RE OFF !!!!!\n");
    oneSecond();
    track(harePos, tortPos);
    oneSecond();

    while(winnerYes==0){
        harePos += getHareGo();
        tortPos  += getTortGo();
        
        if(harePos<1)
            harePos = 1;
        if(tortPos<1)
            tortPos = 1;
        
        track(harePos, tortPos);
        
        winnerYes = winnerCheck(harePos, tortPos);
        oneSecond();
    }
    return 0;
}

int getRandNum(int max){
    return rand()%max;
}

void oneSecond()
{
    clock_t start;
    int pauseLength = 1000;
    
    start = clock();
    while(clock() < start + pauseLength)
        ; 
}

void track(int harePos, int tortPos){
    int i;
    for(i=1; i<=harePos; i++)
        printf(" ");
    
    if(harePos == tortPos){
        printf("OUCH!!!\n");
    }
    else
        printf("H");
    
    for(i=1; i<=tortPos; i++)
        printf(" ");
    printf("T\n");
}

int winnerCheck(int harePos, int tortPos){
    if(harePos>=70 && tortPos>=70){
        printf("The animals tied.\n");
        return 1;
    }
    else if(harePos>=70){
        printf("Hare Wins! Yuch.\n");
        return 1;
    }
    else if(tortPos>=70){
        printf("TORTOISE WINS!!! YAY!!!\n");
        return 1;
    }    
    else 
        return 0;
}

int getHareGo(){
    int randomNum = rand()%1000;
    
    if(randomNum>=800)
        return 0;
    else if(randomNum>=600)
        return 9;   
    else if(randomNum>=500)
        return -12; 
    else if(randomNum>=200)
        return 1;
    else
        return -2;
}

int getTortGo(){
    int randomNum = rand()%1000;
    
    if(randomNum>=500)
        return 3;
    else if(randomNum>=200)
        return -6;  
    else
        return 1;
}