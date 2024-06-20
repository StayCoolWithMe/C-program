#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This is structures
struct product {
    char name[999];
    int quantity;
    int price;
};

struct customer {
    char name[999];
    char sex[999];
};

struct order_info {
    int orderID;
    char customername[999];
    char prodctname[999];
    int quantity;
    float totalprice;
};

// This is variable
int product_index = 0;
int customer_index = 0;
int order_index = 0;
int choice;

// This is structure name
struct product product[100];
struct customer customer[100];
struct order_info order[100]; 

// This is function
void new_product();
void new_customer();
void product_display();
void place_order(); 
void order_history();

int main() {
    printf("1. Add Product\n2. Add new customer\n3. Product Display\n4. Place an order\n5. Display order history\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            new_product();
            break;
        case 2:
            new_customer();
            break;
        case 3:
            product_display();
            break;
        case 4:
            place_order();
            break;
        case 5:
            order_history();
            break;
        default:
            printf("Invalid choice. Please enter another one");
            scanf("%d", &choice);
    }
}

void new_product() {
    while (1) {
        printf("Product Name (0 to enter): ");
        scanf("%s", product[product_index].name);
        if (strcmp(product[product_index].name, "0") == 0) {
            break;
        }
        printf("Product Quantity: ");
        scanf("%d", &product[product_index].quantity);
        printf("Product Price: ");
        scanf("%d", &product[product_index].price);
        product_index++;
    }
}

void new_customer() {
    while (1) {
        printf("Enter the customer Name (0 to stop): ");
        scanf("%s", customer[customer_index].name);
        if (strcmp(customer[customer_index].name, "0") == 0) {
            break;
        }
        printf("Enter %s sex: ", customer[customer_index].name);
        scanf("%s", customer[customer_index].sex);
        customer_index++;
    }
}

void product_display() {
    printf("Product Name\tStock Quantity\tPrice Per Unit\n");
    for (int i = 0; i < product_index; i++) {
        printf("%s\t\t%d\t\t%d\n", product[i].name, product[i].quantity, product[i].price);
    }
}

void place_order() {
    while (1) {
        printf("Enter customer Name(0 to stop):");
        scanf("%s", order[order_index].customername);
        if (strcmp(order[order_index].customername, "0") == 0) {
            break;
        }
        // This generates a number between 1 and infinity
        srand(time(NULL));
        int randomNumber = rand();
        order[order_index].orderID = randomNumber; // Store the order ID
        printf("Order ID: %d\n", randomNumber);
        printf("Enter the product Name:");
        scanf("%s", order[order_index].prodctname);

        // This is how you handle the name 
        int productFound = 0;
        int i;
        for (i = 0; i < product_index; i++) {
            if (strcmp(order[order_index].prodctname, product[i].name) == 0) {
                productFound = 1;
                break;
            }
        }
        if (!productFound) {
            printf("Invalid product requirement, Please enter a valid one: ");
            scanf("%s", order[order_index].prodctname);
            continue;
        }

        printf("Enter the Quantity:");
        scanf("%d", &order[order_index].quantity);
        // Handle the quantity error
        if (order[order_index].quantity > product[i].quantity) {
            printf("We don't have enough product for your requirement, we stocked %d product\n", product[i].quantity); 
            printf("Please enter a valid one: ");
            scanf("%d", &order[order_index].quantity);
        }
        order[order_index].totalprice = product[i].price * order[order_index].quantity;
        printf("Your total price will be %f\n", order[order_index].totalprice);
        order_index++;
    }
}

void order_history() {
    printf("Customer Name\tOrder ID\tProduct Name\tQuantity\tTotal Price\n");
    for (int i = 0; i < order_index; i++) {
        printf("%s\t\t%d\t\t%s\t\t%d\t\t%f\n", order[i].customername, order[i].orderID, order[i].prodctname, order[i].quantity, order[i].totalprice);
    }
}
