#include <stdio.h>

void identify(char name[20], int y)
{
    printf("Hello %s, you are %d years old\n", name, y);
}
int findmax(int x,int y)
{
    if(x>y)
    {
        return x;
    }
    else
    {
        return y;
    }
    
}

int main()
{
    char name[20];
    int age;

    printf("What's your name? ");
    scanf("%s", name);
    
    printf("What's your age? ");
    scanf("%d", &age);
    
    identify(name, age);

    identify(name,age);
    int max=findmax(5,9);
    printf("%d",max);
}
