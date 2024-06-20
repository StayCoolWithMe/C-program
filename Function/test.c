#include<stdio.h>
int main()
{
    FILE *fp=fopen("../duckquack.txt","w");
    fprintf(fp,"Hello world");
    fclose(fp);
}