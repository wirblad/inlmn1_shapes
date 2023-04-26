#include <stdio.h>
#include <stdbool.h>
#include "safeinput.h"
#include "shapes.h"
#include "calculator.h"
#include "rockpaperscissor.h"

int main(){

    while(true){
        
        int choice = 0;
        GetInputInt("1.Shapes\n2.Calculator\n3.Rock Paper Scissor\n4.Exit\n", &choice);
        if(choice == 1)
            shapes();
        if(choice == 2)
            calculator();
        if(choice == 3)
            rockpaperscissor();
        if(choice == 4)
            break;
    }
}