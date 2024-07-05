#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

// GLOBAL VARIABLES
int choice;
int Register_Index = 0;
int Login_Index = 0;
int Edit_Index = 0;
int ridesize = 0;
int Bookride_Index = 0;
int Cancel_Index = 0;
int Rate_Index = 0;
int logout_Index = 0;

// STRUCTURES
struct Register_Structure {
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int registerID;
};

struct Register_Structure Register_Structure[999];

struct Bookride_Structure {
    char name[MAX_NAME_LENGTH];
    int BookID;
    float Bookprice;
    float bookTotal;
    float distance; // Added distance for booking
};

struct Bookride_Structure Bookride_Structure[999];

struct Login_Structure {
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int LoginID;
};

struct Login_Structure Login_Structure[999];

struct Edit_Structure {
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int EditID;
};

struct Edit_Structure Edit_Structure[999];

struct Menu_Structure {
    char ridename[MAX_NAME_LENGTH];
    int rideID;
    float rideprice;
};

struct Menu_Structure Menu_Structure[999];

struct Rate_Structure {
    int scale;
};

struct Rate_Structure Rate_Structure[999];

struct Cancel_Structure {
    char username[MAX_NAME_LENGTH];
    int rideID;
    float canceltotal;
};

struct Cancel_Structure Cancel_Structure[999];

struct Logout_Structure {
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int LogoutID;
};

struct Logout_Structure Logout_Structure[999];

// FUNCTION PROTOTYPES
void Register_Function();
void Login_Function();
void Viewprofile_Function();
void Editprofile_Function();
void Viewride_Function();
void initride();
void Bookride_Function();
void Viewbooking_Function();
void Cancel_Function();
void Rate_Function();
void Logout_Function();

int main() {
    srand(time(NULL));
    initride();

    while (1) {
        printf("\033[0;32m\nMenu:\n");
        printf("1. Register\n");
        printf("2. Log In\n");
        printf("3. View Profile\n");
        printf("4. Edit Profile\n");
        printf("5. View Ride\n");
        printf("6. Book Ride\n");
        printf("7. View Booking\n");
        printf("8. Cancel Booking\n");
        printf("9. Rate Ride\n");
        printf("10. Log Out\n");
        printf("11. Exit\n");
        printf("\033[0m");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                Register_Function();
                break;
            case 2:
                Login_Function();
                break;
            case 3:
                Viewprofile_Function();
                break;
            case 4:
                Editprofile_Function();
                break;
            case 5:
                Viewride_Function();
                break;
            case 6:
                Bookride_Function();
                break;
            case 7:
                Viewbooking_Function();
                break;
            case 8:
                Cancel_Function();
                break;
            case 9:
                Rate_Function();
                break;
            case 10:
                Logout_Function();
                break;
            case 11:
                exit(0);
            default:
                printf("\033[1;31mInvalid choice, please enter another one:\033[0m\n");
                scanf("%d", &choice);
                break;
        }
    }
}

void Register_Function() {
    while (1) {
        printf("\nEnter username (0 to stop): ");
        scanf("%s", Register_Structure[Register_Index].name);
        if (strcmp(Register_Structure[Register_Index].name, "0") == 0) {
            break;
        }
        
        printf("%s password: ", Register_Structure[Register_Index].name);
        scanf("%s", Register_Structure[Register_Index].password);
        
        // Generate a random ID
        Register_Structure[Register_Index].registerID = rand() % 10000 + 1;
        
        printf("%s ID: %d\n", Register_Structure[Register_Index].name, Register_Structure[Register_Index].registerID);
        
        Register_Index++;
    }
}

