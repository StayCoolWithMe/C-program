#include<stdio.h>
#include<stdlib.h>
#define Max_Name 50
#define Max_Name_Lenght 200
//variable
char name[Max_Name][Max_Name_Lenght];
int ID[Max_Name];
int age[Max_Name];
int choice;
void input();

//main function
int main()
{
 input();
}
//function
void input(){
    printf("Enter your ID");
    scanf("%d",&ID[0]);
    while(ID[Max_Name]<0 || ID[Max_Name]>Max_Name)
    {
        printf("Unvalid ,please enter a valid one");
        scanf("%d",&ID[0]);

    }
    printf("Menu\n\n");
    printf("1.Name\n");
    printf("2.Age\n");
    printf("3.exit\n");
    printf("Enter your choice(1-3)");
    scanf("%d",&choice);
    if(choice>3 || choice<1)
    {
         printf("Unvalid ,please enter a valid one3");
        scanf("%d",&choice);
    }
    switch(choice)
    {
        case 1:
        {
            printf("Enter your name");
            scanf(" %s", name[ID[0]]);
        break;
        }
        case 2:
        {
            printf("Enter your age");
            scanf("%d",  &age[ID[0]]);
        break;
        }
        case 3:
        {
            exit(0);
        break;
        }
        default:
        {
            printf("Unvalid\n");
        }
 
    }
}

