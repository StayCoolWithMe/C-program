#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int student_index=0;
int choice;

struct student {
    char name[50];
    int age;
    char sex[50];
    char attempt[50];
};

struct student students[50];

void attendent();
void output();
void input();

int main() {
    while(1) {
        printf("1.Input\n2.Attendance\n3.Output\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                input();
                break;
            case 2:
                attendent();
                break;
            case 3:
                output();
                break;
            default:
                printf("Invalid choice, Please enter a valid one\n");
        }
    } 
}

void input() {
    while(1) {
        printf("Enter the student name:(0 to stop)");
        scanf("%s", students[student_index].name);
        if(strcmp(students[student_index].name, "0") == 0) {
            break;
        }
        printf("Enter the student sex(M/F)");
        scanf("%s", students[student_index].sex);
        printf("Enter the student age");
        scanf("%d", &students[student_index].age);
        printf("Did he/she attempt class(Y/N)");
        scanf("%s", students[student_index].attempt); 
        student_index++;
    }
}

void attendent() {
    for(int i=0; i<student_index; i++) {
        if(strcmp(students[i].attempt, "Y") == 0 || strcmp(students[i].attempt, "y") == 0) {
            printf("Attempted\n");
        } else if(strcmp(students[i].attempt, "N") == 0 || strcmp(students[i].attempt, "n") == 0) {
            printf("Absent\n");
        }
    }
}

void output() {
    printf("Attempted students:\n");
    printf("Name\tSex\n");
    for(int i=0; i<student_index; i++) {
        if(strcmp(students[i].attempt, "Y") == 0 || strcmp(students[i].attempt, "y") == 0) {
            printf("%s\t%s\n", students[i].name, students[i].sex);
        }
    }
    printf("Absent students:\n");
    printf("Name\tSex\n");
    for(int i=0; i<student_index; i++) {
        if(strcmp(students[i].attempt, "N") == 0 || strcmp(students[i].attempt, "n") == 0) {
            printf("%s\t%s\n", students[i].name, students[i].sex);
        }
    }
}
