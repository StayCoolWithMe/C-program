#include <stdio.h>
#include <string.h>

int main() {
    int choice;
    float distance;
    float cost = 0;
    float total = 0;
    char type[20];
    char choice1;
    int choice2;
    char name[20];

    do {
        printf("\nInput your transportation");
        printf("\n1. Bike");
        printf("\n2. Car");
        printf("\n3. Bus");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("6$ per 100km");
                cost = 6;
                break;
            case 2:
                printf("20$ per 100km");
                cost = 20;
                break;
            case 3:
                printf("13$ per 100km");
                cost = 13;
                break;
            default:
                printf("Invalid choice");
                break;
        }
        printf("\nEnter your distance(km): ");
        scanf("%f", &distance);
        total += cost *(distance/100); 

        printf("\nEnter your plan for this trip:\n1. Adventure\n2. Fast-ride\n3. Chill-ride\n");
        scanf("%d", &choice2);

        switch (choice2) 
        {
            case 1:
                strcpy(name, "adventure");

                printf("We recommend you to take the bike\n");
                break;
            case 2:
                strcpy(name, "fast-ride");
                printf("We recommend you to take the car\n");
                break;
            case 3:
                strcpy(name, "chill-ride");
                printf("We recommend you to take the bus\n");
                break;
            default:
                printf("Invalid choice");
                break;
        }
        printf("Do you want to book again? (y/n): ");
        scanf(" %c", &choice1);
    } while (choice1 != 'n');
    printf("Your total cost will be %f$\n", total);

}
