
#include <stdio.h>

    int main()
{
    int ID;
    char name[20];
    float salary;
    int choice;

    printf("\nMenu");
    printf("\n1. Add employee");
    printf("\n2. View employee");
    printf("\n3. Exit");

    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter employee name: ");
            scanf("%s", name);
            printf("Enter employee ID: ");
            scanf("%d", &ID);
            printf("Enter salary: ");
            scanf("%f", &salary);
            printf("\nEmployee added successfully\n");
            break;
        case 2:
            printf("\nName: %s\n", name);
            printf("ID: %d\n", ID);
            printf("Salary: %.2f\n", salary);
            break;
        case 3:
            printf("\nExiting...\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
