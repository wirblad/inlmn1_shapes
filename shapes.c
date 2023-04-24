#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "safeinput.h"
#include "shapes.h"



void rectangle(){
    float lenght = 0;
    float width = 0;
    while(!GetInputFloat("Enter lenght of rectangle: ", &lenght))
        printf("Please enter a number!!\n");
    while(!GetInputFloat("Enter width of rectangle: ", &width))
        printf("Please enter a number!!\n");
    printf("Area of rectangle is: %.2f and perimeter is: %.2f\n\n", calc_area_rectangle(lenght, width), calc_perimeter_rectangle(lenght, width));
}

float calc_area_rectangle(float lenght, float width){
    return lenght*width;
}

float calc_perimeter_rectangle(float lenght, float width){
    return (2*lenght)+(2*width);
}

void parallelogram(){
    float base = 0;
    float side2 = 0;
    float hight = 0;
    while(!GetInputFloat("Enter base of parallelogram: ", &base))
        printf("Please enter a number!!\n");
    while(!GetInputFloat("Enter other side of parallelogram: ", &side2))
        printf("Please enter a number!!\n");
    while(!GetInputFloat("Enter hight of paralellogram: ", &hight))
        printf("Please enter a number!!\n");
    printf("Area of parallelogram is: %.2f and perimeter is: %.2f\n\n", calc_area_parallelogram(base,hight), calc_perimeter_parallelogram(base, side2));
}

float calc_area_parallelogram(float base, float hight){
    return base*hight;
}

float calc_perimeter_parallelogram(float base, float side2){
    return (2*base)+(2*side2);
}

void triangle(){
    float base = 0;
    float side2 = 0;
    float side3 = 0;
    float hight = 0;
    while(!GetInputFloat("Enter base of triangle: ", &base))
        printf("Please enter a number!!\n");
    while(!GetInputFloat("Enter second side of triangle: ", &side2))
        printf("Please enter a number!!\n");
    while(!GetInputFloat("Enter third side of triangle: ", &side3))
        printf("Please enter a number!!\n");
    while(!GetInputFloat("Enter hight of triangle: ", &hight))
        printf("Please enter a number!!\n");
    printf("Area of triangle is: %.2f and perimeter is: %.2f\n\n", calc_area_triangle(base,hight), calc_perimeter_triangle(base,side2,side3));
}

float calc_area_triangle(float base, float hight){
    return (base*hight)/2;
}

float calc_perimeter_triangle(float base, float side2, float side3){
    return base+side2+side3;
}

void circle(){
    float radie = 0;
    while(!GetInputFloat("Enter radie of circle: ", &radie))
        printf("Please enter a number!!\n");
    printf("Area of circle is: %.2f and perimeter is: %.2f\n\n", calc_area_circle(radie), calc_perimeter_circle(radie));
}

double calc_area_circle(float radie){
    
    return radie*3.14;
}

double calc_perimeter_circle(float radie){
    
    return 2*radie*3.14;
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







