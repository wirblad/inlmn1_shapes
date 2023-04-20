#include <stdio.h>
#include <stdbool.h>
#include "safeinput.h"
#include "shapes.h"
#include "calculator.h"

int main(){

    while(true){
        
        int choice = 0;
        GetInputInt("1.Shapes\n2.Calculator\n3.Exit\n", &choice);
        if(choice == 1)
            shapes();
        if(choice == 2)
            calculator();
        if(choice == 3)
            break;
    }
}