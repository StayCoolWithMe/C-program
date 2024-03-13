#include <stdio.h>

#define NUM_ROOMS 100

char guestName[NUM_ROOMS][50];
int roomStatus[NUM_ROOMS];

    int choice, roomNumber[NUM_ROOMS];
    int i = 1;
int main() {

    do {
        printf("\n1. Add a new guest\n");
        printf("2. Check-in a guest\n");
        printf("3. Check-out a guest\n");
        printf("4. Display room status\n");
        printf("5. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter guest name: ");
            scanf("%s", guestName[i]);

            printf("Enter room number: ");
            scanf("%d", &roomNumber[i]);

            roomStatus[i] = 1;//just an identify show that the room is occupied
            printf("Guest added successfully.\n");
        } else if (choice == 2) {
            int roomToCheckIn;
            printf("Enter room number to check-in: ");
            scanf("%d", &roomToCheckIn);
            int guestIndex = -1;//dont know whether the room is occupied or not
             for (int j = 1; j <=i ; j++) {
                if (roomNumber[j] == roomToCheckIn) {
                    guestIndex = j;//to make sure the room is occupied
                    break;
                }
            }

            if (guestIndex != -1) {
                roomStatus[guestIndex] = 1;//the room definetly is occupied 
                printf("Guest checked-in successfully.\n");
            } else {
                printf("Room number not found.\n");
            }
        } else if (choice == 3) {
            int roomToCheckOut;
            printf("Enter room number to check-out: ");
            scanf("%d", &roomToCheckOut);


            int guestIndex = -1;
             for (int j = 1; j <=i ; j++){
                if (roomNumber[j] == roomToCheckOut) {
                    guestIndex = j;
                    break;
                }
            }
            if (guestIndex != -1) {
                roomStatus[guestIndex] = 0; 
                printf("Guest checked-out successfully.\n");
            } else {
                printf("Room number not found.\n");
            }
        } else if (choice == 4) {
            printf("Room Status:\n");
           for (int j = 1; j <=i ; j++){
                if (roomStatus[i] == 0) {
                    printf("%d - Vacant\n", roomNumber[j]);
                } else {
                    printf("%d - Occupied\n", roomNumber[j]);
                }
            }
        } else if (choice == 5) {
            printf("Thank you for using the Hotel Management System. Goodbye!\n");
        } else {
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5 && i <= NUM_ROOMS);//5=case 
}

