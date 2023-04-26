#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "safeinput.h"
#include "rockpaperscissor.h"

void play(char *userChoice, char *computerChoice, int *userWins, int *computerWins){

    printf("YOU CHOSSE %s and computer choose %s\n", userChoice, computerChoice);

    if(!strcmp(userChoice,"Rock") || !strcmp(userChoice,"rock")){
        if(!strcmp(computerChoice,"Rock")){
            printf("IT'S A DRAW\n");   
        }
        else if(!strcmp(computerChoice,"Paper")){
            printf("YOU LOOSE\n");
            *computerWins = *computerWins +1;   
        }
        else if(!strcmp(computerChoice,"Scissor")){
            printf("YOU WIN\n");
            *userWins = *userWins +1;
        }
    }

    else if(!strcmp(userChoice,"Paper") || !strcmp(userChoice,"paper")){
        if(!strcmp(computerChoice,"Paper")){
            printf("IT'S A DRAW\n");   
        }
        else if(!strcmp(computerChoice,"Scisoot")){
            printf("YOU LOOSE\n");
            *computerWins = *computerWins +1;   
        }
        else if(!strcmp(computerChoice,"Rock")){
            printf("YOU WIN\n");
            *userWins = *userWins +1;
        }
    }

    else if(!strcmp(userChoice,"Scissor") || !strcmp(userChoice,"scissor")){
        if(!strcmp(computerChoice,"Scissor")){
            printf("IT'S A DRAW\n");   
        }
        else if(!strcmp(computerChoice,"Rock")){
            printf("YOU LOOSE\n");
            *computerWins = *computerWins +1;   
        }
        else if(!strcmp(computerChoice,"Paper")){
            printf("YOU WIN\n");
            *userWins = *userWins +1;
        }
    }
}

void getComputerChoice(int random, char *computerChoice){

    if(random == 1)
        strcpy(computerChoice, "Rock");
    else if(random == 2)
        strcpy(computerChoice, "Paper");
    else if(random == 3)
        strcpy(computerChoice, "Scissor");
}

bool checkUserInput(char *userChoice){

        if(!strcmp(userChoice,"Rock") || !strcmp(userChoice,"rock") || 
                !strcmp(userChoice,"Paper") || !strcmp(userChoice,"paper") || 
                !strcmp(userChoice,"Scissor") || !strcmp(userChoice,"scissor"))
            return true;       
        else   
            return false; 
}

void rockpaperscissor(){
    
    srand(time(0));
    char computerChoice[100] = "";
    char continuePlaying;
    int userWins = 0;
    int computerWins = 0;
    while(true){

        char userChoice[100] = "";
        while(!checkUserInput(userChoice)){
            GetInput("Choose Rock, Paper or Scissor\n", userChoice,sizeof(userChoice));
        }
        getComputerChoice((rand() % 3) + 1, computerChoice);
        
        play(userChoice, computerChoice, &userWins, &computerWins);
           
        printf("You have won: %d times and computer have won: %d times\n\n", userWins, computerWins);
        GetInputChar("Press any key to continue or press 'N' to quit", &continuePlaying);
        if(continuePlaying == 'N' || continuePlaying == 'n')
            break; 
    }
}

