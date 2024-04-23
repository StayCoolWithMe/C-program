#include<stdio.h>
#include<stdlib.h>
int  sum(int  x,int y)
{
    return x+y;
}
int  divide(int  x,int y)
{
    return x/y;
}
int  minus(int x,int y)
{
    return x-y;
}
int multiply(int x,int y)
{
    return x*y;
}
int num1;
int num2;
int result;
char operator;

int main()
{
    while(1)
    {
    printf("\nEnter two number ");
    scanf("%d %d",&num1,&num2);
    printf("Enter the operator(+ - * /)");
    scanf(" %c",&operator);
    if(operator=='+')
    {
        result=sum( num1, num2);
        printf("%d",result);
    }
    else if(operator=='-')
    {
        result=minus( num1, num2);
        printf("%d",result);
    }
    else if(operator=='*')
    {
        result=multiply( num1, num2);
        printf("%d",result);
    }
    else if(operator=='/')
    {
        result=divide(  num1, num2);
        printf("%d",result);
    }
    }
    exit(0);  
}