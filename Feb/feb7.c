#include<stdio.h>
int main()
{
    float Total;
    int choice;
    printf("Welcome to Cafe system!\n");
    printf("1.Order Coffee\n");
    printf("2.Order Tea\n");
    printf("3.Exit \n");
    printf("4.Enter your choice(1-3)\n");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
        printf("Ordered Coffee.$2.50 add to to total!\n");
        Total=2.50;
        break;
        case 2:
        printf("Oreded Tea.$2.00 add to the total!\n");
        Total=2.00;
        break;
        case 3:
        printf("Exiting Cafe System.Thank you\n");
        break;
        default:
        printf("Invalid choice.Please enter the number between 1 and 3 \n");
    }
      printf("Total %.2f",Total);


}