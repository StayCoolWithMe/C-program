#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<stdbool.h>
int choice;
int RegisterIndex=0;
int LoginIndex=0;
char *availableExercise[] = {"Push_Up", "Running", "Pull_Up", "Boxing"};
int ActivityIndex=0;

struct Registers{
    char name[999];
    char password[999];
    int RegisterID;
};
struct Registers Registers[999];

struct Login{
    char name[999];
    char password[999];
    int LoginID;
};
struct Login Login[999];

struct exercise{
    char name[999];
    char exericiseName[999];
    int duration;
    int ID;
};
 struct exercise exercise[999];

void Register();
void LoginN();
void Activity();
void View();
int main()
{
    srand(time(NULL));
    FILE*fp=fopen("fitness-track.txt","a+");
    while(1)
    {
        printf("\nMenu\n1.Register\n2.Log In\n3.Activities\n4.View Activities\n5.Exit\n");
        scanf("%d",&choice);
        switch(choice)
    {
        case 1:
        Register();
        break;
        case 2:
        LoginN();
        break;
        case 3:
        Activity();
        break;
        case 4:
        View();
        break;
        
        case 5:
         for(int i=0;i<ActivityIndex;i++)
        {
            fprintf(fp,"%s\t%d\t%s\t%d",exercise[i].name,exercise[i].ID,exercise[i].exericiseName,exercise[i].duration);
        }
        fclose(fp);
            exit(0);
        break;
        default:
        printf("Invalid choice,please enter a valid one:\n");
        scanf("%d",&choice);
        break;
    } 
    }
}
*
void Register()
{
    while(1)
    {
        printf("\nEnter Username(0 to stop):");
        scanf("%s", Registers[RegisterIndex].name);
        if(strcmp( Registers[RegisterIndex].name,"0")==0)
        {
            break;
        }
        printf("Enter %s password:",Registers[RegisterIndex].name);
        scanf("%s", Registers[RegisterIndex].password);
        int randomID=1+rand();
        Registers[RegisterIndex].RegisterID=randomID;
        printf("%s ID: %d\n", Registers[RegisterIndex].name, Registers[RegisterIndex].RegisterID);
    RegisterIndex++;
    }
}

void LoginN()
{
    while(1)
    {
        printf("\nEnter Username(0 to stop):");
        scanf("%s", Login[LoginIndex].name);
        if(strcmp( Login[LoginIndex].name,"0")==0)
        {
            break;
        }
        printf("Enter your password:");
        scanf("%s", Login[LoginIndex].password);
        int loggedin=0;
        for(int i=0;i<RegisterIndex;i++)
        {
            if(strcmp(Login[LoginIndex].name,Registers[i].name)==0 || strcmp(Login[LoginIndex].password,Registers[i].password)==0)
            {
                Login[LoginIndex].LoginID=Registers[i].RegisterID;
                printf("Log in successfully\n");
                loggedin=1;
                break;
            }
        }
        if(!loggedin)
        {
            printf("Log in unsuccess\n");
            continue;
        }
    LoginIndex++;
    }
}

void Activity() {
    while (1) {
        printf("\nUsername(0 to stop):");
        scanf("%s", exercise[ActivityIndex].name);
        if (strcmp(exercise[ActivityIndex].name, "0") == 0) {
            break;
        }
        int foundUser = 0;
        for (int i = 0; i < LoginIndex; i++) {
            if (strcmp(exercise[ActivityIndex].name, Login[i].name) == 0) {
                foundUser = 1;
                exercise[ActivityIndex].ID = Login[i].LoginID;
                break;
            }
        }
        if (!foundUser) {
            printf("User not found\n");
            continue;
        }
        printf("%s Activities(Push_Up/Running/Pull_Up/Boxing):", exercise[ActivityIndex].name);
        scanf("%s", exercise[ActivityIndex].exericiseName);
        int found = 0;
        for (int j = 0; j < sizeof(availableExercise) / sizeof(availableExercise[0]); j++) {
            if (strcmp(exercise[ActivityIndex].exericiseName, availableExercise[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Invalid exercise, please enter another one:");
            continue;
        }
        printf("Enter duration(mn):");
        scanf("%d", &exercise[ActivityIndex].duration);
        if (exercise[ActivityIndex].duration > 15) {  
            printf("Pro\n");
        } else if (exercise[ActivityIndex].duration > 10) {  
            printf("Intermediate\n");
        } else if (exercise[ActivityIndex].duration > 0) {  
            printf("Beginner\n");
        } else {
            printf("Invalid duration.\n");
            continue;
        }
        ActivityIndex++;  
    }
}

void View()
{
    
    
        printf("\nUser name\tID\tActivities\tDuration\n");
        for(int i=0;i<ActivityIndex;i++)
        {
            printf("%s\t\t%d\t%s\t\t%d\n",exercise[i].name,exercise[i].ID,exercise[i].exericiseName,exercise[i].duration);
        }
    
}
