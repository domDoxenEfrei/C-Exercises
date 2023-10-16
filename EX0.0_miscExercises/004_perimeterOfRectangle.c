#include <stdio.h>

int main(void){

float rectLength;
float rectWidth;

    printf("What is the length of your rectangle: ");
    scanf ("%f", &rectLength);

    printf("\n What is the width of your rectangle: ");
    scanf ("%f", &rectWidth);
    
    float rectArea = rectLength*rectWidth;
    float rectPerimeter = 2*rectLength + 2*rectWidth;

    printf("The length of your rectangle is %g and the width of your rectangle is %g \n", rectLength, rectWidth);
    printf("That makes the area of your rectangle %g \n", rectArea);
    printf("And the perimeter %g", rectPerimeter);
}