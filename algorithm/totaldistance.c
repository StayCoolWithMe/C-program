#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#define max 50 
void howFarCanYouGo(int mainTank[],int SecondTank[],int i); 
int calculate(int mainTank,int SecondTank); 
int mainTank[max]; 
int SecondTank[max]; 
int i=0; 
int main() 
{ 
    do 
    { 
      howFarCanYouGo(mainTank,SecondTank,i); 
    }while(i<max); 
} 
void howFarCanYouGo(int mainTank[],int SecondTank[],int i) 
{ 
        while(i<max) 
        { 
        printf("Main Tank Amount:"); 
        scanf("%d",&mainTank[i]); 
        printf("Second Tank Amount:"); 
        scanf("%d",&SecondTank[i]); 
        if(mainTank[i]<1 || SecondTank[i]>100) 
        { 
            printf("Error,please enter another one for Main and Secondaly Tank"); 
            scanf("%d %d",&mainTank[i],&SecondTank[i]); 
        } 
        int milage=calculate( mainTank[i], SecondTank[i]); 
        printf("Distance that you can travel:%d\n",milage); 
        i++; 
        } 
 
} 
int calculate(int mainTank, int SecondTank) { 
    int mileage = mainTank * 10;
    
    if ((mainTank % 5) == 0 && SecondTank > 0) { 
        SecondTank -= 1;
        mainTank += 1;
    } 
    
    return (mainTank * 10); 
}