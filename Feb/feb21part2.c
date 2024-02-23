#include<stdio.h>
#include<string.h>

int main() {
    int experince;
    int education_level;
    char Education[50];
    char certificate[2]; // changed to an array of characters to store a string

    printf("Enter your job experience: ");
    scanf("%d", &experince);
    
    printf("\nEnter your education level:\n1.High school \n2.Bachelor \n3.Master or higher: ");
    scanf("%d", &education_level);
    scanf("%s", Education); // reading education level as a string
    
    printf("\nDo you have the certificate (y/n): ");
    scanf("%s", certificate);
    
    if (experince >= 5 && (strcmp("Master", Education) == 0)) {
        printf("You are eligible to join.\n");
    }
    else if (experince >= 3 && (strcmp("Bachelor", Education) == 0)) {
        printf("You are eligible to join.\n");
    }
    else if (experince >= 6 && (strcmp("High", Education) == 0)) {
        printf("You are eligible to join.\n");
    }
    else {
        printf("You are not eligible to join.\n");
    }
    return 0;
}
