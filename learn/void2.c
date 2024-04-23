#include<stdio.h>
void identifier(char name[], int age) 
{
    printf("Hello %s, you are %d year old\n",name,age);}
int findmax(int number1,int number2)
{
    if(number1>number2)
    {
        return number1;
    }
    else{
        return number2;
    }
}

int main()
{
    char name[5][20];
    int age[5];
    int numofpeople;
    printf("Enter the number of people(1-5)");
    scanf("%d",&numofpeople);
    while(numofpeople>5 || numofpeople<1)
    {
        printf("Number of people is umatchable ,please enter a new one (1-5)");
        scanf("%d",&numofpeople);
    }
    for(int i=0;i<numofpeople;i++)
    {
        printf("What your name");
        scanf("%s", name[i]);
        printf("What your age");
        scanf("%d",&age[i]);
        identifier(name[i] , age[i]);
    }
    int findmax(int number1,int number2);
    int result=0;
    int number1;
    int number2;
    printf("Enter the frist digital :");
    scanf("%d",&number1);
    printf("Enter the second digital number:");
    scanf("%d", &number2);
    findmax(number1,number2);
    result=findmax( number1 ,number2);
    printf("The reuslt is %d",result);
    

    

}

