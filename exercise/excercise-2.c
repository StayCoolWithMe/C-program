#include<stdio.h>
int main()
{
    int cost[]={20,40,50,70};
    int num=sizeof(cost)/sizeof(cost[0]);
    int no;
    printf("Enter customer No");
    scanf("%d",&no);
    for(int i=0;i<num;i++)
    {
        printf("Price of item %d :%d\n",i+1,cost[i]);
    }
}