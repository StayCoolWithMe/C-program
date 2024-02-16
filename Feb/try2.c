#include<stdio.h>
#include<string.h>
int main()
{
    float cost;
    int quantity;
    int choice;
    float total;
    char name[20];
    printf("\nMenu:");
    printf("\n1.Pizza:25$");
    printf("\n2.Burger:10$");
    printf("\n3.Sandwiches:5$\n");
    printf("please enter your choice(1-3)\n");
    scanf("%d",&choice);
    printf("please enter quantity:");
    scanf("%d",&quantity);
    switch(choice)
    {
        case 1:
        strcpy(name,"Pizaa");
        cost=25;
        break;
        case 2:
        strcpy(name,"Burger");
        cost=10;
        break;
        case 3:
         strcpy(name,"Sandwiches");
        cost=5;
        break;
        default:
        printf("please enter valid choice");
        break;
    }
    total=quantity*cost;
    printf("\nYou ordered %s",name);
    printf("\nYour total: %f",total);
}