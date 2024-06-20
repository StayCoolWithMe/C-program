#include <stdio.h>
#include <stdlib.h>

int whoHasTheMostMoney(int balance[], int num_customers) {
    int max_money = balance[0];
    int max_index = 0;

    for (int i = 1; i < num_customers; i++) {
        if (balance[i] > max_money) {
            max_money = balance[i];
            max_index = i;
        }
    }

    return max_index;
}

int main() {
    int num_customers;

    printf("Enter the number of customers: ");
    scanf("%d", &num_customers);
    getchar(); 

    int* balance = (int*)malloc(num_customers * sizeof(int));

    printf("Enter the balances for each customer separated by spaces:\n");

    for (int i = 0; i < num_customers; i++) {
        printf("Customer %d: ", i + 1);
        balance[i] = 0; 
        int temp;
        while (scanf("%d", &temp) == 1) {
            balance[i] += temp;
            char c = getchar();
            if (c == '\n' || c == EOF) 
                break; 
        }
    }

    int richest_customer_index = whoHasTheMostMoney(balance, num_customers);

    printf("The customer with the most money is at index %d\n", richest_customer_index);

    free(balance);

    return 0;
}
