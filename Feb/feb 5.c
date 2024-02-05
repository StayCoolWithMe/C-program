#include<stdio.h>
int main()
{
    char name[50];
    int parking_hour;
    float cost;
    float discount;
    float total;
    printf("Parking Brand Name: ");
    scanf("%s",name);
    printf("Parking Hour : ");
    scanf(" %d",&parking_hour);
    if(parking_hour<=3)
    {
        total = parking_hour * 3;
    }
    else if(parking_hour>=4 && parking_hour <=12)
    {
        total=2*parking_hour;
    }
    else if(parking_hour>12)
    {
        cost=(2*parking_hour);
        discount = cost * 0.2;
        total = cost - discount;
    }
    printf("parking hour:%d\n",parking_hour);
    printf("cost %.2f\n",cost);
    printf("discount:%.2f\n",discount);
    printf("The total cost %.2f\n",total);
}
