#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define Max_Student 20
#define Max_Name_Length 20
#define Max_Comment_Length 50

int main() {
    char name[Max_Student][Max_Name_Length];
    int ID[Max_Student];
    char comment[Max_Student][Max_Comment_Length];
    int choice;
    int studentnumber=0;
    int currentstudent=0;
    int studentindex=0;

    printf("Enter the number of students: ");
    scanf("%d", &studentnumber);

    while(studentnumber < 0 || studentnumber > Max_Student) {
        printf("Unacceptable number. Please enter a valid one: ");
        scanf("%d", &studentnumber);
    }

    for(int i = 0; i < studentnumber; i++) {
        ID[i] = i+1;
    }

    do {
        printf("\n1. Add student\n");
        printf("2. Remove student\n");
        printf("3. Enter comment for the student\n");
        printf("4. Student status\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(studentindex < studentnumber) {
                    printf("Enter ID for student %d: ", currentstudent+1);
                    scanf("%d", &ID[currentstudent]);
                    printf("Enter the name to add for student %d: ", currentstudent+1);
                    scanf("%s", name[studentindex]);
                    studentindex++;
                } else {
                    printf("Maximum number of students reached.\n");
                }
                break;

            case 2:
                if(studentindex > 0) {
                    int removestudent;
                    printf("Enter the student number to remove (1-%d): ", studentindex);
                    scanf("%d", &removestudent);
                    if(removestudent > 0 && removestudent <= studentindex) {
                        for(int i = removestudent-1; i < studentindex-1; i++) {
                            strcpy(name[i], name[i+1]);
                            studentindex--;
                        }
                        printf("Student removed successfully.\n");
                    } else {
                        printf("No student to remove.\n");
                    }
                }
                break;

            case 3:
                printf("Enter the comment for student %d: ", currentstudent+1);
                scanf(" %[^\n]s", comment[currentstudent]);
                break;

            case 4:
                printf("\nStudent status:\n");
                for(int i = 0; i < studentindex; i++) {
                    printf("Student %d: ID  %d, Name  %s, Comment  %s\n", i+1, ID[i], name[i], comment[i]);
                }
                break;

            case 5:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid choice.\n");
                break;
        }
    } while(choice != 5);

}