void Login_Function() {
    while (1) {
        int loginfound = 0;
        printf("\nEnter login name (0 to stop): ");
        scanf("%s", Login_Structure[Login_Index].name);
        
        if (strcmp(Login_Structure[Login_Index].name, "0") == 0) {
            break;
        }
        
        printf("Enter %s password: ", Login_Structure[Login_Index].name);
        scanf("%s", Login_Structure[Login_Index].password);
        
        for (int i = 0; i < Register_Index; i++) {
            if (strcmp(Login_Structure[Login_Index].name, Register_Structure[i].name) == 0
                && strcmp(Login_Structure[Login_Index].password, Register_Structure[i].password) == 0) {
                loginfound = 1;
                Login_Structure[Login_Index].LoginID = Register_Structure[i].registerID;
                printf("%s Login Successfully\n", Login_Structure[Login_Index].name);
                break;
            }
        }
        
        if (!loginfound) {
            printf("%s Login Failed\n", Login_Structure[Login_Index].name);
        }
        
        Login_Index++;
    }
}

void Viewprofile_Function() {
    printf("\nUsername\tID\tPassword\n");
    for (int i = 0; i < Login_Index; i++) {
        printf("%s\t\t%d\t%s\n", Login_Structure[i].name, Login_Structure[i].LoginID, Login_Structure[i].password);
    }
}

void Editprofile_Function() {
    while (1) {
        printf("\nEnter username to edit (0 to stop): ");
        scanf("%s", Edit_Structure[Edit_Index].name);

        if (strcmp(Edit_Structure[Edit_Index].name, "0") == 0) {
            break;
        }

        int userFound = 0;
        for (int i = 0; i < Login_Index; i++) {
            if (strcmp(Edit_Structure[Edit_Index].name, Login_Structure[i].name) == 0) {
                userFound = 1;
                char Editstring[20];
                printf("%s Edit Options (username/password): ", Edit_Structure[Edit_Index].name);
                scanf("%s", Editstring);

                if (strcmp(Editstring, "username") == 0) {
                    printf("Enter new username: ");
                    scanf("%s", Login_Structure[i].name);
                    printf("Username updated\n");

                    // Update username in Bookride_Structure if already booked
                    for (int j = 0; j < Bookride_Index; j++) {
                        if (strcmp(Bookride_Structure[j].name, Edit_Structure[Edit_Index].name) == 0) {
                            strcpy(Bookride_Structure[j].name, Login_Structure[i].name);
                        }
                    }
                } else if (strcmp(Editstring, "password") == 0) {
                    printf("Enter new password: ");
                    scanf("%s", Login_Structure[i].password);
                    printf("Password updated\n");
                } else {
                    printf("Invalid edit option. Please choose 'username' or 'password'.\n");
                }

                break; // Exit loop once user is found and edited
            }
        }

        if (!userFound) {
            printf("%s not found\n", Edit_Structure[Edit_Index].name);
        }

        Edit_Index++;
    }
}

void Viewride_Function() {
    printf("\nMenu:\n");
    for (int i = 0; i < ridesize; i++) {
        printf("ID: %d\tName: %s\tPrice: %.2f\n", Menu_Structure[i].rideID, Menu_Structure[i].ridename, Menu_Structure[i].rideprice);
    }
}

void initride() {
    Menu_Structure[0].rideID = 1;
    strcpy(Menu_Structure[0].ridename, "Passapp");
    Menu_Structure[0].rideprice = 3.29;

    Menu_Structure[1].rideID = 2;
    strcpy(Menu_Structure[1].ridename, "Moto");
    Menu_Structure[1].rideprice = 2.50;

    Menu_Structure[2].rideID = 3;
    strcpy(Menu_Structure[2].ridename, "Car");
    Menu_Structure[2].rideprice = 5.58;

    Menu_Structure[3].rideID = 4;
    strcpy(Menu_Structure[3].ridename, "Tuktuk");
    Menu_Structure[3].rideprice = 1.89;

    ridesize = 4;
}

//still need to fx error , when login a user,when change the user profile it doesnt get updatad 

