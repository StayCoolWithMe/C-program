#include<stdio.h>
int main()
{
    char name[20];
    float cost;
    int buyer;
    float Total;
    printf("Store Name: ");
    scanf("%s",name);
    printf("cost_per_one: ");
    scanf(" %f",&cost);
    printf("buyer: ");
    scanf(" %d",&buyer);
    Total=cost*buyer;
     printf("Toatal %.0f",Total);
     if(buyer>=5)
     {
        Total=cost*buyer-(cost*buyer)*0.2;
     }
    printf("\nThe toal cost will be %f",Total);

    
}
