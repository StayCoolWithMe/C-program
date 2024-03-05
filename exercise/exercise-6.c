#include <stdio.h>

int main() {
    int price[20];
    char name[20][20];
    int choice[20];
    float total[20];
    int quantity[20];
    float discount[20];
    int num;

    printf("Input the number of customers: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++) {
        printf("Customer No %d\n", i + 1);
        printf("Enter your name: ");
        scanf("%s", name[i]);
        printf("Menu:\n");
        printf("1. Coffee\n");
        printf("2. Tea\n");
        printf("3. Sting\n");
        printf("Enter your choice: ");
        scanf("%d", &choice[i]);

        switch (choice[i]) {
            case 1:
                printf("You ordered coffee\n");
                price[i] = 1;
                break;
            case 2:
                printf("You ordered tea\n");
                price[i] = 2;
                break;
            case 3:
                printf("You ordered sting\n");
                price[i] = 3;
                break;
            default:
                printf("Invalid choice\n");
                return 1; // Terminate the program in case of an invalid choice.
        }

        printf("Enter your quantity: ");
        scanf("%d", &quantity[i]);

        if (quantity[i] >= 5) {
            discount[i] = total[i] * 0.1;
            printf("You got 10%% off\n");
        } else {
            discount[i] = 0; // Ensure discount is initialized to zero when not applicable.
        }

        total[i] = price[i] * quantity[i] - discount[i];
    }

    for (int i = 0; i < num; i++) {
        printf("Hello %s\n", name[i]);
        printf("Your total: %.2f\n", total[i]);
    }

    return 0; // Indicate successful program execution.
}
