#include <stdio.h>

int main() {
    int numEmployees = 5;

    for (int i = 0; i < numEmployees; ++i) {
        char name[50];
        int role, performanceRating;

        printf("\nEnter details for Employee %d:\n", i + 1);

        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter role (1 for Manager, 2 for Developer, 3 for Designer): ");
        scanf("%d", &role);

        printf("Enter performance rating (1 to 5): ");
        scanf("%d", &performanceRating);

        printf("\nEmployee %d:\n", i + 1);
        printf("Name: %s\n", name);
        printf("Role: ");
        switch (role) {
            case 1:
             printf("Manager\n"); 
             break;
            case 2: 
            printf("Developer\n");
             break;
            case 3: 
            printf("Designer\n");
             break;
            default:
             printf("Unknown role\n");
              break;
        }

        printf("Performance Rating: %d\n", performanceRating);

        printf("Performance Evaluation: ");
        if (performanceRating >= 4)
            printf("Excellent performance!\n");
        else if (performanceRating >= 2)
            printf("Satisfactory performance.\n");
        else
            printf("Poor performance.\n");
    }
}
    