void Bookride_Function() {
    while (1) {
        printf("\nLogin name or 0 to stop: ");
        char loginname[MAX_NAME_LENGTH];
        scanf("%s", loginname);
        
        if (strcmp(loginname, "0") == 0) {
            break;
        }
        
        int rideID;
        printf("Ride ID: ");
        scanf("%d", &rideID);
        
        float distance;
        printf("Enter distance (in km): ");
        scanf("%f", &distance);
        
        int rideFound = 0;
        for (int i = 0; i < ridesize; i++) {
            if (rideID == Menu_Structure[i].rideID) {
                rideFound = 1;
                
                // Calculate total price
                float total = distance * Menu_Structure[i].rideprice;
                
                // Store booking details
                strcpy(Bookride_Structure[Bookride_Index].name, loginname);
                Bookride_Structure[Bookride_Index].BookID = rideID;
                Bookride_Structure[Bookride_Index].Bookprice = Menu_Structure[i].rideprice;
                Bookride_Structure[Bookride_Index].bookTotal = total;
                Bookride_Structure[Bookride_Index].distance = distance;
                
                printf("%s Book Ride ID %d Price/Km %.2f Total %.2f\n", 
                       Bookride_Structure[Bookride_Index].name, rideID, Menu_Structure[i].rideprice, total);
                
                Bookride_Index++;
                break;
            }
        }
        
        if (!rideFound) {
            printf("Invalid Ride ID\n");
        }
    }
}

void Viewbooking_Function() {
    printf("\nUsername\tBooking ID\tPrice/Km\tDistance\tTotal\n");
    for (int i = 0; i < Bookride_Index; i++) {
        printf("%s\t\t%d\t\t%.2f\t\t%.2f\t\t%.2f\n", Bookride_Structure[i].name, 
               Bookride_Structure[i].BookID, Bookride_Structure[i].Bookprice, 
               Bookride_Structure[i].distance, Bookride_Structure[i].bookTotal);
    }
}


void Cancel_Function() {
    while (1) {
        printf("\nUsername or 0 to stop: ");
        scanf("%s", Cancel_Structure[Cancel_Index].username);
        if (strcmp(Cancel_Structure[Cancel_Index].username, "0") == 0) {
            break;
        }
        printf("Cancel Ride ID: ");
        scanf("%d", &Cancel_Structure[Cancel_Index].rideID);

        int rideFound = 0;
        for (int i = 0; i < Bookride_Index; i++) {
            if (strcmp(Cancel_Structure[Cancel_Index].username, Bookride_Structure[i].name) == 0
                && Cancel_Structure[Cancel_Index].rideID == Bookride_Structure[i].BookID) {
                rideFound = 1;
                Cancel_Structure[Cancel_Index].canceltotal = Bookride_Structure[i].bookTotal;
                printf("Username %s Cancel Booking ID %d Total: %.2f\n", Cancel_Structure[Cancel_Index].username,
                       Cancel_Structure[Cancel_Index].rideID, Cancel_Structure[Cancel_Index].canceltotal);
                // Shift remaining bookings up
                for (int j = i; j < Bookride_Index - 1; j++) {
                    Bookride_Structure[j] = Bookride_Structure[j + 1];
                }
                Bookride_Index--;
                break;
            }
        }

        if (!rideFound) {
            printf("Invalid Username or Ride ID\n");
        }

        Cancel_Index++;
    }
}

void Rate_Function() {
    while (1) {
        printf("\nEnter Rate(0 to stop): ");
        scanf("%d", &Rate_Structure[Rate_Index].scale);
        if(Rate_Structure[Rate_Index].scale==0)
        {
            break;
        }
        if (Rate_Structure[Rate_Index].scale >= 1 && Rate_Structure[Rate_Index].scale <= 5) {
            printf("Rating Successful\n");
        } else {
            printf("Invalid Rate (1-5)\n");
        }
        Rate_Index++;
    }
}

void Logout_Function() {
    while (1) {
        printf("\nUser name (0 to stop): ");
        scanf("%s", Logout_Structure[logout_Index].name);
        if (strcmp(Logout_Structure[logout_Index].name, "0") == 0) {
            break;
        }

        int userFound = 0;
        for (int i = 0; i < Login_Index; i++) {
            if (strcmp(Logout_Structure[logout_Index].name, Login_Structure[i].name) == 0) {
                userFound = 1;
                printf("Successfully logged out: %s\n", Login_Structure[i].name);
                break;
            }
        }

        if (!userFound) {
            printf("User not found\n");
        }

        logout_Index++;
    }
}
