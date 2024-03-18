#include <stdio.h>

int main() {
    int numStudents;
    int ID[numStudents];
    float salary[numStudents];
    char name[numStudents][50];
    char gender[numStudents];
    char statement[numStudents][50];

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    while (numStudents <= 0) {
        printf("Invalid number of students. Please enter a valid one: ");
        scanf("%d", &numStudents);
    }


    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Enter the ID for student %d: ", i + 1);
        scanf("%d", &ID[i]);

        printf("Enter the name for student %d: ", i + 1);
        scanf("%s", name[i]);

        printf("Enter the gender for student %d (M/F): ", i + 1);
        scanf(" %c", &gender[i]);

        printf("Enter the salary for student %d: ", i + 1);
        scanf("%f", &salary[i]);

        printf("Enter the comment for student %d: ", i + 1);
        scanf(" %[^\n]", statement[i]);
    }
    printf("\nStudent Information:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Student ID: %d\n", ID[i]);
        printf("Name: %s\n", name[i]);
        printf("Gender: %c\n", gender[i]);
        printf("Salary: %.2f\n", salary[i]);
        printf("Statement: %s\n", statement[i]);
    }
}


