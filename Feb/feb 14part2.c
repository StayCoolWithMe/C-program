#include<stdio.h>
int main()
{
    //nececarry varbale for the program to wrlk
    int id, age;
    char name[20];
    char gender;
    float salary;
    char choice;
    //while with true 
    while(1)
    {
       printf("\nEnter your name:");
       scanf("%s",name);
       printf("\nEnter your Id:");
       scanf(" %d",&id);
        printf("\nEnter your age:");
       scanf(" %d",&age);
        printf("\nEnter your gender:");
       scanf(" %c",&gender);
        printf("\nEnter your salary:");
       scanf(" %f",&salary);
       printf("Do your want to continue(y/n)");
       scanf(" %c",&choice);
    if(choice=='n')
    break;
    }
}