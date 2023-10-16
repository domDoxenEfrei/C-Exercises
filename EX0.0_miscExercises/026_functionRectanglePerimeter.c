#include <stdio.h>

float calculateRectangleArea (float length, float width) {
    float rectangleArea = length*width;
    return rectangleArea;
}

float calculateRectanglePerimeter (float length, float width){
    float rectanglePerimeter = ((2*length)+(2*width));
    return rectanglePerimeter;
}

int main () {
    float length, width, area,perimeter;
    printf("Please enter the length of the rectangle:");
    scanf ("%f",&length);
    printf("Please enter the width of the rectangle:");
    scanf ("%f",&width);

    area = calculateRectangleArea(length,width);
    perimeter=calculateRectanglePerimeter(length,width);
    printf("The area of a rectangle with length %g, and width %g, is %g. \n", length, width, area);
    printf("The perimeter of a rectangle with length %g, and width %g, is %g. \n", length, width, perimeter);

    return 0;
}