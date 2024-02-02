#include<stdio.h>

int main()
{
char name[20];
char sex;
char dateofbirth[20];
char address[50];
int ID;
char department[20];
float salary;
printf("Enter your name");
scanf("%s",name);
printf("Enter your Gender");
scanf(" %c",&sex);
printf("Enter your address");
scanf("%s",address);
printf("ID");
scanf("%i",&ID);
printf("Enter your date of birth");
scanf("%s",dateofbirth);
printf("Department");
scanf(" %s",department);
printf("Salary");
scanf(" %f",&salary);
printf("\nName %s",name);
printf("\n Gendere %c",sex);
printf("\n dateofbirth %s",dateofbirth);
printf("\n address %s",address);
printf("\n Department %s",department);
printf("\n salary %.0f ",salary);






}