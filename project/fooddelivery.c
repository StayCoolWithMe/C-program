#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

/** 
 * GLOBAL VARIABLES
 */
int choice;
int Register_Index = 0;
int Login_Index = 0;
int MenuSize = 0;
int orderIndex = 0;
int searchIndex = 0;
int updateIndex = 0;

/** 
 * STRUCTURES
 */
struct Register_Structure {
    char name[999];
    int RegisterID;
    char password[999];
};
struct Register_Structure Register_Structure[999];

struct Login_Structure {
    char name[999];
    int loginID;
    char password[999];
};
struct Login_Structure Login_Structure[999];

struct menuitem {
    char name[999];
    int id;
    float price;
};
struct menuitem menuitem[999];

struct order {
    float total;
    char username[999];
    char productNames[10][999]; // Assuming a user can order up to 10 items at once
    int quantities[10];
    int numItems;
    char status[50]; // Added status field
};
struct order order[999];

struct update_structure {
    char updateName[999];
    int updateID;
    char updatepassword[999];
};
struct update_structure update_structure[999];

/** 
 *! FUNCTION PROTOTYPES
 */
void Register();
void Login();
void Viewmenu();
void Searchmenu();
void Placeorder();
void ViewCart();
void Trackorder();
void Updateprofile();
void Contract();
void initializeMenu();

int main() {
    srand(time(NULL));
    initializeMenu();

    while (1) {
    
        printf("\nMenu\n1.Register\n2.Log in\n3.View Menu\n4.Search Menu\n5.Place Order\n6.View Order\n7.Track Order\n8.Update Profile\n9.Contract Support\n10.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Register();
                break;
            case 2:
                Login();
                break;
            case 3:
                Viewmenu();
                break;
            case 4:
                Searchmenu();
                break;
            case 5:
                Placeorder();
                break;
            case 6:
                ViewCart();
                break;
            case 7:
                Trackorder();
                break;
            case 8:
                Updateprofile();
                break;
            case 9:
                Contract();
                break;
            case 10:
                exit(0);
                break;
            default:
                printf("\033[1;31mInvalid choice, please enter another one:\033[0m\n");
                break;
        }
    }
    return 0;
}

/** 
 * FUNCTION DEFINITIONS
 */
void Register() {
    while (1) {
        printf("\nRegister Username (0 to stop): ");
        scanf("%s", Register_Structure[Register_Index].name);

        if (strcmp(Register_Structure[Register_Index].name, "0") == 0) {
            break;
        }

        int randomNumber = 1 + rand();
        Register_Structure[Register_Index].RegisterID = randomNumber;
        printf("%s ID: %d\n", Register_Structure[Register_Index].name, Register_Structure[Register_Index].RegisterID);
        printf("User Password: ");
        scanf("%s", Register_Structure[Register_Index].password);
        Register_Index++;
    }
}

void Login() {
    while (1) {
        printf("\nLog In Username (0 to stop): ");
        scanf("%s", Login_Structure[Login_Index].name);

        if (strcmp(Login_Structure[Login_Index].name, "0") == 0) {
            break;
        }

        printf("User Password: ");
        scanf("%s", Login_Structure[Login_Index].password);

        int RegisterFound = 0;
        for (int i = 0; i < Register_Index; i++) {
            if (strcmp(Login_Structure[Login_Index].name, Register_Structure[i].name) == 0 ||
                strcmp(Login_Structure[Login_Index].password, Register_Structure[i].password) == 0) {
                RegisterFound = 1;
                Login_Structure[Login_Index].loginID = Register_Structure[i].RegisterID;
                printf("Log In Successful\n");
                break;
            }
        }
        if (!RegisterFound) {
            printf("Log In Failed\n");
        }
        Login_Index++;
    }
}

void Viewmenu() {
    printf("\nMenu:\n");
    for (int i = 0; i < MenuSize; i++) {
        printf("ID: %d, Name: %s, Price: %.1f\n", menuitem[i].id, menuitem[i].name, menuitem[i].price);
    }
}

void initializeMenu() {
    menuitem[0].id = 1;
    strcpy(menuitem[0].name, "Burger");
    menuitem[0].price = 2.99;

    menuitem[1].id = 2;
    strcpy(menuitem[1].name, "Pasta");
    menuitem[1].price = 1.99;

    menuitem[2].id = 3;
    strcpy(menuitem[2].name, "Fried_Chicken");
    menuitem[2].price = 4.99;

    menuitem[3].id = 4;
    strcpy(menuitem[3].name, "Chicken_Nugget");
    menuitem[3].price = 3.99;

    menuitem[4].id = 5;
    strcpy(menuitem[4].name, "Ice_Cream");
    menuitem[4].price = 1.59;

    menuitem[5].id = 6;
    strcpy(menuitem[5].name, "Lemonade");
    menuitem[5].price = 2.00;

    menuitem[6].id = 7;
    strcpy(menuitem[6].name, "Meatball");
    menuitem[6].price = 4.00;

    menuitem[7].id = 8;
    strcpy(menuitem[7].name, "Sushi");
    menuitem[7].price = 3.58;

    menuitem[8].id = 9;
    strcpy(menuitem[8].name, "Grilled_Chicken");
    menuitem[8].price = 7.99;

    menuitem[9].id = 10;
    strcpy(menuitem[9].name, "Omelet");
    menuitem[9].price = 3.28;

    MenuSize = 10;
}

