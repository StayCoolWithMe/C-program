#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int choice;
int studentIndex = 0;
void input();
void output();
float calculator(int index);
void mark_student();
float higscore = -1; 
float Wholegrade;
float overall[100];
struct information
{
    char name[100];
    int age;
    float Mathgrade;
    float Englishgrade;
    int id;
    float Physicgrade;
};
struct information information[100];

int main()
{
    FILE *fp;
    fp=fopen("test65.txt","a+");
    srand(time(NULL)); //1
    while (1)
    {
        printf("1.Input\n2.Output\n3.Mark Student\n4.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            input();
            break;
        case 2:
            output();
            break;
        case 3:
            mark_student();
            break;
        case 4: 
        for (int i = 0; i < studentIndex; i++)
        {     
            fprintf(fp, "%-20s\t\t%-10d\t\t%-5d\t\t%-5.0f\t\t%-5.0f\t\t%-5.0f\t\t%-5.2f\n", information[i].name, information[i].id, information[i].age, information[i].Mathgrade, information[i].Englishgrade, information[i].Physicgrade, overall[i]);

        }
        fclose(fp);
        exit(0);
        default:
            printf("Invalid,please enter another one\n"); 
            break;
        } 
    }
}
void input()
{
    while (1)
    {
        printf("Enter Your Name(0 to stop):");
        scanf("%s", information[studentIndex].name);
        if (strcmp(information[studentIndex].name, "0") == 0)
        {
            break;
        }
        printf("Enter Your Age:");
        scanf("%d", &information[studentIndex].age);

        int randomnumber = rand();
        
        information[studentIndex].id = randomnumber;
        printf("The student ID is: %d\n", information[studentIndex].id);
        printf("Enter Your Grade for the following subjects Math/English/Physic(1-100):");
        scanf("%f %f %f", &information[studentIndex].Mathgrade, &information[studentIndex].Englishgrade, &information[studentIndex].Physicgrade);
        overall[studentIndex] = calculator(studentIndex);
        studentIndex++;
    }
}

float calculator(int index)
{
    return (information[index].Mathgrade + information[index].Englishgrade + information[index].Physicgrade) / 3;
}

void output()
{
    printf("Detail:\n");
    printf("Name\tID\tAge\tMath\tEnglish\tPhysic\tOverll\n");
    for (int i = 0; i < studentIndex; i++)
    {
        printf("%s\t%d\t%d\t%.0f\t%.0f\t%.0f\t%.0f\n", information[i].name, information[i].id, information[i].age, information[i].Mathgrade, information[i].Englishgrade, information[i].Physicgrade, overall[i]);
    }
    for (int i = 0; i < studentIndex; i++)
    {
        if (overall[i] < 60)
        {
            printf("The student \033[1;31m%s\033[0m has been failed\n", information[i].name);
        }
    }

    printf("Top student:\n");
    for (int i = 0; i < studentIndex; i++)
    {
        if (overall[i] > higscore) 
        {
            higscore = overall[i];
        }
    }
    for (int i = 0; i < studentIndex; i++)
    {
        if (overall[i] == higscore)
        {
            printf("The student with the highest score is %s with overall score %.0f\n", information[i].name, overall[i]);
        }
    }
    float sum = 0;
    for (int i = 0; i < studentIndex; i++)
    {
        sum += overall[i];
    }
    Wholegrade = sum / studentIndex; 
    printf("The class overall grade is :%.0f\n", Wholegrade);
}

void mark_student()
{
    int searchID;
    printf("Enter the student ID to search: ");
    scanf("%d", &searchID);

    for (int i = 0; i < studentIndex; i++)
    {
        if (information[i].id == searchID)
        {
            printf("The student \033[1;31m%s\033[0m has been marked\n", information[i].name);
            return; 
        }
    }
    printf("Student ID not found.\n");
}
