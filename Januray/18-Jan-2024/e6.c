#include<stdio.h>
int main()
{

    char name[20];
    printf("Enter your name");
    scanf("%s",name);
     float heigh;
    printf("Enter your heigh");
    scanf("%f",&heigh);
    float weight;
    printf("Enter your weight");
    scanf("%f",&weight);
    char sex;
    printf("sex:");
    scanf("%s",&sex);
    float num1;
    printf("Enter your salary for year 1");
    scanf("%f",&num1);
    float num2;
    printf("Enter your salary for year 2");
    scanf("%f",&num2);
    float num3;
    num3=num1+num2;
    
   
    printf("Total of salary earn in the previous 2 years %.2f",num3);
    printf("\nnum3 %f",num3);
    printf("\nName: %s",name);
    printf("\nHeight: %.2f",heigh);
    printf("\nweight:%f",weight);
    printf("\nnum1 %f",num1);
    printf("\nnum2 %f",num2);
    
    
}