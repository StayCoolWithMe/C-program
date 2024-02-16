#include<stdio.h>
#include<stdlib.h>
int main()
{
    char choice='y';
    float amount;
    float exchangerate;
    char fromcurrency[5];
    char tocurrency[5];
    float convertedamount;
    while(1)
    {
        printf("\nEnter the amount");
        scanf("%f",&amount);
        printf("Enter the source currency(eg.USD)");
        scanf(" %s",fromcurrency);
        printf("Enter target currency(eg.YUAN)");
        scanf(" %s",tocurrency);
        printf("Enter to exchange rate: ");
        scanf(" %f",&exchangerate);
        convertedamount=amount*exchangerate;
        printf(" your exchange is:%.2f",convertedamount);
        printf("\nDo you want to convert another one(y/n)");
        scanf(" %c",&choice);
        if(choice='n')
        {
            exit(1);
        }
    }
}