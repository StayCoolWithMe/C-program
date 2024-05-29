#include<stdio.h>
#include<stdlib.h>
float widght;
float hight;
float result=0;
int choice;
float celsius;
float fahrenheit;
float celsius_result=0;
float fahrenheit_result=0;
float calculate(float widght,float hight);
float fahrenheit1(float fahrenheit);
float celsius1(float celsius);
int main()
{
do
{
printf("1.Find the area\n");
printf("2.Convert Celsius to fahrenheit\n");
printf("3.Convert Fahrenheit to Celsius\n");
printf("4.Exit\n");
printf("what's your choice");
scanf("%d",&choice);
switch(choice)
{
    case 1:
    {
            printf("\nEnter the widght");
            scanf("%f",&widght);
            printf("Enter the hight");
            scanf("%f",&hight);
            result=calculate(widght,hight);
            printf("The area will be %.0f",result);
    break;
    }
    case 2:
    {
            printf("Enter celsius value:");
            scanf("%f",&celsius);
            celsius_result=celsius1(celsius);
            printf("%f Celsius is equal to %.0f Fahrenheit",celsius,celsius_result);
    break;
    }
    case 3:
    {
            printf("Enter fahrenheit value:");
            scanf("%f",&fahrenheit);
            celsius_result=fahrenheit1(fahrenheit);
            printf("%f fahrenheit is equal to %.0f celsius",fahrenheit,fahrenheit_result);
    break;
    }
    case 4:
    {
        exit(0);
    }
    default :
    {
        printf("INVALID INTENTION");
    }
}
}while(choice!=4);
}
float calculate(float widght,float hight)
{
  
    return widght*hight;
}
float celsius1(float celsius)
{
    return (9/5*celsius)+32;
}
float fahrenheit1(float fahrenheit)
{
    return (5/9)*(fahrenheit-32);
}
