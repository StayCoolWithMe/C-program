#include<stdio.h>
int main()
{
    char name[20][50];
    int age[20];
    char address[20][50];
    float salary[20];
    int choice;
    float new_salary[20];
    int year_of_retire;
    int id[20];
    

    for(int i=0; i<3; i++)
    {
        printf("Enter your name: ");
        scanf("%s", name[i]);
        printf("Enter your age: ");
        scanf("%d", &age[i]);
        printf("Enter your ID: ");
        scanf("%d", &id[i]);
        printf("Enter your current salary: ");
        scanf("%f", &salary[i]);
        printf("Enter your address: ");
        scanf("%s", address[i]);
    }

    printf("\nMenu\n");
    printf("1. Update salary\n");
    printf("2. Year of retirement\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        int searchID;
        printf("Enter your ID to search: ");
        scanf("%d", &searchID);

        int found = 0; 
        for(int i = 0; i < 3; i++)
        {
            if(searchID == id[i])
            {
                printf("ID found\n");
                printf("Enter your new salary: ");
                scanf("%f", &new_salary[i]);
                salary[i] = new_salary[i];
                printf("Salary updated successfully.\n");
                found = 1; 
                break; 
            }
        }
        if (!found)
        {
            printf("ID not found\n");
        }
    }
    else if(choice == 2)
    {
        for(int i = 0; i < 3; i++)
        {
            if(age[i] > 65)
            {
                printf("Dear %s, it's time for you to retire.\n", name[i]);
            }
            else
            {
                year_of_retire = 65 - age[i];
                printf("Dear %s, you are %d years away from your year of retirement.\n", name[i], year_of_retire);
            }
        }
    }
    else
    {
        printf("Invalid choice.\n");
    }
}






