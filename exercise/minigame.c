#include<stdio.h>
#include<string.h>

int main() {
    int choice1, choice2, choice3;
    float totalpoint = 0;
    int point1 = 0, point2 = 0, point3 = 0, point4 = 0, point5 = 0;
    char choice4[50], choice5[50];
    char playAgain;
    
    do {
        printf("Question 1:During World War II, Germany tried to attack Russia. It failed. You would think that the Germans would have learned not to make the same mistake again. Who was the leader that tried to conquer Russia?\n");
        printf("1.Winston Churchill\n");
        printf("2.Adolf Hitler\n");
        printf("3.Benito Mussolini\n");
        printf("4.General Tojo\n");
        printf("Enter your choice(1-4): ");
        scanf("%d", &choice1);
        
        if (choice1 == 2) {
            printf("Congratulation you got it right\n");
            point1 = 1;
        } else {
            printf("NO!You got it wrong\n");
            point1 = 0;
        }
        
        printf("Question 2:This singer made the same mistake many times. In fact, a song title tells us that she made the same mistake. She played with [his] heart and got lost in the game.Who is the singer?\n");
        printf("1.Avril Lavigne\n");
        printf("2. Christina Aguilera\n");
        printf("3.Jennifer Lopez\n");
        printf("4.Britney Spears\n");
        printf("Enter your choice(1-4): ");
        scanf("%d", &choice2);
        
        if (choice2 == 4) {
            printf("Congratulation you got it right\n");
            point2 = 1;
        } else {
            printf("NO!You got it wrong\n");
            point2 = 0;
        }
        
        printf("Question 3:Carolco Pictures had several blockbuster hits, but in 1995 they created a movie that turned out to be a complete flop. Then, in the same year, the company went bankrupt when they made the same mistake by making another movie that was a complete flop. It became the company's last movie. What movie caused Carolco Pictures to become bankrupt?\n");
        printf("1. The Changeling \n");
        printf("2. The Silent Partner \n");
        printf("3. Cutthroat Island \n");
        printf("4. Jacob's Ladder \n");
        printf("Enter your choice(1-4): ");
        scanf("%d", &choice3);
        
        if (choice3 == 3) {
            printf("Congratulation you got it right\n");
            point3 = 1;
        } else {
            printf("NO!You got it wrong\n");
            point3 = 0;
        }
        
        printf("Bonus Question\n");
        printf("Who is the 9 tails Jinchuriki? ");
        scanf("%s", choice4);
        
        if (strcmp(choice4, "naruto") == 0 || strcmp(choice4, "Naruto") == 0)
         {
            printf("Congratulation you got it right\n");
            point4 = 1;
        } else {
            printf("NO!You got it wrong\n");
            point4 = 0;
        }
        
        printf("Bonus question2\n");
        printf("Who eliminated the whole Uchiha clan? ");
        scanf("%s", choice5);
        
        if (strcmp(choice5, "Itachi") == 0 || strcmp(choice5, "itachi") == 0 || strcmp(choice5, "Uchiha Itachi") == 0 || strcmp(choice5, "uchiha Itachi") == 0) 
        {
            printf("Congratulation you got it right\n");
            point5 = 1;
        } else {
            printf("NO!You got it wrong\n");
            point5 = 0;
        }
        
        totalpoint += point1 + point2 + point3 + point4 + point5;
        printf("Your total points: %.2f\n", totalpoint);
        if(totalpoint>=3)
        {
            printf("You are tough\n");

        }
        else
        {
            printf("You should review class slide\n");
        }

        
        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);
        
    } while (playAgain == 'Y' || playAgain == 'y');
    

}

