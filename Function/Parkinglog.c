#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Max_Capacity 10

char Car[Max_Capacity][100];
int num=0;
int choice=0;
int current=0;
int carIndex=0;
 void input();
 void output();
 int main()
 {
    input();
    output();
 }
 void input()
 {
    printf("Enter the number of customer to car park(1-10) ");
    scanf("%d",&num);
    while(num<1 || num>Max_Capacity)
    {
        printf("Sorry the number you enter is not valid,please enter another one");
         scanf("%d",&num);
    }
    do{
   printf("\n1.Park a car\n");
   printf("2.Remove car\n");
   printf("3.Exit\n");
   printf("What your choice");
   scanf("%d",&choice);
   switch (choice)
   {
    case 1:{
        if(carIndex<Max_Capacity)
        {
            printf("Adding car to park");
            scanf("%s", Car[carIndex]);
            carIndex++;
        }
        else{
            printf("Sorry the car park is full\n");
        }
    break;
    }
    case 2: {
        if(carIndex>0)
        {
            printf("Removing car \n");
     
            carIndex--;
            
        }
        else {
            printf("Sorry the parking lot is empty\n");
        }
    break;
    }
    case 3 :{
        exit(0);
    }
    default:
    {
        printf("Unvalid choice\n");
    }
   }

    }
    while(choice != 3);
 }
void output()
{
if(carIndex>0)
{
    printf("The parking lot is full thus not available\n");
}
else{
    printf("The parking lot is available\n");
}
}