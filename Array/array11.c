#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max_car 20
#define Max_Name_Length 100

int main() {
    char name[Max_car][Max_Name_Length];
    char engine[Max_car][Max_Name_Length];
    float duration[Max_car];
    float price[Max_car];
    char *availableEngines[] = {"Toyota", "Hyundai", "Lexus"};
    float enginePrices[] = {20, 30, 40};//put all the price in here
    int currentCustomer = 0;
    int totalCar = 0;
    int customerNumber = 0;
    int choice;
    int ID[Max_car];
    int carstatus[Max_car] = {0}; 

    printf("Enter the number of customers waiting in line (1-20): ");
    scanf("%d", &customerNumber);
    while (customerNumber > Max_car) {
        printf("We don't have enough vehicles for 20 plus customers. Please enter a valid number: ");
        scanf("%d", &customerNumber);
    }

    for(int i = 0; i < Max_car; i++) {
        ID[i] = i + 1;
    }

    do {
        printf("\nService Menu\n\n");
        printf("1. Rent a car\n");
        printf("2. Check in car\n");
        printf("3. Check out car\n");
        printf("4. Car display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (currentCustomer < Max_car) {
                    printf("Enter the name of the customer %d: ", currentCustomer + 1);
                    scanf("%s", name[currentCustomer]);
                    printf("Enter your preferred vehicle type (Toyota, Hyundai, Lexus): ");
                    scanf("%s", engine[currentCustomer]);
                    printf("Enter the rental period (in days): ");
                    scanf("%f", &duration[currentCustomer]);
                    printf("Enter the car ID(1-20): ");
                    scanf("%d", &ID[currentCustomer]);

                    int engineIndex = -1;//the purpose of this whole for code is to finding a valueble in the array
                    for (int i = 0; i < 3; i++) 
                    {
                        if (strcmp(engine[currentCustomer], availableEngines[i]) == 0) 
 //this condition want to check if the engine selected by the user has it value in the available engine
                        {
                            engineIndex = i;// if it has then the engine index set to i
                            break;
                        }
                    }

                    if (engineIndex != -1) //this condition check if a matching engine is found
                    {
                        printf("%s is available at $%.0f/day.\n", availableEngines[engineIndex], enginePrices[engineIndex]);
                        price[currentCustomer] = enginePrices[engineIndex] * duration[currentCustomer];
                        printf("Total cost: $%.2f\n", price[currentCustomer]);
                        carstatus[ID[currentCustomer]] = 1; 
                    } else {
                        printf("Sorry, the requested car is not available.\n");
                    }

                    currentCustomer++;
                    totalCar++;
                } else {
                    printf("No more cars available or maximum customer limit reached.\n");
                }
            }
            break;

            case 2: {
                int checkincar;
                printf("Enter the car ID to check in: ");
                scanf("%d", &checkincar);
                if (checkincar > 0 && checkincar <= Max_car) 
                {
                    if (carstatus[checkincar] == 0) {
                        carstatus[checkincar] = 1; // Update car status
                        printf("Car ID %d has been successfully checked in.\n", checkincar);
                    } else {
                        printf("Car ID %d is already been checked in.\n", checkincar);
                    }
                } else {
                    printf("Invalid car ID.\n");
                }
            }
            break;

            case 3: {
                int checkoutcar;
                printf("Enter the car ID to check out: ");
                scanf("%d", &checkoutcar);
                if (checkoutcar > 0 && checkoutcar <= Max_car) {
                    if (carstatus[checkoutcar] == 1) {
                        carstatus[checkoutcar] = 0; // Update car status
                        printf("Car ID %d has been successfully checked out.\n", checkoutcar);
                    } else {
                        printf("Car ID %d is not checked in.\n", checkoutcar);
                    }
                } else {
                    printf("Invalid car ID.\n");
                }
            }
            break;

            case 4: 
            {
                int carIDToCheck;
                printf("Enter the car ID to check: ");
                scanf("%d", &carIDToCheck);
                if (carIDToCheck > 0 && carIDToCheck <= Max_car) {
                    if (carstatus[carIDToCheck] == 0) {
                        printf("Car ID %d is ready to be booked\n", carIDToCheck);
                    } else {
                        printf("Car ID %d is not available\n", carIDToCheck);
                    }
                } else {
                    printf("Invalid car ID.\n");
                }
            }
            break;

            case 5: {
                exit(0);
            }
            break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    
}




