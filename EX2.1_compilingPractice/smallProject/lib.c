#include "header.h"
#include <math.h>

float calculate_distance(Point point) {
    //pythagorean theorem
    float distance = sqrt(point.x * point.x + point.y * point.y);
    return distance;
}
