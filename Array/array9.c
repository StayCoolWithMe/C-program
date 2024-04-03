#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max_Room 100
#define Max_Name_Length 200
#define Comment_Section 200

int main() {
    char name[Max_Room][Max_Name_Length];
    int choice;
    int currentguess = 0;
    char comment[Max_Room][Comment_Section];
    int roomnumber[Max_Room];
    int roomstatus[Max_Room] = {0}; 
    int totalroom = 0;
    int payment;
    
    printf("Welcome to our Hotel Service\n\n");
    
    do {
        printf("1. Add guest\n");
        printf("2. Check in guest\n");
        printf("3. Check out guest\n");
        printf("4. Room display\n");
        printf("5. Verification and Payment\n");
        printf("6. Leave a comment for our hotel\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                if (currentguess < Max_Room) {
                    printf("Customer %d name: ", currentguess + 1);
                    scanf("%s", name[currentguess]);
                    printf("%s, please enter the room number to book (1-100): ", name[currentguess]);
                    scanf("%d", &roomnumber[currentguess]);
                    roomstatus[roomnumber[currentguess] - 1] = 1;
                    printf("%d Customer %s, Have you done your payment (y/n): ", currentguess + 1, name[currentguess]);
                    scanf(" %c", &payment); 
                    if (payment == 'n') { 
                        printf("Please go to the financial service to pay the fee\n");
                    } else {
                        printf("Thank you so much for your payment\n");
                    }
                    currentguess++;
                    totalroom++;
                } else {
                    printf("All rooms have been booked\n");
                }
            } break;
            
            case 2: {
                int roomtocheckin;
                printf("Enter room number to check in: ");
                scanf("%d", &roomtocheckin);
                if (roomtocheckin > 0 && roomtocheckin <= Max_Room) {
                    if (roomstatus[roomtocheckin - 1] == 0) {
                        printf("Enter the guest name: ");
                        scanf("%s", name[roomtocheckin - 1]);
                        roomstatus[roomtocheckin - 1] = 1;
                        printf("Room checked in successfully\n");
                    } else {
                        printf("Room already booked by another guest\n");
                    }
                } else {
                    printf("Invalid room number\n\n");
                }
            } break;
            
            case 3: {
                int roomtocheckout;
                printf("Enter the room number to check out: ");
                scanf("%d", &roomtocheckout);
                if (roomtocheckout > 0 && roomtocheckout <= Max_Room) {
                    if (roomstatus[roomtocheckout - 1] == 1) {
                        printf("Guest name: %s\n", name[roomtocheckout - 1]);
                        roomstatus[roomtocheckout - 1] = 0; 
                        printf("Room checked out successfully\n");
                    } else {
                        printf("Room not booked\n");
                    }
                } else {
                    printf("Invalid room number\n\n");
                }
            } break;
            
            case 4: {
                for (int i = 0; i < Max_Room; i++) {
                    if (roomstatus[i] == 0) {
                        printf("Room %d is ready to be booked\n", i + 1);
                    } else {
                        printf("Sorry, Room %d is not available\n", i + 1);
                    }
                }
            } break;
            
            case 5: {
                int searchroom;
                printf("Enter a room number to search: ");
                scanf("%d", &searchroom);
                int found = 0;
                for (int i = 0; i < totalroom; i++) {
                    if (searchroom == roomnumber[i] &&  searchroom==roomtocheckin && searchroom==roomtocheckout) {
                        printf("%d Customer %s, Have you done your payment (y/n): ", i + 1, name[i]);
                        scanf(" %c", &payment);
                        if (payment == 'n') {
                            printf("Please go to the financial service to pay the fee\n");
                        } else {
                            printf("Thank you so much for your payment\n");
                        }
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Room not found.\n");
                }
            } break;
            
            case 6: {
                printf("Your comment matters: ");
                scanf(" %[^\n]", comment[currentguess - 1]);
            } break;
            
            case 7: {
                exit(0);
            } break;
            
            default: {
                printf("Invalid choice\n");
            } break;
        }
    } while (1);
    
}



