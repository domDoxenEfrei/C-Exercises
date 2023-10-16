#include <stdio.h>

int main(void){

float Number;
printf ("Please input a real number: ");
scanf ("%f", &Number);

int wholeNumber = (int)Number;
float decimalNumber = Number-wholeNumber;

printf ("Your number is: %f \n", Number);
printf ("The integer of that number is: %d \n", wholeNumber);
printf ("The decimal part of that number is %f \n", decimalNumber);

}