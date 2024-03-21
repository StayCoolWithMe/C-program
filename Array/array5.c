#include <stdio.h>
#include <stdlib.h>

#define Max_employee 50
#define Max_Name_Length 50

int main() {
    char name[Max_employee][Max_Name_Length];
    int age[Max_employee];
    int ID[Max_employee];
    int numofemployee = 0;
    int currentemployee = 0;
    char comment[Max_employee][Max_Name_Length];
    char gender[Max_employee];
    float salary[Max_employee];
    int yearofretirement[Max_employee];
    float newsalary;
    int searchID;

    printf("Enter the number of employees: ");
    scanf("%d", &numofemployee);
    while (numofemployee < 0 || numofemployee > Max_employee) {
        printf("INVALID, PLEASE ENTER A MATCHABLE ONE: ");
        scanf("%d", &numofemployee);
    }

    for (int i = 0; i < Max_employee; i++) {
        ID[i] = i + 1;
    }

    int choice;
    do {
        printf("\n1. Employee management\n");
        printf("2. Retirement requirement\n");
        printf("3. Leave a comment for the employee\n");
        printf("4. Update salary\n");
        printf("5. Exit\n");
        printf("What's your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter the name for employee %d: ", currentemployee + 1);
                scanf("%s", name[currentemployee]);
                printf("Enter the age for employee %d: ", currentemployee + 1);
                scanf("%d", &age[currentemployee]);
                printf("Enter the gender of employee %d (M/F): ", currentemployee + 1);
                scanf(" %c", &gender[currentemployee]);
                printf("Enter the salary: ");
                scanf("%f", &salary[currentemployee]);
                currentemployee++;
                break;
            }
            case 2: {
                printf("\nAge retirement\n");
                for (int i = 0; i < currentemployee; i++) {
                    if (gender[i] == 'M' || gender[i] == 'm') {
                        printf("Employee %d's year of retirement will be %d\n", i + 1, 65 - age[i]);
                    } else if (gender[i] == 'F' || gender[i] == 'f') {
                        printf("Employee %d's year of retirement will be %d\n", i + 1, 60 - age[i]);
                    } else {
                        printf("Invalid gender for employee %d, please enter a valid one (M/F)\n", i + 1);
                    }
                }
                break;
            }
            case 3: {
                printf("Enter a comment for employee %d: ", currentemployee);
                scanf("%s", comment[currentemployee - 1]);
                break;
            }
            case 4: {
                printf("Enter ID to search: ");
                scanf("%d", &searchID);
                int found = 0;
                for (int i = 0; i < currentemployee; i++) {
                    if (ID[i] == searchID) {
                        printf("Name: %s\n", name[i]);
                        printf("Current salary: %.2f\n", salary[i]);
                        printf("Enter the new salary: ");
                        scanf("%f", &newsalary);
                        salary[i] = newsalary;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("ID %d not found.\n", searchID);
                }
                break;
            }
            case 5: {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice, please enter a valid one.\n");
                break;
            }
        }
    } while (choice != 5);

   
}
 

