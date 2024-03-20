#include <stdio.h>
#include <stdlib.h>

#define Max_Room 50
#define Max_Name_Length 100
#define Max_Comment 100

int main() {
    // Arrays to store information about rooms and guests
    char name[Max_Room][Max_Name_Length]; // Stores names of guests
    char comment[Max_Room][Max_Comment]; // Stores comments for each guest
    int RoomNumber[Max_Room]; // Stores room numbers
    int roomStatus[Max_Room] = {0}; // Stores status of each room (0 for vacant, 1 for occupied)

    // Variables to track the current state
    int currentCustomer = 0; // Tracks the current customer index
    int totalRooms = 0; // Tracks the total number of rooms
    int choice; // Stores the user's menu choice

    printf("Welcome to our hotel management system!\n");

    do {
        // Display menu options
        printf("\nMenu:\n");
        printf("1. Book a room\n");
        printf("2. Check in a guest\n");
        printf("3. Check out a guest\n");
        printf("4. Room status\n");
        printf("5. Leave a comment\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform actions based on user choice
        switch (choice) {
            case 1: // Book a room
                if (currentCustomer < Max_Room) {
                    printf("Enter the name for customer %d: ", currentCustomer + 1);
                    scanf("%s", name[currentCustomer]); // Input guest name
                    printf("Enter room number to book: ");
                    scanf("%d", &RoomNumber[currentCustomer]); // Input room number
                    roomStatus[RoomNumber[currentCustomer] - 1] = 1; // Mark the room as occupied
                    currentCustomer++; // Move to the next customer
                    totalRooms++; // Increment total room count
                    printf("Room booked successfully!\n");
                } else {
                    printf("Sorry, all rooms are booked.\n");
                }
                break;

            case 2: // Check in a guest
                {
                    int roomtocheckin;
                    printf("Enter room number to check in: ");
                    scanf("%d", &roomtocheckin);
                    if (roomtocheckin >= 1 && roomtocheckin <= totalRooms) {
                        if (roomStatus[roomtocheckin - 1] == 0) {//if the room is free
                            printf("Enter the name for the guest: ");
                            scanf("%s", name[roomtocheckin - 1]);
                            roomStatus[roomtocheckin - 1] = 1;
                            printf("Guest checked in successfully.\n");
                        } else {
                            printf("Sorry, the room is already occupied.\n");
                        }
                    } else {
                        printf("Invalid room number.\n");
                    }
                }
                break;

            case 3: // Check out a guest
                {
                    int roomtocheckout;
                    printf("Enter room number to check out: ");
                    scanf("%d", &roomtocheckout);
                    if (roomtocheckout >= 1 && roomtocheckout <= totalRooms) {
                        if (roomStatus[roomtocheckout - 1] == 1) {
                            roomStatus[roomtocheckout - 1] = 0;
                            printf("Guest checked out successfully.\n");
                        } else {
                            printf("Sorry, the room is already vacant.\n");
                        }
                    } else {
                        printf("Invalid room number.\n");
                    }
                }
                break;

            case 4: // Room status
                printf("Room Status:\n");
                for (int i = 0; i < totalRooms; i++) {
                    if (roomStatus[i] == 0) {
                        printf("Room %d - Vacant\n", i + 1);
                    } else {
                        printf("Room %d - Occupied by %s\n", i + 1, name[i]);
                    }
                }
                break;

            case 5: // Leave a comment
                printf("Enter your comment: ");
                scanf(" %[^\n]", comment[currentCustomer - 1]); // Input comment
                printf("Thank you for your feedback!\n");
                break;

            case 6: // Exit
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a number from 1 to 6.\n");
        }
    } while (choice != 6); // Continue until the user chooses to exit

}

 

