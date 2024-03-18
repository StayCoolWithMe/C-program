#include<stdio.h>
int main() {
    int ID[50];
    float salary[50];
    char name[50][50];
    char gender[50];
    char statement[50][50];
    int numofstudent;
    int choice;

    printf("Enter the number of students: ");
    scanf("%d", &numofstudent);

    while(numofstudent < 0) {
        printf("Invalid number of students. Please enter a valid one: ");
        scanf("%d", &numofstudent);
    }
    //to create a number of 50 people
    for(int i = 0; i < numofstudent; i++) {
        ID[i] = i + 1;
    }

    do {
        printf("\n1. Enter the student ID\n");
        printf("2. Enter the student name\n");
        printf("3. Enter the student gender\n");
        printf("4. Enter the student salary\n");
        printf("5. Enter the comment for the student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        //we use the -1 to make the code more dynamic

        switch(choice) {
            case 1:
                printf("Enter the ID for student %d: ", numofstudent);
                scanf("%d", &ID[numofstudent - 1]); 
                break;
            case 2:
                printf("Enter the name for student %d: ", numofstudent);
                scanf("%s", name[numofstudent - 1]);
                break;
            case 3:
                printf("Enter the gender for student %d: ", numofstudent);
                scanf(" %c", &gender[numofstudent - 1]); 
                break;
            case 4:
                printf("Enter the salary for student %d: ", numofstudent);
                scanf("%f", &salary[numofstudent - 1]);
                break;
            case 5:
                printf("Enter the comment for student %d: ", numofstudent);
                scanf(" %[^\n]s", statement[numofstudent - 1]); 
                break;
            case 6:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6 && numofstudent > 0);

    printf("\nStudent Information:\n");
    for (int i = 0; i < numofstudent; i++) {
        printf("\nStudent ID: %d\n", ID[i]);
        printf("Name: %s\n", name[i]);
        printf("Gender: %c\n", gender[i]);
        printf("Salary: %.2f\n", salary[i][0]);
        printf("Statement: %s\n", statement[i]);
    }
    
}





    




