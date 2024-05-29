#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int i = 0;
int total = 0;

void Input(char name[][20], int quantity[], char opt[][20], float Price[], char *available[]);
int Payment(char name[][20], int quantity[], char opt[][20], float Price[], char *available[]);
void Output(char name[][20], int quantity[], int total, char opt[][20], float Price[]);

int main()
{
    char name[100][20];
    int quantity[999];
    char opt[999][20];
    int choice;
    char *available[] = {"Petro", "Extra", "Gas"};
    float Price[] = {4000, 5000, 4200};

    while (1)
    {
        printf("1.Input\n2.Output\n");
        printf("Please enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            Input(name, quantity, opt, Price, available);
            break;
        case 2:
            total = Payment(name, quantity, opt, Price, available);
            Output(name, quantity, total, opt, Price);
            break;
        default:
            printf("Invalid choice. Please enter 1 or 2.\n");
        }
    }
}

void Input(char name[][20], int quantity[], char opt[][20], float Price[], char *available[])
{
    while (1)
    {
        printf("Please enter your name(0 to stop): ");
        scanf("%s", name[i]);
        if (strcmp(name[i], "0") == 0)
        {
            break;
        }
        printf("Enter your preference(Petro/Gas/Extra) [please enter in word]: ");
        scanf("%s", opt[i]);

        //Handle error
        int Index = -1;
        for (int j = 0; j < 3; j++) 
        { 
            if (strcmp(opt[i], available[j]) == 0) {
                Index = j;
                break;
            }
        }

        if (Index != -1)
        {
            printf("%s is available at %.0f\n", available[Index], Price[Index]);
            printf("Enter the quantity: ");
            scanf("%d", &quantity[i]);
            i++;
        }
        else
        {
            printf("Invalid option entered. Please try again.\n");
        }
    }
}

int Payment(char name[][20], int quantity[], char opt[][20], float Price[], char *available[])
{
    int total = 0;
    for (int j = 0; j < i; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            if (strcmp(opt[j], available[k]) == 0)
            {
                total += Price[k] * quantity[j];
                break;
            }
        }
    }
    return total;
}

void Output(char name[][20], int quantity[], int total, char opt[][20], float Price[])
{
    printf("Name\tGas Type\tQuantity\tGrand Total\n");
    for (int j = 0; j < i; j++)
    {
        printf("%s\t%s\t\t%d\t\t%.0f\n", name[j], opt[j], quantity[j], Price[j] * quantity[j]);
    }
}
