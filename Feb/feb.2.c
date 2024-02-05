#include<stdio.h>
int main()
{
    char name[20];
    int age;
    float score;
    char grade;
    printf("Enter your name: ");
    scanf("%s",name);
    printf("Enter your age: ");
    scanf(" %d",&age);
    printf("Enter your score: ");
    scanf(" %f",&score);
   if(score>=50)
   {
    grade='D';
   }
   else if(score>=75)
   {
    grade='C';
    ;
   }
   else if (score>=85)
   {
    grade='B';
   }
   else if (score>=90)
   {
    grade='A';

   }
   else 
   {
    grade='F';
   }
    printf("Student Grade :%c",grade);
}