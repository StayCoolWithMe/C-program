#include<stdio.h>
int main()
{
    char name[10];
    float math[10];
    float physic[10];
    float chemistry[10];
    float average[10];
    float totalmath;
    float totalphysic;
    float totalchemistry;
        printf("Enter your name");
        scanf("%s",name);
    for(int i=0;i<3;i++)
    {
        printf("your score for day %d\n",i+1);
        printf("Enter your math score");
        scanf("%f",&math[i]);
        printf("Enter your physic score");
        scanf("%f",&physic[i]);
        printf("Enter your chemistry score");
        scanf("%f",&chemistry[i]);
    }
    for(int i=0;i<3;i++)
    {
        totalmath+=math[i];
        totalchemistry+=chemistry[i];
        totalphysic+=physic[i];
        average[i]+=(totalmath+totalchemistry+totalphysic)/3;
    }
    for(int i=0;i<3;i++)
    {
        printf("Your average for the last 3 days is %f",average[i]);
    }

    
}