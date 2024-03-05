#include<stdio.h>
int main()
{
  int rentalPrices[] = {150, 200, 120, 180, 250};
  int numRentals = sizeof(rentalPrices) / sizeof(rentalPrices[0]);
  int option;
  int quantity;
  int totalCost = 0;
  printf("Available rental option:\n"); 
  for (int i = 0; i < numRentals; i++)
  {
    printf("%d.option $%d per unit \n", i + 1, rentalPrices[i]);
  }
  for (int i = 0; i < numRentals; i++) 
  {
    printf("Enter the option number to rent(0 to exit): ");
    scanf("%d", &option);
    if (option == 0)
    {
      break;
    }
    else if (option >= 1 && option <= numRentals)
    {
      printf("Enter the quantity: ");
      scanf("%d", &quantity);
      switch (option)
      {
      case 1:
        totalCost += 150 * quantity;
        break; 
      case 2:
        totalCost += 200 * quantity;
        break;
      case 3:
        totalCost += 120 * quantity;
        break;
      case 4:
        totalCost += 180 * quantity;
        break;
      case 5:
        totalCost += 250 * quantity;
        break;
      default:
        printf("Invalid option \n");
        
      }
    }
    else
    {
      printf("Invalid option try again\n");
      i--; 
    }
  }
  printf("Total cost for renting: $%d\n", totalCost);
}