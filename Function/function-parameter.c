#include<Stdio.h>
char operator;
int num1;
int num2;
void input();
int sum(int num1,int num2);
int minus(int num1,int num2);
int multiply(int num1,int num2);
int divide(int num1,int num2);
int main()
{
    input();
}
void input()
{
    printf("Input two number");
    scanf("%d %d",&num1,&num2);
    printf("What your operator(+,-,*,/)");
    scanf(" %c", &operator);
    if(operator=='+')
    {
        int resultSum=sum(num1,num2);
        printf("%d",resultSum);
    }
    else if(operator=='-')
    {
        int resultMinus=minus(num1,num2);
        printf("%d",resultMinus);
    }
    else if(operator=='*')
    {
        int resultMultiply=multiply(num1,num2);
        printf("%d",resultMultiply);
    }
    else if(operator=='/')
    {
        int resultdivide=divide(num1,num2);
        printf("%d",resultdivide);
    }

}
int sum(int num1,int num2){
    return num1+num2;
}
int minus(int num1,int num2){
    return num1-num2;
}
int multiply(int num1,int num2){
    return num1*num2;
}
int divide(int num1,int num2){
    return num1/num2;
}


