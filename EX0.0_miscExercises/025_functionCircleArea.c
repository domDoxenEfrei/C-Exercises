#include <stdio.h>

float calculateCircleArea (float radius) {
    const float pi = 3.14159;
    float circleArea = pi*radius*radius;
    return circleArea;
}

float calculateCircleCircumference (float radius){
    const float pi = 3.14159;
    float circleCircumference = 2*pi*radius;
    return circleCircumference;
}

int main () {
    float radius, area, circumference;
    printf("Please enter the radius of a circle:");
    scanf ("%f",&radius);
    
    area = calculateCircleArea(radius);
    circumference=calculateCircleCircumference(radius);
    printf("The area of a circle with radius %g, is %g. \n", radius, area);
    printf("The circumference of a circle with radius %g, is %g. \n", radius, circumference);

    return 0;
}