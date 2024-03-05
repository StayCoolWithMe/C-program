#include<stdio.h>
int main()
{
    int coffeeBeans[3];
    int teaBags[3];
    int milkCartons[3];
    int sugarPackets[3];
    int totalcoffee=0;
    int totaltea=0;
    int totalmilk=0;
    int totalsugar=0;
    for(int i=0;i<2;i++)
    {
        printf("Enter the stock for day %d\n",i+1);
        printf("Stock ofr coffee beans:");
        scanf("%d",&coffeeBeans[i]);
        printf("Stock for tea bags :");
        scanf("%d",&teaBags[i]);
        printf("Stock for milk cartons :");
        scanf("%d",&milkCartons[i]);
        printf("Stock for sugar packets");
        scanf("%d",&sugarPackets[i]);

    }
    //calculate for the whole 2 day
    //if dont use for that mean we only calculate for specific day
    for(int i=0;i<2;i++)
    {
        totalcoffee+=coffeeBeans[i];
        totaltea+=teaBags[i];
        totalmilk+=milkCartons[i];
        totalsugar+=sugarPackets[i];

    }
    printf("\nTotal stock for the last 2 days:\n");
    printf("Coffee beans: %d\n", totalcoffee);
    printf("Tea bags: %d\n", totaltea);
    printf("Milk cartons: %d\n", totalmilk);
    printf("Sugar packets: %d\n", totalsugar);
}