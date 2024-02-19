#include<stdio.h>
int main()
{
    int number,facatorial=1;
    printf("Enter a position interger");
    scanf("%d",&number);
    if(number<0)
    {
        printf("\nFactorial is not defind for negative number");
    }
    else{
        int i=1;
        do{
            facatorial=facatorial*i;
            i++;
        }
        while(i<=number);
            printf("Factorial of %d=%d",number,facatorial);
        {
        }
    }
}