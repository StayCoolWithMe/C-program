#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int choice1;
int opt;
int student_index = 0;
int teacher_index = 0;
int choice3;
int highlight;
int search;
int search1;
int popotion;
char coment[100][999];

struct student {
    char name[100][999];
    int id[999];
    char sex[999];
    int teacherid[999];
};

struct teacher {
    char name[100][999];
    int id[999];
    char sex[999];
};

struct student students;
struct teacher teachers;

void input();
void output();
void mark();
void class();

int main() {
    while (1) {
        printf("1.Input\n2.Output\n3.Additional coment\n4.Class\n");
        printf("Enter your choice (0 to stop): ");
        scanf("%d", &choice1);
        if (choice1 == 0) { 
            break;
        }
        switch (choice1) {
            case 1:
                input();
                break;
            case 2:
                output();
                break;
            case 3:
                mark();
                break;
            case 4:
                class();
                break;

            default:
                printf("Invalid choice, please enter another one\n");
                break;
        }
    }
}

void input() {
    while (1) {
        printf("1.Student input\n2.Professor input\n");
        printf("Enter your choice (0 to stop): ");
        scanf("%d", &opt);
        if (opt == 0) { 
            break;
        }
        switch (opt) {
            case 1:
                printf("Enter your Name (0 to stop): ");
                scanf("%s", students.name[student_index]);
                if (strcmp(students.name[student_index], "0") == 0) { 
                    break;
                }
                printf("Enter your ID: ");
                scanf("%d", &students.id[student_index]);
                printf("Enter your Sex (M/F): ");
                scanf(" %c", &students.sex[student_index]);
                printf("Class of TeacherID:");
                scanf("%d",&students.teacherid[student_index]);
                student_index++;
                break;
            case 2:
                printf("Enter your Name (0 to stop): ");
                scanf("%s", teachers.name[teacher_index]);
                if (strcmp(teachers.name[teacher_index], "0") == 0) {
                    break;
                }
                printf("Enter your ID: ");
                scanf("%d", &teachers.id[teacher_index]);
                printf("Enter your Sex (M/F): ");
                scanf(" %c", &teachers.sex[teacher_index]);
                teacher_index++;
                break;
            default:
                printf("Invalid choice, please enter another one\n");
                break;
        }
    }
}
void output() {
    printf("Detail (1.Student / 2.Teacher): ");
    scanf("%d", &choice3);
    switch (choice3) {
        case 1:
            printf("Student Name\tID\tSex\n");
            for (int j = 0; j < student_index; j++) {
                printf("%s\t\t%d\t%c\n", students.name[j], students.id[j], students.sex[j]);
            }
            break;
        case 2:
            printf("Teacher Name\tID\tSex\n");
            for (int j = 0; j < teacher_index; j++) {
                printf("%s\t\t%d\t%c\n", teachers.name[j], teachers.id[j], teachers.sex[j]);
            }
            break;
        default:
            printf("Invalid choice, please enter another one\n");
            break;
    }
}
void mark()
{
   printf("Which popotion you want to mark(1.Student/2.Proffessor)\n");
    scanf("%d",&popotion);
    switch(popotion)
    {
        case 1:
        while(1)
        {
            printf("Enter Student ID to search");
            scanf("%d",&search);
            int found1=0;
            for(int i=0;i<student_index;i++)
            {
            if(search==students.id[i])
            {
                printf("Write a mark for this studebt:");
                scanf("%s", coment[i]);
                found1=1;
                break;
            }
            }
            if(!found1)
            {
                printf("Invalid student ID,please try again");
                scanf("%d",&search);
            }
            else 
            {
                break;
            }
        }
        break;
        case 2:
            while(1)
        {
            printf("Enter Proffessor ID to search");
            scanf("%d",&search);
            int found2=0;
            for(int i=0;i<teacher_index;i++)
            {
            if(search==teachers.id[i])
            {
                printf("Write a mark for this teacher:");
                scanf("%s", coment[i]);
                found2=1;
                break;
            }
            }
            if(!found2)
            {
                printf("Invalid teacher ID,please try again");
                scanf("%d",&search);

            }
            else {
                break;
            }
            }
              break;
            default :
            printf("Invalid choice,please select another one");
            scanf("%d",&popotion);
        }

    }
void class() {
    printf("Classroom of student:\n");
    for (int i = 0; i < teacher_index; i++) {
        int count = 0; // Initialize a counter for each teacher
        printf("Teacher %d has the following students:\n", teachers.id[i]);
        for (int j = 0; j < student_index; j++) {
            if (students.teacherid[j] == teachers.id[i]) {
                printf(" - Student ID: %d\n", students.id[j]);
                count++;
            }
        }
        printf("Total students taught by teacher %d: %d\n", teachers.id[i], count);
    }
}




