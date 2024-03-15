#include<stdio.h>
#define TotalNumber 10

int main() {
    int room[TotalNumber] = {0}; //to tell that all room is available at the moment

    int choice;
    do {
        printf("Welcome to our hotel\n\n");
        printf("1. Display the available rooms\n");
        printf("2. Book a room\n");
        printf("3. Display booked rooms\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Available rooms\n");
                int available = 0;
                for (int i = 0; i < TotalNumber; i++) {
                    if (room[i] == 0) {
                        printf("Room %d\n", i + 1);
                        available++;
                    }
                }
                if (available == 0) {
                    printf("All rooms are booked\n");
                }
                break;
            }
            case 2: {
                int bookroom;
                printf("Enter the room number to book: ");
                scanf("%d", &bookroom);
                if (bookroom < 1 || bookroom > TotalNumber) {
                    printf("Invalid choice\n");
                } else if (room[bookroom - 1] == 1) {
                    printf("Room %d is already booked\n", bookroom);
                } else {
                    room[bookroom - 1] = 1; // Mark the room as booked
                    printf("Room %d booked successfully\n", bookroom);
                }
                break;
            }
            case 3: {
                printf("Booked rooms\n");
                int booked = 0;
                for (int i = 0; i < TotalNumber; i++) {
                    if (room[i] == 1) {
                        printf("Room %d\n", i + 1);
                        booked++;
                    }
                }
                if (booked == 0) {
                    printf("No rooms are booked\n");
                }
                break;
            }
            case 4: {
                printf("Thank you for choosing us\n");
                break;
            }
            default: {
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
            }
        }
    } while (choice != 4);

    return 0;
}

