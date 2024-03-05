#include<stdio.h>
int main()
{
    int num;
    char name[3][5];
    printf("Enter numnber of product ");
    scanf("%d",&num);
    while(num<0)
    {
        printf("Invalid number,plase enter a valid one");
        scanf("%d",&num);
    }
    int choice;
    for(int i=0;i<num;i++){
    printf("\nproduct No:%d\n",i+1);
    printf("Menu\n");
    printf("1.add product\n");
    printf("2.view product\n");
    printf("3.Modify product\n");
    printf("Enter your choice");
    scanf("%d",&choice);
    switch(choice)
        {
        case 1:
        printf("Enter product name");
        scanf("%s", name[i]);
        printf("product successfully added\n");
        break;
        default:
        printf("Unmatch\n"); 
        break;
        }
    }
    for(int i=0;i<num;i++){
        printf("\nproduct No:%d\n",i+1);
        printf("product name is %s\n",name[i]);
    }
}
