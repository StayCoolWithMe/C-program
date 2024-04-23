#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 50
#define Max_Name_lenght 100
void input();
void output();
char name[Max][Max_Name_lenght];
char*available[]={"1.PP to KPS","2.PP to Sr","3.PP to BTB"};
float price[]={25,65,45};
int current=0;
int num=0;
int main()
{
 input();
 output();
}
void input(){
    printf("Enter the number of customer");
    scanf("%d",&num);
    while(num<1)
    {
        printf("Plase enter a valid number");
        scanf("%d",&num);
    }
    for(int i=0;i<num ;i++)
    {
        printf("\nEnter name for passenger %d",i+1);
        scanf("%s", name[i]);
        char choice[50];
        printf("Where your destination(PP to KPS,PP to Sr,PP to BTB)");
        scanf(" %s", choice);
        int index=-1;
        for(int i=0;i<3;i++)
        {
            if(strcmp(choice,available[i])==0)
            {
                index=i;
                break;
            }
        }
        if(index!=-1)
        {
            printf("%s will be available at %f/person(only serve for go)",available[index],price[index]);
        }
    }
}
void output()
    {   //This will make the output well organized and easy
        printf("Name\t\tdestination\t\tprice\n");
        for(int i=0;i<num;i++)
        {
        printf("%s\t\t%s\t\t%.2f\n",name[i],available[i],price[i]);
        }
    }