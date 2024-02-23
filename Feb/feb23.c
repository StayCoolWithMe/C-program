#include <stdio.h>

int main() {
    float distance;
    float cost = 11;
    float weight;
    char name[20];
    int quantity;
    float total;
    printf("Enter username: ");
    scanf("%s", name);
    printf("Enter the distance: ");
    scanf("%f", &distance);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);
    printf("Enter the weight: ");
    scanf("%f", &weight);
    total = quantity * cost;
    if (distance >= 100)
     {
        total = total+(total*0.01); 
    }
    printf("Your cost: %.2f\n", total);

}
