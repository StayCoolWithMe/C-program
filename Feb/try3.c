#include<stdio.h>
#include<string.h>

int main()
{
    int num;
    int cost = 0;
    float total = 0;
    int choice;
    int quantity;
    float discount;
    char name[20];
    
    printf("Enter the line costumer: ");
    scanf("%d", &num);

    for(int i = 1; i <= num; i++)
    {
        printf("\nCustomer %d\n", i);
        printf("Menu\n");
        printf("1. Coffee\n");
        printf("2. Tea\n");
        printf("3. Chocolate Frappe\n");
        printf("Enter your order(1-3): ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Coffee\n");
                strcpy(name, "Coffee");
                cost = 2;
                break;

            case 2:
                printf("Tea\n");
                strcpy(name, "Tea");
                cost = 3;
                break;

            case 3:
                printf("Chocolate Frappe\n");
                strcpy(name, "Chocolate Frappe");
                cost = 4;
                break;

            default :
                printf("Invalid choice\n");
    
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);
        total += cost * quantity;

        if(quantity >= 3)
        {
            printf("Congratulations! You get 10%% off\n");
            discount = total * 0.1;
            printf("You have saved %.2f\n", discount);
            total =(cost * quantity)-discount; 
              printf("Your total cost: %.2f\n", total);
        printf("Ordered: %s\n", name);
        printf("Your discount: %.2f\n", discount);
        }
        else
        {
            discount = 0;
        printf("Your total cost: %.2f\n", total);
        printf("Ordered: %s\n", name);
        printf("Your discount: %.2f\n", discount);
        }

    }
}
