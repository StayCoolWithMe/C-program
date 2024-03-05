#include<stdio.h>
int main()
{
    int math[3];
    int physic[3];
    int chemistry[3];
    char name[3][20];
    float total[50];
    
    for(int i=0;i<3;i++)
    {
        printf("Enter the student name");
        scanf("%s",name[i]);
        printf("Enter the score for math");
        scanf(" %d",&math[i]);
         printf("Enter the score for physic");
        scanf("%d",&physic[i]);
         printf("Enter the score for chemistry");
        scanf("%d",&chemistry[i]);
    }
    for(int i=0;i<3;i++)
    {
        printf("Name:%s\n", name[i]);   
        printf("Math:%d\n", math[i]);
        printf("Physic:%d\n", physic[i]);
        printf("Chemistry:%d\n", chemistry[i]);
        total[i] = math[i] + physic[i] + chemistry[i];
        printf("Total:%.0f\n", total[i]);
    }
}
