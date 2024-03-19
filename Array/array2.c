#include<stdio.h>

#define Max_Student 50
#define Max_Name_Lenght 50
#define Max_Statement_Lenght 50

int main()
{
    int ID[Max_Student];
    char name[Max_Student][Max_Name_Lenght];
    char gender[Max_Student][Max_Name_Lenght];
    char statement[Max_Student][Max_Statement_Lenght];
    int choice;
    float salary[Max_Student];
    int numofstudent = 0; 
    int currentstudent = 0;

    for(int i = 0; i < Max_Student; i++)
    {
        ID[i] = i + 1;
    }

    printf("Enter number of students: ");
    scanf("%d", &numofstudent);

    while(numofstudent <= 0 || numofstudent > Max_Student)
    {
        printf("Invalid number of students. Please enter a valid number (1-%d): ", Max_Student);
        scanf("%d", &numofstudent);
    }

    do
    {
        printf("1. Enter ID\n");
        printf("2. Enter Name\n");
        printf("3. Enter gender\n");
        printf("4. Enter salary\n");
        printf("5. Enter statement\n");
        printf("6. Move to the next student\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the ID for student %d: ", currentstudent + 1);
                scanf("%d", &ID[currentstudent]);
                break;
            case 2:
                printf("Enter the name for student %d: ", currentstudent + 1);
                scanf("%s", name[currentstudent]);
                break;
            case 3:
                printf("Enter the gender for student %d: ", currentstudent + 1);
                scanf("%s", gender[currentstudent]);
                break;
            case 4:
                printf("Enter salary for student %d: ", currentstudent + 1);
                scanf("%f", &salary[currentstudent]);
                break;
            case 5:
                printf("Enter statement for student %d: ", currentstudent + 1);
                scanf("%[^\n]s", statement[currentstudent]);
                break;
            case 6:
                if(currentstudent < numofstudent - 1)
                {
                    currentstudent++;
                }
                else
                {
                    printf("Already at the last student.\n");
                }
                break;
            case 7:
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 7);

    printf("\nStudent Information:\n");
    for(int i = 0; i < numofstudent; i++)
    {
        printf("Student ID: %d\n", ID[i]);
        printf("Student name: %s\n", name[i]);
        printf("Student gender: %s\n", gender[i]);
        printf("Student salary: %.2f\n", salary[i]);
        printf("Student statement: %s\n\n", statement[i]);
    }
}
