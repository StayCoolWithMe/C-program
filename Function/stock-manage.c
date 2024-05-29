#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxcar 30

    char *carType[]={"Sedan","SUVs","Truck"};
    int stock[30]={10,10,10};
    char name[30][30];
    int choice;
    int total_Car_Stock=0;

    void add_car();
    void sell_car();
    void exit_program();
    void stock_display();
    void car_type_stock();
int main()
{
    do
    {
    printf("1.Adding car\n");
    printf("2.Selling car\n");
    printf("3.Exit\n");
    printf("4.Stock Display\n");
    printf("Enter your choice");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            add_car();
        break;
        }
        case 2:
        {
            sell_car();
        break;
        }
        case 3:
        {
            exit_program();
        break;
        }
        case 4:
        {
            stock_display();
        }
        break;
        default:
        {
            printf("INVALID CHOICE\n");
        }
    }}
        while(choice!=5);
return 0;
}
void exit_program()
{
    exit(0);
}
void add_car()
{
    printf("What is the Current Total car stock");
    scanf("%d",&total_Car_Stock);
    while(total_Car_Stock<1 || total_Car_Stock>maxcar)
    {
        printf("Invalid car stock,please enter a valid one");
        scanf("%d",&total_Car_Stock);
    }
    printf("What is the car stock for Sedan SUVs and Truck");
    for (int i=0;i<3;i++)
    {
        scanf("%d",&stock[i]);
    }
    car_type_stock();
}
void car_type_stock()
{
    for(int i=0;i<3;i++)
    {
        if(stock[i]<5 && stock[i]>0)
        {
            printf("Need to buy car to stock for %s\n",carType[i]);
            while(stock[i]<5)
            {
                stock[i]++;
                total_Car_Stock++;
            }
        }
        else{
            printf("No need to buy car to stock %s\n",carType[i]);
        }
    }
}
void sell_car()
{
       printf("which type of car does the customer want to buy\n");
       for(int i=0;i<3;i++)
       {
        printf("%d %s\n",i+1,carType[i]);
       }
       printf("Please enter the number of corresponding to the car type");
       int intention;
       scanf("%d",&intention);
       while(intention<1 || intention>3)
       {
        printf("Invalid, please enter another one");
        scanf("%d",&intention);
       }
       stock[intention-1]--;
       total_Car_Stock--;
}
void stock_display(){
    printf("Car type\tStock\n");
    for(int i=0;i<3;i++)
    {
        printf("%s\t\t%d\n",carType[i],stock[i]);
    }
        printf("Total stock: %d\n",total_Car_Stock);
}
    