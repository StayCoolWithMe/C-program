#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max_employee 1000
#define Max_Name_Length 200

int main()
{
    char name[Max_employee][Max_Name_Length];
    int ID[Max_employee];
    int choice;
    int currentemployee = 0;
    char gender[Max_employee];
    int empployeenumber = 0;
    char department[Max_employee][Max_Name_Length];
    float salary[Max_employee];
    float newsalary;
    char comment[200];

    printf("Enter the number of employees: ");
    scanf("%d", &empployeenumber);

    while(empployeenumber < 1 || empployeenumber > Max_employee)
    {
        printf("INVALID, PLEASE ENTER AN ACCEPTABLE NUMBER: ");
        scanf("%d", &empployeenumber);
    }

    for(int i = 0; i < empployeenumber; i++)
    {
        ID[i] = i + 1;
    }

    printf("HR employee management\n\n");

    do
    {
        MainMenu:
        printf("1. Recruitment\n");
        printf("2. Administration\n");
        printf("3. Performance Reviews\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                if(currentemployee < Max_employee)
                {
                    if(currentemployee < 500)
                    {
                        printf("Enter the name for employee %d to add: ", currentemployee + 1);
                        scanf("%s", name[currentemployee]);
                        printf("Enter your ID: ");
                        scanf("%d", &ID[currentemployee]);
                        printf("Enter your gender (M/F): ");
                        scanf(" %c", &gender[currentemployee]);
                        printf("Enter your department: ");
                        scanf("%s", department[currentemployee]);
                        printf("Enter your salary: ");
                        scanf("%f", &salary[currentemployee]);
                        currentemployee++;
                    }
                    else
                    {
                        printf("NO NEED TO ADD EMPLOYEE\n");
                    }
                }
                else
                {
                    printf("MAXIMUM EMPLOYEE LIMIT REACHED\n");
                }
                break;
            }
            case 2:
            {
                if (currentemployee > 0)
                {
                    int adminChoice;
                    int searchID;
                    printf("\nAdministration Menu\n");
                    printf("1. Update Employee Information\n");
                    printf("2. Delete Employee\n");
                    printf("3. Return to Main Menu\n");
                    printf("Enter your choice: ");
                    scanf("%d", &adminChoice);
                    switch(adminChoice)
                    {
                        case 1:
                        {
                            printf("Enter the employee ID to update: ");
                            scanf("%d", &searchID);
                            int found = 0;
                            for(int i = 0; i < currentemployee; i++)
                            {
                                if(searchID == ID[i])
                                {
                                    printf("Hello %s, your current salary is %.2f\n", name[i], salary[i]);
                                    printf("Enter the new salary: ");
                                    scanf("%f", &newsalary);
                                    salary[i] = newsalary;
                                    found = 1;
                                    break;
                                }
                            }
                            if(!found)
                            {
                                printf("EMPLOYEE NOT FOUND\n");
                            }
                            break;
                        }
                        case 2:
                        {
                            int removeemployee;
                            printf("Enter number (1-%d) to remove: ", currentemployee);
                            scanf("%d", &removeemployee);
                            if(removeemployee > 0 && removeemployee <= currentemployee)
                            {
                                for(int i = removeemployee - 1; i < currentemployee - 1; i++)
                                {
                                    strcpy(name[i], name[i+1]);
                                    ID[i] = ID[i+1];
                                     salary[i] = salary[i+1];
                                }
                                printf("Remove successfully\n");
                                currentemployee--;
                            }
                            else
                            {
                                printf("NO employee to remove\n");
                            }
                            break;
                        }
                        case 3:
                            break;
                        default:
                            printf("INVALID CHOICE\n");
                    }
                }
                else
                {
                    printf("No employees added yet.\n");
                }
                break;
            }
            case 3:
            {
                if (currentemployee > 0)
                {
                    printf("Leave a performance review for employee %s: ", name[currentemployee-1]);
                    scanf(" %[^\n]", comment);
                }
                else
                {
                    printf("No employees added yet.\n");
                }
                break;
            }
            case 4:
            {
                exit(0);
            }
            default:
            {
                printf("INVALID CHOICE\n");
            }
        }
    }
    while(1);
}
