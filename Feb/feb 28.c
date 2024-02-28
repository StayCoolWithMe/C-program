#include<stdio.h>

int main ()
{
    int number=5;
    for(int i=0;i<number;++i)
    {   
        char name[20];
        int age;
        int choice;
        float cost;
        int choice1;
        printf("Enter your name");
        scanf("%s", name);
        printf("Enter your age");
        scanf("%d",&age);
        printf("\nMenu:");
        printf("\n1.Phone serive");
        printf("\n2.Laptop service");
        printf("\n3.Accessories");
        printf("\nEnter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
           
            printf("At your service\n");
            break;
            case 2:
          
            printf("At your service");
            break;
            case 3:
            printf("\nWhat's your catagory:");
            printf("\n1.power-supply");
            printf("\n2.Memory");
            printf("\nEnter your needed accessory");
            scanf("%d",&choice1);
            switch (choice1)
            {
                case 1:
                printf("your cost 10$\n");
                cost=10;
                break;
                case 2:
                printf("your cost 20$\n");
                cost=20;
                break;
                default:
                printf("Invalid choice\n");
                break;
            }
           
            break;
        }   
    }

}