void Searchmenu() {
    char searchName[999];
    int searchFound = 0;
    printf("\nEnter item name to search: ");
    scanf("%s", searchName);
    for (int i = 0; i < MenuSize; i++) {
        if (strcmp(searchName, menuitem[i].name) == 0) {
            searchFound = 1;
            printf("Search Found\n");
            printf("ID: %d, Name: %s, Price: $%.2f\n", menuitem[i].id, menuitem[i].name, menuitem[i].price);
            break;
        }
    }
    if (!searchFound) {
        printf("Searched item not found\n");
    }
}


/**
 *!There are some error with the total calculation  */ 
void Placeorder() {
    int id, quantity;
    float final;

    while (1) {
        printf("\nEnter Your name (0 to stop): ");
        scanf("%s", order[orderIndex].username);

        if (strcmp(order[orderIndex].username, "0") == 0) {
            break;
        }

        int UserOrderFound = 0;
        int loggedInIndex = -1;

        // Check if the user is logged in
        for (int i = 0; i < Login_Index; i++) {
            if (strcmp(order[orderIndex].username, Login_Structure[i].name) == 0) {
                UserOrderFound = 1;
                loggedInIndex = i;
                break;
            }
        }

        if (!UserOrderFound) {
            printf("You are not logged in\n");
            continue;
        }

        final = 0;
        order[orderIndex].numItems = 0;

        while (1) {
            printf("Enter Item ID to purchase (0 to stop): ");
            scanf("%d", &id);
            if (id == 0) {
                break;
            }

            // Check if the item ID is valid
            int itemFound = 0;
            for (int i = 0; i < MenuSize; i++) {
                if (id == menuitem[i].id) {
                    itemFound = 1;
                    printf("Item Found: %s, Price: $%.2f\n", menuitem[i].name, menuitem[i].price);
                    printf("Enter the quantity: ");
                    scanf("%d", &quantity);

                    if (quantity <= 0 || quantity > 10) {
                        printf("\033[1;31mInvalid quantity, please enter another one (1-10):\033[0m\n");
                        continue;
                    }

                    // Add the item to the order
                    float itemTotal = menuitem[i].price * quantity;
                    strcpy(order[orderIndex].productNames[order[orderIndex].numItems], menuitem[i].name);
                    order[orderIndex].quantities[order[orderIndex].numItems] = quantity;
                    order[orderIndex].total += itemTotal;
                    order[orderIndex].numItems++;

                    final += itemTotal;
                    break;
                }
            }
            if (!itemFound) {
                printf("Item not found\n");
                continue;
            }
        }

        printf("%s Order placed successfully! Total: $%.2f\n", order[orderIndex].username,final);

        // Assign the status of the order
        strcpy(order[orderIndex].status, "Pending");

        // Increment the order index for the next order
        orderIndex++;
    }
}

void ViewCart() {
    printf("\n%-15s %-15s %-10s %-10s\n", "Username", "Product", "Quantity", "Total");
    for (int i = 0; i < orderIndex; i++) {
        for (int j = 0; j < order[i].numItems; j++) {
            if (j == 0) {
                // Print the username and total only once per order
                printf("%-15s %-15s %-10d %-10.1f\n", order[i].username, order[i].productNames[j], order[i].quantities[j], order[i].total);
            } else {
                // For subsequent items, leave the username and total blank
                printf("%-15s %-15s %-10d\n", "", order[i].productNames[j], order[i].quantities[j]);
            }
        }
    }
}


void Trackorder() {
    char username[999];
    printf("\nEnter username to track orders: ");
    scanf("%s", username);

    int orderFound = 0;
    printf("\n%-15s %-15s %-10s %-10s %-10s\n", "Username", "Product", "Quantity", "Total", "Status");
    for (int i = 0; i < orderIndex; i++) {
        if (strcmp(order[i].username, username) == 0) {
            orderFound = 1;
            for (int j = 0; j < order[i].numItems; j++) {
                if (j == 0) {
                    // Print the username, total, and status only once per order
                    printf("%-15s %-15s %-10d %-10.2f %-10s\n", order[i].username, order[i].productNames[j], order[i].quantities[j], order[i].total, order[i].status);
                } else {
                    // For subsequent items, leave the username, total, and status blank
                    printf("%-15s %-15s %-10d\n", "", order[i].productNames[j], order[i].quantities[j]);
                }
            }
        }
    }
    if (!orderFound) {
        printf("No orders found for the username: %s\n", username);
    }
}


void Updateprofile() {
    char changename[999];
    int updatefound = 0;

    while (1) {
        printf("\nEnter username to update (0 to stop): ");
        scanf("%s", changename);

        if (strcmp(changename, "0") == 0) {
            break;
        }

        updatefound = 0;
        for (int i = 0; i < Login_Index; i++) {
            if (strcmp(Login_Structure[i].name, changename) == 0) {
                updatefound = 1;

                printf("What do you want to change (username/password): ");
                char option[20];
                scanf("%s", option);

                if (strcmp(option, "username") == 0) {
                    printf("Enter new username: ");
                    scanf("%s", Login_Structure[i].name);
                    printf("Username updated successfully!\n");
                } else if (strcmp(option, "password") == 0) {
                    printf("Enter new password: ");
                    scanf("%s", Login_Structure[i].password);
                    printf("Password updated successfully!\n");
                } else {
                    printf("Invalid option\n");
                }
                break;
            }
        }
        if (!updatefound) {
            printf("Username not found. Please enter a valid username.\n");
        }
    }
}

void Contract() {
    printf("\nAny concern, please contact us via email: V010utha@gmail.com\n");
}
