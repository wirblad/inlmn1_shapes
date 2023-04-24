#include <stdio.h>
#include "safeinput.h"
#include "calculator.h"


float add(float firstNumber, float secondNumber){
   return firstNumber+secondNumber;
}

float subtraction(float firstNumber, float secondNumber){
   return firstNumber-secondNumber;
}

double multiplie(float firstNumber, float secondNumber){
   return firstNumber*secondNumber;
}

double division(float firstNumber, float secondNumber){
   return firstNumber/secondNumber;
}

int modulus(float firstNumber, float secondNumber){
   return ((int)firstNumber%(int)secondNumber);
}

void calculator(){

   float firstNumber = 0;
   while(!GetInputFloat("Enter first number: ", &firstNumber))
      printf("Please enter a number!!\n");
   float secondNumber = 0;
   while(!GetInputFloat("Enter first number: ", &secondNumber))
      printf("Please enter a number!!\n");
   //printf("YOUR NUMBER %.2f and %.2f\n\n\n", firstNumber, secondNumber);

   char userChooseOperator;

   while(!GetInputChar("Choose operator: +, -, *, /, m(modulus):  ", &userChooseOperator)){
      printf("Please choose an operator");
   }

   //printf("TEST AV OPERATOR ---> %c\n\n", userChooseOperator);

   if(userChooseOperator == '+'){
      printf("The sum of %.2f and %.2f equals %.2f\n", firstNumber, secondNumber, add(firstNumber, secondNumber));
   }
   else if(userChooseOperator == '-'){
      printf("%.2f subtracted by %.2f equals %.2f\n", firstNumber, secondNumber, subtraction(firstNumber, secondNumber));
   }
   else if(userChooseOperator == '*'){
      printf("%.2f multiplied by %.2f equals %.2f\n", firstNumber, secondNumber, multiplie(firstNumber, secondNumber));
   }
   else if(userChooseOperator == '/'){
      printf("%.2f divided by %.2f equals %.2f\n", firstNumber, secondNumber, division(firstNumber, secondNumber));
   }
   else if(userChooseOperator == 'm'){
      printf("%.2f divided by %.2f gives the remainder %d", firstNumber, secondNumber, modulus(firstNumber,secondNumber));
   }
}

