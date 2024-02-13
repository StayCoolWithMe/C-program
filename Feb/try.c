#include<stdio.h>
int main()
{
  char name[25];
  int age;
  float salary;
  char new[10]="Newcomer";
  printf("Enter your Name");
  scanf("%c",name);
   printf("\nEnter your age");
  scanf(" %d",&age);
   printf("\nEnter your salary");
  scanf(" %f",&salary);  
  printf("hello %s",new);
  switch(new)
  {
    case 1 :
    new=New;
    printf("You have been selected");
    break;
    case 2 :
    new=Old;
    printf("You have have been disqualified");
    break;
  }
  printf("Hello %c",name);
  printf("Your salary is %f",salary);
  printf("Your age is %d",age);
}