#include<stdio.h>
#include<stdlib.h>
#define Max_Student 50
#define Max_Name_Lenght 50
int main()
{
    char name[Max_Student][Max_Name_Lenght];
    int math[Max_Student];
    int science[Max_Student];
    int english[Max_Student];
    int choice;
    int currentstudent=0;
    int studentnumber=0;
    float average[Max_Student];
    printf("Enter student number");
    scanf("%d",&studentnumber);
    while(studentnumber<1 ||  studentnumber>Max_Student)
    {
        printf("UNVALID,PLEASE ENTER A ACCEPTABLE ONE\n");
         scanf("%d",&studentnumber);       
    }
    do{
        printf("1.student informantion\n");
        printf("2.score average\n");
        printf("3.student grade\n");
        printf("4.Exit\n");
        printf("Enter your choice(1-4)");
        scanf("%d",&choice);
        switch (choice)
        {

        case 1 :
        {
            if(currentstudent<studentnumber)
            {

                printf("Enter name for student %d", currentstudent+1);
                scanf("%s", name[currentstudent]);
                printf("Enter math grade for student %d", currentstudent+1);
                scanf("%d",&math[currentstudent]);
                printf("Enter english grade for student %d", currentstudent+1);
                scanf("%d",&english[currentstudent]);
                printf("Enter science grade for student %d", currentstudent+1);
                scanf("%d",&science[currentstudent]);
                currentstudent++;
            }
            else
            {
                printf("Student reach\n");
            }
        break;
        }
        case 2:
        {
                for(int i=0;i<currentstudent;i++)
                {
                average[currentstudent]=(math[i]+science[i]+english[i])/3;
                printf("Average score for student %d will be %.1f\n\n",i+1,average[currentstudent]);
                }
         break;
        }
        case 3:
        {
            for(int i=0;i<currentstudent;i++)
            {
             average[currentstudent]=(math[i]+science[i]+english[i])/3;
            if(average[currentstudent]>=60)
            {
                printf("CONGRATULATION !! YOU HAVE PASSED\n");
            
            }
            else{
                printf("YOU HAVE FAILED\n");
            }
            }
        break;
        }
        case 4:
        {
            exit(0);
        }
        default :
        {
            printf("INVALID CHOICE,PLEASE ENTER THE RIGHT ONE");
        }
        }
      
    }while(choice!=4);
}