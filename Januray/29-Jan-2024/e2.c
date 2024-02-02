#include<stdio.h>

int main() {
    char statement[20];
    int gpaGrade;  // Changed the data type to int for GPA grade
    float age;
    int experience;  // Changed the data type to int for job experience
    float salary;

    printf("Enter Your Name: ");
    scanf("%s", statement);

    printf("Enter Your GPA Grade: ");
    scanf("%d", &gpaGrade);  // Changed the data type to int for GPA grade

    printf("Enter Your age: ");
    scanf(" %f", &age);

    printf("Job experience: ");
    scanf(" %d", &experience);  // Changed the data type to int for job experience

    printf("Salary: ");
    scanf(" %f", &salary);

    if (age >= 25 && experience >= 3) {
        printf("Available to enroll\n");

        if (experience >= 5) {
            salary = salary + salary * 0.2;
            printf("The total salary will be: %f\n", salary);
        }
        else {
            printf("The total salary will be: %f\n", salary);
        }

        if (gpaGrade == 4) {
            salary = salary + salary * 0.1;
            printf("The total salary will be: %f\n", salary);
        }
         else {
            printf("The total salary will be: %f\n", salary);
        }
    } else {
        printf("Not available to enroll\n");
    }

    return 0;
}
