/*
We want to compute the distance between two Position struct (float x,y)

The formula is 
SQRT (x1−x2)^2 +(y1−y2)^2

1. Create the struct Position 
2. code a function float distance(Position p1, Position p2) that returns the position between to positions
*/

#include <stdio.h>
#include <math.h>

typedef struct Position {
    float x,y;
} Position;

float distanceBetween (struct Position position1, struct Position position2) {
    float distance = sqrt(pow(position1.x - position2.x, 2) + pow(position1.y - position2.y, 2));
    return distance;
}

int main () {

    Position position1;
        position1.x = 25;
        position1.y = 25;
    

    Position position2;
        position2.x = 0;
        position2.y = 0;

    float distance = distanceBetween (position1, position2);
    printf("The distance between the two points is: %g", distance);
    return 0;

}


