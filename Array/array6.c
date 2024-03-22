#include<stdio.h>
#include<stdlib.h>
#define Max_Room 20
#define Max_Name_Length 50

int main()
{
    char name[Max_Room][Max_Name_Length];
    int Roomnumber[Max_Room];
    int Roomstatus[Max_Room]={0};
    int currentguess=0;
    int choice;
    int choice1;
    int choice2;
    int choice3;
    int totalRoom=0;
    int roomtocheckin;
    int roomtocheckout;
    int price[Max_Room];

    printf("\nWelcome to our hotel\n");
    do{
        printf("1.Book Room\n");
        printf("2.Check in room\n");
        printf("3.Check out room\n");
        printf("4.Exit\n");
        printf("Enter your choice(1-4)");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
             if(currentguess<Max_Room)
             {
                printf("What's your name for guess %d",currentguess+1);
                scanf("%s", name[currentguess]);
                printf("Enter a room number to book for customer %d",currentguess+1);
                scanf("%d",&Roomnumber[currentguess]);
    
                printf("Our room to serve for you\n");
                printf("1.Room with 1 bed\n");
                printf("2.Room with 2 bed\n");
                printf("What's your choice");
                scanf("%d",&choice1);
                switch(choice1)
                {
                    case 1:
                    {

                        printf("Your room fee will be 15$\n");
                        printf("Room condition\n");
                        printf("1.Standard room with fan\n");
                        printf("2.VIP room with A.C\n");
                        printf("3.No device added \n");
                        printf("What your choice");
                        scanf("%d",&choice2);
                        switch(choice2)
                        {
                            case 1:
                            price[currentguess]=20;
                            printf("Your price to rent will be 20$ with additional fee 5$\n");
                            break;
                            case 2:
                            price[currentguess]=30;
                            printf("Your price to rent will be 30$with additional fee 15$\n");
                            break;
                            case 3:
                            price[currentguess]=15;
                            printf("NO Addtional fee\n");
                            break;
                            default:
                            printf("INVALID CHOICE\n");
                        } 
                        break;   
                    }
                    case 2 :
                    {
                        printf("Your room fee will be 25$\n");
                        printf("Room condition\n");
                        printf("1.Standard room with fan\n");
                        printf("2.VIP room with A.C\n");
                        printf("3.No additional add\n");
                        printf("What's your choice");
                        scanf("%d",&choice3);
                        switch(choice3)
                        {
                            case 1 :
                                price[currentguess]=35;
                                printf("Your price to rent will be 35$ with additional fee 10$\n");
                             break;
                             case 2:
                                 price[currentguess]=55;
                                 printf("Your price to rent will be 55$ with additional fee 30$\n");
                                 break;
                            case 3:
                                price[currentguess]=25;
                                printf("NO additional fee\n");
                                break;
                            default :
                            {
                                printf("Unvalid choice\n");
                            }
                        }
                    break;
                    }

                
                }
                Roomstatus[Roomnumber[currentguess-1]]=1;
                currentguess++;
                totalRoom++;
            break;
             }
            }
            case 2:
            {
                printf("Enter the room number to check in");
                scanf("%d",&roomtocheckin);
                if(roomtocheckin>=1 && roomtocheckin<=Max_Room)
                {
                    if(Roomstatus[Roomnumber[currentguess-1]]==0)
                    {
                        printf("Enter name for the guess");
                        scanf("%s", name[roomtocheckin-1]);
                        Roomstatus[Roomnumber[currentguess-1]]=1;
                        printf("Guess check in successfully\n");

                    }
                    else{
                        printf("All room has been book\n");
                    }
                }
                else{
                    printf("NO ROOM FOR YOU\n");
                }
            break;
            }
            case 3:
            {
                printf("Enter the room to check out");
                scanf("%d",&roomtocheckout);
                if(roomtocheckout>=1 && roomtocheckout<=Max_Room)
                {
                    if(Roomstatus[Roomnumber[roomtocheckout-1]]==1)
                    {
                        Roomstatus[Roomnumber[roomtocheckout-1]]=0;
                        printf("Room check out sucessfully\n");
                    }
                    else{
                        printf("Check out room unsuccessfully\n");
                    }
                }
                else {
                    printf("NO ROOM FOR YOU TO CHECK OUT\n");

                }
            break;
            }
            case 4:
            {
                exit(0);
            }
            default :{
                printf("UNMATCHABLE CHOICE\n");
            }

        }
    }while(choice!=4);
    for(int i=0;i<=currentguess;i++)
    {
        printf("Name %s room %d price %f", name[i],Roomnumber[i],price[i]);
    }

}

   