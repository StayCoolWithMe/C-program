#include<stdio.h>
int main()
{
    char name[20];
    int ID;
    int choice;
    int totalstudent;
    char opinion[2];
    int age;

    printf("Enter the total students: ");
    scanf("%d", &totalstudent);

    while(totalstudent < 1)
    {
        printf("Invalid input ");
        scanf("%d", &totalstudent);
    }

    for(int i = 0; i < totalstudent; i++)
    {
        printf("Did you graduate from high school (y/n): ");
        scanf(" %c", opinion);

        switch(opinion[0])
        {
            case 'y':
            {
                printf("1. New Semester Register\n");
                printf("2. Age restriction\n");
                printf("3. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if(choice == 1)
                {
                    printf("Enter your name: ");
                    scanf("%s", name);
                    printf("Enter your ID: ");
                    scanf("%d", &ID);
                }
                else if(choice == 2)
                {
                    printf("Enter your age: ");
                    scanf("%d", &age);

                    if(age < 1)
                    {
                        printf("Invalid age\n");
                    }
                    else if(age > 18)
                    {
                        printf("You are ineligible to register\n");
                    }
                    else
                    {
                        printf("You are too young\n");
                    }
                }
                else if(choice == 3)
                {
                    printf("Have a good day\n");
                }
                break;
            }
            case 'n':
            {
                printf("You should'nt be here\n");
                break;
            }
            default:
                printf("Invalid choice\n");
        }
    }
}
