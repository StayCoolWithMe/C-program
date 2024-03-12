#include<stdio.h>

int main() {
    int searchID;
    char name[20][50];
    int age[20];
    char address[20][100];
    float salary[20];
    int retired[20];
    int choice;
    float newSalary;
    int id[20];

    for(int i = 0; i < 3; i++) {
        printf("\nNo %d\n", i + 1);
        printf("Enter Your Name: ");
        scanf("%s", name[i]);
        printf("Enter your age: ");
        scanf("%d", &age[i]);
        printf("Enter your address: ");
        scanf("%s", address[i]);
        printf("Enter your ID: ");
        scanf("%d", &id[i]);
        printf("Enter Your Salary: ");
        scanf("%f", &salary[i]);
    }

    printf("\n1. Update salary\n");
    printf("2. Year of retirement\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) 
    {
        case 1:
            printf("Enter ID to search: ");
            scanf("%d", &searchID);
            int found = 0;
        for(int i = 0; i < 3; i++) {
        if(id[i] == searchID)
         {
             printf("Name: %s\n", name[i]);
            printf("Your current salary is: %.2f\n", salary[i]);
            printf("Your new salary: ");
            scanf("%f", &newSalary);
            salary[i] = newSalary;
            found = 1;
            break;
        }
            }
            if(!found) {
                printf("ID %d not found.\n", searchID);
            }
            break;
        case 2:
         for(int i = 0; i < 3; i++)
             {
             if(age[i] >= 65) {
            printf("Dear %s, it's time for you to retire.\n", name[i]);
                }
                else {
                    retired[i] = 65 - age[i];
                printf("Dear %s, You're Marvelous.\n", name[i]);
                 printf("You are %d years away from your retirement year.\n", retired[i]);
                }
            }
            break;

        default:
            printf("unmatch choice.\n");
    }

    printf("\nDetails:\n");
    for(int i = 0; i < 3; i++) {
        printf("Name: %s\n", name[i]);
        printf("Age: %d\n", age[i]);
        if(age[i] >= 65) {
            printf("Dear %s, it's time for you to retire.\n", name[i]);
                }
                else {
                    retired[i] = 65 - age[i];
                printf("Dear %s, You're Marvelous.\n", name[i]);
                 printf("You are %d years away from your retirement year.\n", retired[i]);
                }

        printf("Salary: %.2f\n", salary[i]);
        printf("\n");
    }

}
