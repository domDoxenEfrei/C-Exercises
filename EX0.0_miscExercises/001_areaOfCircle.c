#include <stdio.h>
int main(){

printf ("Please input the radius of a circle:  \n");

int radius;
scanf("%d",&radius);

//int radius = 2;

const float PI=3.14159;

float area = radius*radius*PI;

printf("The area of the circle of radius %d is %f", radius, area);
}