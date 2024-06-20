#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int student_index=0;
int choice;
float answer;
float highscore=0;
float lowestscore=100;
struct student
{
    char name[999];
    int id;
    char gender[999];
    float Math;
    float English;
    float ENVs;
    float history;
    float overallscore;
};
struct student student[999];
void input();
void output();
float calculator_function(float Math, float English, float ENVs, float history); 
int main()
{
     srand(time(NULL));
    while(1)
    {
        printf("1.Input/2.Output\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            input();
            break;
            case 2:
            output();
            break;
            default:
            printf("Invalid,please enter another one:");
            scanf("%d", &choice);
            break;
        }

    }
}
void input()
{
    while(1)
    {
        printf("Student Name(0 to stop):");
        scanf("%s", student[student_index].name);
        if(strcmp(student[student_index].name,"0")==0)
        {
            break;
        }
        int randomnumber=rand();//This code create number
        student[student_index].id = randomnumber; 
        printf("Student ID:%d\n", student[student_index].id);
        printf("Student gender:");
        scanf("%s", student[student_index].gender);
        printf("Please enter %s score for the folliwing subject(1-100)(Math,English,ENVs,history)",student[student_index].name);
        scanf("%f %f %f %f",&student[student_index].Math,&student[student_index].English,&student[student_index].ENVs,&student[student_index].history);
        if(student[student_index].Math>100 || student[student_index].Math<1 ||student[student_index].English>100 || student[student_index].English<1 ||student[student_index].ENVs>100 || student[student_index].ENVs<1 ||student[student_index].history>100 || student[student_index].history<1)
        {
            printf("Invalid,please enter a valid one(1-100):");
            scanf("%f %f %f %f", &student[student_index].Math, &student[student_index].English, &student[student_index].ENVs, &student[student_index].history);
        }
      student[student_index].overallscore= calculator_function(student[student_index].Math,student[student_index].English,student[student_index].ENVs,student[student_index].history);
    student_index++;
    }
}
float calculator_function(float Math, float English, float ENVs, float history)
{   
    
    return (Math+English+ENVs+history)/4;
    
}
void output()
{
    while(1)
    {
        printf("Student who are below average:\n");
        printf("Student Name\tStudent gender\tOverall grade\n");
        for(int i=0;i<student_index;i++)
        {
            if(student[i].overallscore<60)
            {
            printf("%s\t\t%s\t\t%.0f\n",student[i].name,student[i].gender,student[i].overallscore);
            }
        }
         printf("Student who are above average:\n");
        printf("Student Name\tStudent gender\tOverall grade\n");
        for(int i=0;i<student_index;i++)
        {
            if(student[i].overallscore>=60)
            {
            printf("%s\t\t%s\t\t%.0f\n",student[i].name,student[i].gender,student[i].overallscore);
            }
        }
        
        //Highest score
        for(int i=0;i<student_index;i++)
        {
        if(student[i].overallscore==highscore)
        {   
                printf("The student with the highest score is %s with an overall score of %.2f\n", student[i].name, student[i].overallscore);        
        }
        }
        //Lowest score 
         for(int i=0;i<student_index;i++)
        {
        if(student[i].overallscore==lowestscore)
        {
            
                printf("The student with the lowest score is %s with an overall score of %.2f\n", student[i].name, student[i].overallscore);        
        }
        }

    }
}
