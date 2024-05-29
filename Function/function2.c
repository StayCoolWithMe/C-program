#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define Max_customer 20
char name[Max_customer][100];
int phoneNumber[Max_customer];
char email[Max_customer][200];
int appointment[Max_customer];
int num=0;
int current=0;
int choice;
void error();
void add_customer();
void view_customer();
void delete_customer();
void exit_program();
int main()
{
    error();
    
    do{
        printf("Welcome to our salon\n");
        printf("1.Add customer\n");
        printf("2.View customer\n");
        printf("3.Delete customer\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :{
                add_customer();
                break;
                }
            case 2:{
                view_customer();
                break;
            }
            case 3:{
                delete_customer();
                break;
            }
            case 4:{
                exit_program();
            }
            default:{
                printf("INVALID CHOICE\n");
            }
        }
        
    }while(choice!=4);
}

//This is the function for each case 
void error()
{
    printf("Enter the number of customers that registered: ");
    scanf("%d", &num);
    while(num<1 || num>Max_customer)
    {
        printf("Invalid choice, please enter another one: ");
        scanf("%d", &num);
    }
}
//This is add cumstomer function
void add_customer()
{
    for(int i=0;i<num;i++)
    {
        printf("Enter the customer %d name: ",current+1);
        scanf("%s", name[current]);
        printf("Enter the customer %d phone number: ",current+1);
        scanf("%d", &phoneNumber[current]);
        printf("Enter the customer %d email: ",current+1);
        scanf("%s", email[current]);
        printf("Enter the appointment time: ");
        scanf("%d", &appointment[current]);
        current++;
    }

}
//This is view function
void view_customer(){
    printf("Name\t\tPhone number\t\tEmail\t\t\tAppointment time\n");
    for(int i=0;i<num;i++){
        printf("%s\t\t%d\t\t%s\t\t%d\n",name[i],phoneNumber[i],email[i],appointment[i]);
    }
}
//This is delete functionn
void delete_customer(){
    if(num==0)
    {
        printf("No customer to delete\n");
    }
    int delete;
    printf("Enter the customer num(1-%d) to delete: ",num);
    scanf("%d",&delete);
    delete--;
    if(delete<0 || delete>=num)
    {
        printf("Invalid number\n");
    }
    for(int i=delete;i<num-1;i++)
    {
        strcpy(name[i],name[i+1]);
        phoneNumber[i]=phoneNumber[i+1];
        strcpy(email[i],email[i+1]);
        appointment[i]=appointment[i+1];
    }
    printf("Deleted successfully\n");
    num--;
}
void exit_program()
{
    exit(0);
}
