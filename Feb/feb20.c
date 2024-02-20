#include<stdio.h>
int main()
{
    int choice;
    int quantity;
    float cost=0;
    char choice1;
    float total;
    printf("Menu");
    do{
    printf("\n1.Coffee");
    printf("\n2.Tea");
    printf("\n3.Milktea");
    printf("\nEnter your choice");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
    printf("your cost 2$");
    cost=2;
    break;
    case 2:
    printf("your cost 3$");
   cost=3;
    break;
    case 3:
    printf("your cost 4$");
    cost=4;
     break;
     case 4:
     printf("Invalid choice");
    }
     printf("\nEnter your quantity");
    scanf("%d", &quantity);

    total+=cost*quantity;
    printf("\nDo you want to order again?(y/n)");
    scanf(" %c", &choice1);
    }
    while(choice1!='n');
    printf("your total will be %f",total);

    
}
