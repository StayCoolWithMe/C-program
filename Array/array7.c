#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max_employee 50
#define Max_Name_Lenght 100

int main() {
    char name[Max_employee][Max_Name_Lenght];
    int ID[Max_employee];
    float salary[Max_employee];
    float newsalary = 0;
    char gender[Max_employee];
    int age[Max_employee];
    int employeenumber = 0;
    int currentemployee = 0;
    int choice;

    printf("Enter the employee number: ");
    scanf("%d", &employeenumber);

    while (employeenumber < 1 || employeenumber > Max_employee) {
        printf("INVALID, PLEASE ENTER A MATCHABLE NUMBER: ");
        scanf("%d", &employeenumber);
    }

    for (int i = 0; i < Max_employee; i++) {
        ID[i] = i + 1;
    }

    do {
        printf("\n1. Add new employee\n");
        printf("2. Remove employee\n");
        printf("3. Salary update\n");
        printf("4. Additional salary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (currentemployee < employeenumber) {
                    printf("Enter the name for employee %d to add: ", currentemployee + 1);
                    scanf("%s", name[currentemployee]);
                    printf("Enter your age for employee %d: ", currentemployee + 1);
                    scanf("%d", &age[currentemployee]);
                    printf("Enter your ID for employee %d: ", currentemployee + 1);
                    scanf("%d", &ID[currentemployee]);
                    printf("Enter the gender for employee %d (M/F): ", currentemployee + 1);
                    scanf(" %c", &gender[currentemployee]);
                    printf("Enter the salary for him/her: ");
                    scanf("%f", &salary[currentemployee]);

                    if (age[currentemployee] >= 18) {
                        printf("You are available to join\n");
                    } else {
                        printf("You are underage\n");
                    }
                } else {
                    printf("MAXIMUM EMPLOYEE REACHED\n");
                }
                currentemployee++;
                break;
            }
            case 2: {
                if (currentemployee > 0) {
                    int removeemployee;
                    printf("Enter the number of employee to remove (1-%d): ", currentemployee);
                    scanf("%d", &removeemployee);
                    if (removeemployee > 0 && removeemployee <= currentemployee) {
                        for (int i = removeemployee - 1; i < currentemployee - 1; i++) {
                            strcpy(name[i], name[i + 1]);
                        }
                        currentemployee--;
                        printf("Remove successfully\n");
                    } else {
                        printf("UNMATCH, PLEASE ENTER A VALID ONE\n");
                    }
                } else {
                    printf("NO EMPLOYEE TO REMOVE\n");
                }
                break;
            }
            case 3: {
                int searchID;
                int found = -1;
                printf("Enter ID to search: ");
                scanf("%d", &searchID);
                for (int i = 0; i < currentemployee; i++) {
                    if (searchID == ID[i]) {
                        printf("ID found, your current salary is %.2f\n", salary[i]);
                        printf("Enter a new salary: ");
                        scanf("%f", &newsalary);
                        salary[i] = newsalary;
                        found = 1;
                        break;
                    }
                }
                if (found == -1) {
                    printf("ID not found\n");
                }
                break;
            }
            case 4: {
                if (age[currentemployee - 1] >= 50) {
                    printf("You got $20 additional salary\n");
                    salary[currentemployee - 1] += 20;
                } else if (age[currentemployee - 1] >= 40) {
                    printf("You got $10 additional salary\n");
                    salary[currentemployee - 1] += 10;
                } else {
                    printf("You got no additional salary\n");
                }
                break;
            }
            case 5: {
                exit(0);
            }
        }
    } while (choice != 5);

    return 0;
}
