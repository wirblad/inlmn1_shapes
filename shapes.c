#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "safeinput.h"

void rectangle(){

    float lenght = 0;
    float width = 0;
    GetInputFloat("Enter lenght of rectangle: ", &lenght);
    GetInputFloat("Enter width of rectangle: ", &width);
    printf("Area of rectangle is: %.2f and perimeter is: %.2f\n", lenght*width, (2*lenght)+(2*width));
}

void parallelogram(){

    float base = 0;
    float side2 = 0;
    float hight = 0;
    GetInputFloat("Enter base of parallelogram: ", &base);
    GetInputFloat("Enter other side of parallelogram: ", &side2);
    GetInputFloat("Enter hight of paralellogram: ", &hight);
    printf("Area of parallelogram is: %.2f and perimeter is: %.2f\n", base*hight, 2*(base+side2));
}

void triangle(){

    float base = 0;
    float side2 = 0;
    float side3 = 0;
    float hight = 0;
    GetInputFloat("Enter base of triangle: ", &base);
    GetInputFloat("Enter second side of triangle: ", &side2);
    GetInputFloat("Enter third side of triangle: ", &side3);
    GetInputFloat("Enter hight of triangle: ", &hight);
    printf("Area of triangle is: %.2f and perimeter is: %.2f\n", (base*hight)/2, base+side2+side3);
}

void circle(){

    float radie = 0;
    const float pi = 3.14;
    GetInputFloat("Enter radie of circle: ", &radie);
    printf("Area of circle is: %.2f and perimeter is: %.2f\n", radie*pi, 2*pi*radie);

}


void shapes(){

    while(true){

        char choice[100] = "";
        GetInput("Rectangle\nParallelogram\nTriangle\nCircle\nExit\nEnter your choice:", choice,sizeof(choice));

        if(!strcmp("Rectangle", choice) || !strcmp("rectangle", choice))
            rectangle();
        if(!strcmp("Parallelogram", choice) || !strcmp("parallelogram", choice))
            parallelogram();
        if(!strcmp("Triangle", choice) || !strcmp("triangle", choice))
            triangle();
        if(!strcmp("Circle", choice) || !strcmp("circle", choice))
            circle();
        if(!strcmp("Exit", choice) || !strcmp("exit", choice))
            break;
    }
}







