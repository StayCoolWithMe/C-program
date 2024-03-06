#include <stdio.h>

int main() {
    int Registed_ID = 12812; // Initial registered ID
    char name[20][20];
    int age[20];
    int ID[20]; // Store the generated number value
    int option;

    for (int i = 0; i < 5; i++) {
        Registed_ID += 1;
        ID[i] = Registed_ID;
        printf("Student No%d\n", i + 1);
        printf(" Student Register Section\n");
        printf("1. Register\n2. Display\n3. Search\n");
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("What is your Name? ");
                scanf("%s", name[i]);
                printf("What is your age? ");
                scanf(" %d", &age[i]);
                printf("Student Register ID %d\n", ID[i]);
                break;
            case 2:
                for (int j = 0; j <= i; j++) {
                    printf("Student Name: %s\n", name[j]);
                    printf("Student Age: %d\n", age[j]);
                    printf("Registered ID: %d\n", ID[j]);
                    if (age[j] >= 18) {
                        printf("You are available to register\n\n");
                    } else {
                        printf("You are not available to register\n\n");
                    }
                }
                break;
            case 3:
                printf("Enter Student ID to search: ");
                scanf("%d", &searchID);
                int searchID;
                int found = 0;
                for (int j = 0; j <= i; j++) {
                    if (ID[j] == searchID) {
                        printf("Student Name: %s\n", name[j]);
                        printf("Student Age: %d\n", age[j]);
                        printf("Registered ID: %d\n", ID[j]);
                        if (age[j] >= 18) {
                            printf("You are available to register\n\n");
                        } else {
                            printf("You are not available to register\n\n");
                        }
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Student with ID %d not found.\n\n", searchID);
                }
                break;
            default:
                printf("Invalid option. Please enter 1, 2, or 3.\n");
                i--; // To repeat the current iteration
        }
    }

    return 0;
}
