#include<stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int secretnumber=5;
    int guess;
    int attempt;
     srand(time(NULL));
     secretnumber=rand()%100+1;
     printf("Welcome to the number gussing Game");
     printf("\nTry to guess a number between 1 and 100");
     while(1)
     {
        printf("Enterr your guess");
        scanf("%d",&guess);
        attempt++;
        if(guess==secretnumber)
        {
            printf("\nCongratulation you got the right anaswer",attempt);
            break;
        }
        else if(guess<<secretnumber)
        {
            printf("\nToo low ,round it up");
            break;
        }
        else
        {
            printf("Too high ,round it down");
            break;
        }
     }

}