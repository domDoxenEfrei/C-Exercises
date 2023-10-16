#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Position {
    float x, y;
} Position;

float distanceBetween(Position position1, Position position2) {
    float distance = sqrt(pow(position1.x - position2.x, 2) + pow(position1.y - position2.y, 2));
    return distance;
}

Position* closestPositions(Position* positions, int positionsArraySize, Position query, float maxDistance, int* result_size) {
    Position* closest = NULL;
    *result_size = 0;

    for (int i = 0; i < positionsArraySize; i++) {
        float dist = distanceBetween(query, positions[i]);

        if (dist <= maxDistance) {
            closest = (Position*)realloc(closest, (*result_size + 1) * sizeof(Position));
            closest[*result_size] = positions[i];
            (*result_size)++;
        }
    }
    return closest;
}

int main() {
    int numPoints = 5;
    Position points[numPoints]; // Declares an array of 'Position' structures with 5 spaces

    points[0].x = 0;
    points[0].y = 0;
    points[1].x = 10;
    points[1].y = 10;
    points[2].x = 15;
    points[2].y = 15;
    points[3].x = 20;
    points[3].y = 20;
    points[4].x = 25;
    points[4].y = 25;

    float maximumDistance = 20.0;

    Position query;
    query.x = 5;
    query.y = 5;

    int result_size = 0;
    Position* closest = closestPositions(points, numPoints, query, maximumDistance, &result_size);

    printf("Closest positions within a max distance of %.2f:\n", maximumDistance);
    for (int i = 0; i < result_size; i++) {
        printf("x=%.2f, y=%.2f\n", closest[i].x, closest[i].y);
    }

    free(closest);
    return 0;
}
