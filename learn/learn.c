
#include<stdio.h>
int main()
{
    int ID[]={1,4,5,8,9,10,11};
    for(int i=0; i < sizeof(ID)/sizeof(ID[0]); i++) {
        printf("%d\n",ID[i]);
    }
    
  
}

