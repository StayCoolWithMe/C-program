#include<stdio.h>

int main() {
    int choice;
    char name[20];
    int age;

    printf("\nManagement System Menu\n");
    printf("1. Add Employee\n");
    printf("2. Remove Employee\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter employee name: ");
            scanf("%s", name);
            printf("Enter employee age: ");
            scanf("%d", &age);
            printf("Employee added successfully.\n");
            break;
        case 2:
            printf("Enter employee name to remove: ");
            scanf("%s", name);
            printf("Employee removed successfully.\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
