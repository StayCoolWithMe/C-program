#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int UserIndex = 0;
int loginIndex = 0;
int enrollIndex = 0;
int choice;
char *availableCourse[] = {"Statistics", "English", "Math"};

void registerUser();
void loginUser();
void enrollCourse();
void Output();

struct user_register
{
    char name[999];  
    int id;
    char password[999];  
};
struct user_register user_register[999]; 

struct login
{
    char loginname[999];
    int loginID;
    char password[999]; 
};
struct login login[999];  
struct course
{
    char intentionCourse[999];  
    char course_User_Name[999];  
    int course_User_ID;
};
struct course course[999];  

int main()
{

    FILE *fp = fopen("OnlineClass.txt", "a+");
    srand(time(NULL));
    while (1)
    {
        printf("1. User Register\n2. Login\n3. Course Enrollment\n4. View Course Enrolled\n5. End\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                enrollCourse();
                break;
            case 4:
                Output();
                break;
            case 5:
                for (int i = 0; i < enrollIndex; i++)
                {
                    fprintf(fp, "\033[34;43m%s\t%d\t%s\n\033[0m",
                course[i].course_User_Name, course[i].course_User_ID, course[i].intentionCourse);
                }
                fclose(fp);
                exit(0);
            default:
                printf("Invalid choice, please enter another:");
                scanf("%d", &choice);
                break;
        }
    }
}

void registerUser()
{
    while (1)
    {
        printf("Enter User name (0 to stop): ");
        scanf("%s", user_register[UserIndex].name);

        if (strcmp(user_register[UserIndex].name, "0") == 0)
        {
            break;
        }

        int randomNumber =1+ rand();
        user_register[UserIndex].id = randomNumber;
        printf("%s ID:%d\n", user_register[UserIndex].name, user_register[UserIndex].id);

        printf("Enter %s password: ", user_register[UserIndex].name);
        scanf("%s", user_register[UserIndex].password);

        UserIndex++;
    }
}

void loginUser()
{
    while (1)
    {
        printf("\nEnter Login Name:(0 to stop)");
        scanf("%s", login[loginIndex].loginname);
        if (strcmp(login[loginIndex].loginname, "0") == 0)
        {
            break;
        }

        printf("Enter %s password:", login[loginIndex].loginname);
        scanf("%s", login[loginIndex].password);

        int loggedIn = 0;
        for (int i = 0; i < UserIndex; i++)
        {
            if (strcmp(login[loginIndex].loginname, user_register[i].name) == 0 && strcmp(login[loginIndex].password, user_register[i].password) == 0)
            {
                login[loginIndex].loginID = user_register[i].id;
                printf("Login successfully\n");
                loggedIn = 1;
                break;
            }
        }

        if (!loggedIn)
        {
            printf("Login unsuccessful. Please enter the following statement again (username/password)\n");
            continue;
        }

        loginIndex++;
    }
}

void enrollCourse()
{
    while (1)
    {
        printf("\nEnter Login Name:(0 to stop)");
        scanf("%s", course[enrollIndex].course_User_Name);
        if(strcmp(course[enrollIndex].course_User_Name,"0")==0)
        {
            break;
        }

        int found = 0;
        for (int i = 0; i < loginIndex; i++)
        {
            if (strcmp(course[enrollIndex].course_User_Name, login[i].loginname) == 0)
            {
                course[enrollIndex].course_User_ID = login[i].loginID;
                found = 1;
                break;
            }
        }

        if (!found)
        {
            printf("User not logged in. Please log in first.\n");
            break;
        }

        printf("Enter enrollment course (Statistics/English/Math): ");
        scanf("%s", course[enrollIndex].intentionCourse);

        int validCourse = 0;
        for (int j = 0; j < sizeof(availableCourse) / sizeof(availableCourse[0]); j++)
        {
            if (strcmp(course[enrollIndex].intentionCourse, availableCourse[j]) == 0)
            {
                validCourse = 1;
                break;
            }
        }

        if (validCourse)
        {
            printf("Course has been successfully enrolled\n");
        }
        else
        {
            printf("Invalid course. Please enter a valid course.\n");
            continue;
        }

        enrollIndex++;
    }
}

void Output()
{
    printf("\nName\tID\tEnrolled Course\n");
    for (int i = 0; i < enrollIndex; i++)
    {
        printf("%s\t%d\t%s\n", course[i].course_User_Name, course[i].course_User_ID, course[i].intentionCourse);
    }
}
