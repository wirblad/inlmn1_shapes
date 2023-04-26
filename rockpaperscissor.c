#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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
        else if(!strcmp(computerChoice,"Scissor")){
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

void saveToFile(char *result, char *date, float averageWins){
    
    FILE *fOpen = fopen("stats.txt", "w");
    if(fOpen == NULL){
        printf("FEL!!! - Filen kunde inte öppnas");
        fclose(fOpen);
        return;
    }

    fputs(result,fOpen);
    fprintf(fOpen, "\n"); 
    fputs(date,fOpen);
    fprintf(fOpen, "\n"); 
    fprintf(fOpen, "%f", averageWins); 
    fprintf(fOpen, "\n"); 
    fclose(fOpen);

}

void showStats(int userWins, int computerWins){

    time_t rawtime;
    struct tm *info;
    char buffer[50];

    time( &rawtime );
    info = localtime( &rawtime );
    strftime(buffer,80,"%x - %I:%M%p", info);
    printf("You played at : %s\n", buffer);
    float averageWins = ((double)userWins/(double)(userWins+computerWins) * 100); 
    if(isnan(averageWins))
        averageWins=0;

    if(userWins > computerWins){
        printf("YOU WON THE GAME\n");
        saveToFile("WON", buffer, averageWins);
    }
    else if(userWins < computerWins){
        printf("SORRY YOU LOST THE GAME\n");
        saveToFile("LOST",buffer, averageWins);
    }
    else{
        printf("ITS A DRAW\n");
        saveToFile("PLAYED DRAW",buffer,averageWins);
    }
    printf("You won %.2f %% of the times\n", averageWins);
}

void loadfile(){

    FILE *fOpen = fopen("stats.txt", "r");

    if(fOpen == NULL){
        printf("FEL!!! - Filen kunde inte öppnas");
        fclose(fOpen);
        return;
    }

    char result[250] = "";
    char date[250] = "";
    char average[250] = "";

    fgets(result,250,fOpen); 
    fgets(date,250,fOpen); 
    fgets(average,250,fOpen);

    printf("LAST TIME YOU PLAYED WAS: %sAND YOU %sYOUR WINRATE WAS: %s\n",date,result,average);
    
    fclose(fOpen); 

}

void rockpaperscissor(){
    
    loadfile();
    srand(time(NULL));
    char computerChoice[100] = "";
    char continuePlaying = '\0';
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
    showStats(userWins, computerWins);
}

