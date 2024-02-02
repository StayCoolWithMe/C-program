#include<stdio.h>
int main()
{
    char statment[20];
    int num;
    char sex;
    char statement1[50];
    char statement2[50];
    float salary;
    printf("Enter Your Name:");
    scanf("%s",statment);
    printf("Enter Your Age:");
    scanf(" %d",&num);
    printf("Gender:");
    scanf(" %c",&sex);
    printf("Occupation:");
    scanf(" %s",statement1);
     printf("Job experince:");
    scanf(" %s",statement2);
    printf("Input Your Salary:");
    scanf("%f",&salary);
    if(num>=45)
    {
        salary = salary + (salary * (10/100));
        printf("The total salary will be %.2f ", salary);
    
    }
    else
    {
        printf("The totoal salary will be");
    }
}