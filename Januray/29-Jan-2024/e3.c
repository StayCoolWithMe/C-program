#include<stdio.h>
int main()
{
    char name[20];
    int age;
    char occupation[20];
    float job_experince;
    char department[20];
    float salary;
    printf("Enter Your Name: ");
    scanf("%s",name);
    printf("Enter Your Age: ");
    scanf(" %d",&age);
    printf("Occupation: ");
    scanf("%s",occupation);
    printf("Enter Your Job Experince: ");
    scanf(" %f",&job_experince);
    printf("Enter Your Department: ");
    scanf("%s",department);
    printf("Enter Your Salary: ");
    scanf(" %f",&salary);

if(job_experince >=3)
{
    salary=salary+((salary*20)/100);
    if(age>=45)
    {
        salary=salary+((salary*10)/100);

    }
}
printf("The total salary wil be: %f",salary);

}