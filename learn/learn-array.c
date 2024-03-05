#include<stdio.h>

int main()
{
    int num[50];
    int limit;
    printf("Input the limit: ");
    scanf("%d", &limit);
    for(i = 0; i<= limit ;i++)
    {
        printf("Input the number: ");
        scanf("%d", &num[i]);
        printf("%d\n", num[i]);
    }
    for(i = 0; i<= limit ;i++)
    {
        printf("%d\n", num[i]);
    }
}