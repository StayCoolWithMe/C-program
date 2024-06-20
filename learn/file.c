#include <stdio.h>

struct Employee {
    char name[20];
    int id;
    char gender;
    float salary;
};

int main()
{
    struct Employee employee;
    FILE *fp;
    
    fp = fopen("file.txt", "w");

    printf("Enter employee name: ");
    scanf("%s", employee.name);

    printf("Enter employee id: ");
    scanf("%d", &employee.id);

    printf("Enter employee gender (M/F): ");
    scanf(" %c", &employee.gender);

    printf("Enter employee salary: ");
    scanf("%f", &employee.salary);

    fprintf(fp, "Name: %s\nID: %d\nGender: %c\nSalary: %.2f\n", employee.name, employee.id, employee.gender, employee.salary);

    fclose(fp);
}