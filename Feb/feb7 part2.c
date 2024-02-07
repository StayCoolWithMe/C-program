#include<stdio.h>
#include<string.h>
int main()
{
    char Name[20];
    int quantity;
    float price;
    float Total;
    int choice;
    printf("Welcome:");
    printf("\nEnter your order:\n1.Coffee \n2.Tea \n3.Milktea\n");
    scanf("%d",&choice);
    printf("Quantatity");
    scanf(" %d",&quantity);
    switch(choice)
    {
        case 1:
        strcpy(Name,"Coffee");
        price=2;
        break;
        case 2:
        strcpy(Name,"Tea");
        price=3;
        break;
        case 3:
        strcpy(Name,"Milktea");
        price=3.50;
        break;
        default:
        printf("please enter valid number");
    }
    if (quantity<=2)
    {
        Total=price*quantity;
    }
    else if(quantity>=3 && quantity<10)
    {
        Total=(price*quantity)-((price*quantity)*0.1);
    }
    else
    {
        Total=price;
    }
    printf("\nName %s",Name);
    printf("\nTotal %.2f",Total);
}