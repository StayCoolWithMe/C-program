#include<stdio.h>
#define TotalRoom 5

int main() {
    int price[] = {25, 35, 45, 55, 65};
    int num = sizeof(price) / sizeof(price[0]);
    char guessname[TotalRoom][50]; 
    int RoomNumber[TotalRoom];
    int RoomStatus[TotalRoom] = {0}; 
    int choice;
    int i = 0; 

    do {
        printf("\nAvailable rental room price\n");
        for(int j = 0; j < num; j++) {
            printf("%d. Price %d\n", j + 1, price[j]);
        }
        printf("\nMenu\n");
        printf("1. Add guest\n");
        printf("2. Check in guest\n");
        printf("3. Check out guest\n");
        printf("4. Room display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter guest name: ");
            scanf("%s", guessname[i]);
            printf("Enter room to book: ");
            scanf("%d", &RoomNumber[i]);
            RoomStatus[i] = 1; // Room is occupied
            printf("Guest added successfully.\n");
            i++; // Increment i after adding a guest
        }
        else if(choice == 2) {
            int roomcheckin;
            printf("Enter room number to check in: ");
            scanf("%d", &roomcheckin);
            int GuestIndex = -1;
            for(int j = 0; j < i; j++) {
                if(roomcheckin == RoomNumber[j]) {
                    GuestIndex = j;
                    break;
                }
            }
            if(GuestIndex != -1) {
                RoomStatus[GuestIndex] = 1;
                printf("Guest checked-in successfully.\n");
            }
            else {
                printf("Room number not found.\n");
            }
        }
        else if(choice == 3) {
            int roomcheckout;
            printf("Enter room number to check out: ");
            scanf("%d", &roomcheckout);
            int GuestIndex = -1;
            for(int j = 0; j < i; j++) {
                if(roomcheckout == RoomNumber[j]) {
                    GuestIndex = j;
                    break;
                }
            }
            if(GuestIndex != -1) {
                RoomStatus[GuestIndex] = 0;
                printf("Guest checked-out successfully.\n");
            }
            else {
                printf("Room number not found.\n");
            }
        }
        else if(choice == 4) {
            printf("Room Status:\n");
            for(int j = 0; j < i; j++) {
                if(RoomStatus[j] == 0) {
                    printf("%d - Vacant\n", RoomNumber[j]);
                }
                else {
                    printf("%d - Occupied\n", RoomNumber[j]);
                }
            }
        }
        else if(choice == 5) {
            printf("Exiting\n");
            break;
        }
        else {
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while(choice != 5 && i < TotalRoom); // Exit loop if choice is 5 or maximum rooms are filled

    return 0;
}

