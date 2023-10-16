#include "header.h"
#include <stdio.h>

float calculate_distance(Point point); //declare the function defined in lib.c

int main() {
    Point point;
    point.x = 24.24;
    point.y = 42.42;

    float distance = calculate_distance(point);

    printf("Coordinates: (%.2f, %.2f)\n", point.x, point.y);
    printf("Distance from the origin: %.2f\n", distance);

    return 0;
}

