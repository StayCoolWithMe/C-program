#include<stdio.h>
int main()
{
    char name[5][20];
    int age[20];
    char province[5][20];
    for(int i=0;i<5;i++)
    {
        printf("---NO %d\n",i+1);
        printf("Enter your name");
        scanf("%s", name[i]);
        printf("Enter your age");
        scanf("%d",&age[i]);
        printf("What province are you from?");
        scanf("%s", province[i]);
    }
    for(int i=0;i<5;i++)
    {
        printf("Hello %s from %s\n",name[i] ,province[i]);
        printf("Your are successfully added\n");
    }
}