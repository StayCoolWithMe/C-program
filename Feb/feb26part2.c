#include<stdio.h>
int main()
{
    int num=3;
    for(int i=0;i<num;i++)
    {
        char name[20];
        int choice;
        float sugarrate;
        printf("Customer No %d",i+1);
        printf("\nCustomer name");
        scanf("%s", name);
        printf("Input your oder(1 for tea,2 for coffee)");
        scanf("%d",&choice);
        printf("Enter your sugar rate");
        scanf("%f",&sugarrate);
        printf("\nCustomer No %d",i+1);
        printf("\nCustomer name %s",name);
        printf("\nOrderd: ");
        switch(choice)
        {
            case 1:
            printf("Tea\n");
            printf("Cost: your cost 1$");
            break;
            case 2:
            printf("your cost 2$");
            break;
            default:
            printf("Unkown ordered");
            break;
        }
        printf("\nsugar rate %.2f\n",sugarrate);



    }

}