#include<stdio.h>
int main()
{
    int num[100];
    int element;
    float sum=0;
    float average;
    printf("Enter the number of element\n");
    scanf("%d",&element);
    for(int i=0;i<element;i++)
    {
        printf("Enter  number %d  ",i+1);
        scanf("%d",&num[i]);
        sum+=num[i];
    }
    if(element>0)
    {
        average=sum/element;
        printf("The average will be %f",average);

    }
}