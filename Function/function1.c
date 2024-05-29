#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 50
#define Max_Name_lenght 100

// Variables
char name[Max][Max_Name_lenght];
char* available[] = {"1.PP to KPS", "2.PP to Sr", "3.PP to BTB"};
float price[] = {25, 65, 45};
int num = 0;
float total[Max];

// Functions
void input();
void output();
float calculator(int intention, int i);

int main() {
    input();
    output();
}

void input() {
    printf("Enter the number of customers: ");
    scanf("%d", &num);
    while(num < 1) {
        printf("Please enter a valid number: ");
        scanf("%d", &num);
    }
    for(int i = 0; i < num; i++) {
        printf("\nEnter name for passenger %d: ", i + 1);
        scanf("%s", name[i]);
        printf("Where is your destination (1/PP to KPS, 2/PP to Sr, 3/PP to BTB): ");
        int choice;
        scanf("%d", &choice);
        int intention;
        printf("What is your intention (1.travel&return/2.travel): ");
        scanf("%d", &intention);
        
     //This is another way rather than strcmp
    //This type is simply eaiser to use if you sure that the use input is within the range 
    //This type is faster but not extra  safe to deal with logical error

        int index = choice - 1; //make sure that the array start from 1 rather than 0
        if(index >= 0 && index < 3) {
            printf("%s will be available at %.2f/person (only serve for go)\n", available[index], price[index]);
            total[i] = calculator(intention, index);
        } else {
            printf("Invalid choice\n");
        }
    }
}

float calculator(int intention, int i) {
    if(intention == 1) {
        return price[i] * 2;
    } else {
        return price[i];
    }
}

void output() {
    printf("Name\t\tDestination\t\tPrice\t\tTotal\n");
    for(int i = 0; i < num; i++) {
        printf("%s\t\t%s\t\t%.2f\t\t%.2f\n", name[i], available[i], price[i], total[i]);
    }
}
