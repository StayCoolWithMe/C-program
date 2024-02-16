#include<stdio.h>
int main()
{
  char operator;
  float num1;
  float num2;
  float total;
  printf("Please enter operator");
  scanf("%c",&operator);
  printf("Please enter number 1:\n");
  scanf(" %f",&num1);
  printf("Please enter number 2:\n");
  scanf(" %f",&num2);
  switch(operator)
  {
    case '+':
    total=num1+num2;
    break;
     case '-':
    total=num1-num2;
    break;
     case '*':
    total=num1*+num2;
    break;
     case '/':
    total=num1/num2;
    break;
    default :
    printf("please enter valid operator");
    break;
  }
  printf("The final result %.2f",total);

  


}