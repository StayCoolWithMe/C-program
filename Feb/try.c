#include <stdio.h>

int main() {
    float basicSalary, allowance, additionalAllowance = 0, netSalary;
    char grade, gender;
    int age;
    printf("Enter the basic salary: ");
    scanf("%f", &basicSalary);
    printf("Enter the grade (A, B, or C): ");
    scanf(" %c", &grade);
    printf("Enter the gender (M for male, F for female): ");
    scanf(" %c", &gender);

    printf("Enter the age: ");
    scanf("%d", &age);
    allowance = 0.1 * basicSalary;

    switch(grade) {
        case 'A':
            additionalAllowance = 500;
            break;
        case 'B':
            additionalAllowance = 300;
            break;
        case 'C':
            additionalAllowance = 100;
            break;
        default:
            printf("Error: Invalid grade entered.\n");
           
    }

   

   
    if (gender == 'M' && age >= 40)
 {
        additionalAllowance += 1000;
    } 
else if
 (gender == 'F' && age >= 35) 
{
        additionalAllowance += 800;
    }



    netSalary = basicSalary + allowance + additionalAllowance;

  
    printf("\nBasic Salary: $%.2f\n", basicSalary);
    printf("Allowance: $%.2f\n", allowance);
    printf("Additional Allowance: $%.2f\n", additionalAllowance);
    printf("Net Salary: $%.2f\n", netSalary);

 
}