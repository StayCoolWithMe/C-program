#include <stdio.h>
#include <string.h> // Include string.h for string manipulation functions

#define Max 50
#define Max_Name 100

// Function prototypes
void input();
void output();
void delete_order();
int sum(int x,int y)
{
    return x+y;
}

// Global variables
char name[Max][Max_Name];
float price[Max];
char* availabledrink[] = {"Coffee", "Tea", "Milkshake"};
float drinkprice[] = {3.0, 2.0, 4.0};
int current = 0;
int num = 0;
int quantity;
 int num1;
    int num2;
    int result;

int main() {
    input(); 
    output(); 
    delete_order();
}

void input() {
    printf("Enter the number of customers waiting in line: ");
    scanf("%d", &num);
    //sum function
    printf("Enter two number to add up");
    scanf("%d %d",&num1,&num2);
    result=sum(num1,num2);
    printf("The result is %d",result);

    while (num < 1 || num > Max) {
        printf("Invalid number, please enter a number between 1 and %d: ", Max);
        scanf("%d", &num);
    }
  
    for(int i = 0; i < num; i++) {
        printf("Enter name for customer %d: ",  i+ 1);
        scanf("%s", name[i]);

        char choice[20];
        printf("What is your preferred drink (Coffee, Tea, Milkshake)? ");
        scanf("%s", choice);

        int index = -1;
        for (int i = 0; i < 3; i++) {
            if (strcmp(choice, availabledrink[i]) == 0) {
                index = i;
                break;
            }
        }

        if (index != -1) {
            printf("%s is available at $%.2f\n", availabledrink[index], drinkprice[index]);

            printf("Enter quantity: ");
            scanf("%d", &quantity);
            
            price[i] = drinkprice[index] * quantity;
            printf("Total cost will be $%.2f\n", price[i]);
        } else {
            printf("Invalid choice.\n");
        }
    }
}

void output() {
    for(int j = 0; j < num; j++) 
    {
    printf("Customer \tDrink \tPrice\n");
    for (int i = 0; i < current; i++) {
        printf("%s\t\t%s\t$%.2f\n", name[i], availabledrink[i], price[i]);
    }

    }
}

void delete_order() {
    if (current > 0) {
        current--;
        printf("Last customer's order deleted.\n");
    } else {
        printf("No orders to delete.\n");
    }
}
