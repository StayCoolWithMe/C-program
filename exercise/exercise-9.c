#include<stdio.h>

int main() {
    int choice[8];
    float cost[8];
    float discount[8] = {0}; 
    float total1[8] = {0}; 
    float total2[8] = {0}; 
    char name[8][20];
    int num;
    int quantity[8];
    
    printf("Number of customers: ");
    scanf("%d", &num);
    
    for(int i = 0; i < num; i++) {
        printf("Customer No %d\n", i+1);
        printf("What's your name? ");
        scanf("%s", name[i]);
        printf("Menu\n");
        printf("1. Coffee\n");
        printf("2. Tea\n");
        printf("3. Sting\n");
        printf("4. Coca\n");
        printf("5. Red Bull\n");
        printf("6. Latte\n");
        printf("7. Cappuccino\n");
        printf("8. Americano\n");
        printf("What's your order? (1-8) (Enter 0 to finish): ");
        scanf("%d", &choice[i]);
        
        while(choice[i] != 0) {
            switch(choice[i]) {
                case 1:
                    cost[i] = 2.3;
                    break;
                case 2:
                    cost[i] = 2;
                    break;
                case 3:
                    cost[i] = 1.5;
                    break;
                case 4:
                    cost[i] = 1.2;
                    break;
                case 5:
                    cost[i] = 1;
                    break;
                case 6:
                    cost[i] = 2.5;
                    break;
                case 7:
                    cost[i] = 3;
                    break;
                case 8:
                    cost[i] = 3.5;
                    break;
                default:
                    printf("Invalid choice\n");
            }
            
            printf("Enter your quantity: ");
            scanf("%d", &quantity[i]);
            while (quantity[i] < 0) {
                printf("Invalid quantity\n");
                printf("Enter your quantity: ");
                scanf("%d", &quantity[i]);
            }
            
            total1[i] += cost[i] * quantity[i];
            
            printf("What's your order? (1-8) (Enter 0 to finish): ");
            scanf("%d", &choice[i]);
        }
    }
    
    for(int i = 0; i < num; i++) {
        if(total1[i] >= 20) {
            discount[i] += total1[i] * 0.05;
            total2[i] = total1[i] - discount[i];
        } else {
            total2[i] = total1[i];
        }
    }
        for(int i=0;i<num;i++)
    { 
        if(total1[i] >= 20)
        {
            printf(" Congrat %s !You got 5%% off\n",name[i]);
        }
        else
        {
            printf("Don't win any promotion");
        }
        printf(" %s your total is:%.0f\n",name[i], total2[i]);
    }
    
}
