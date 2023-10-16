#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    float temperature;
    Point location;  
} Temperature;

Temperature average_temperature(Temperature t1, Temperature t2) { 
    Temperature avg;
    avg.temperature = (t1.temperature + t2.temperature) / 2;
    avg.location.x = (t1.location.x + t2.location.x) / 2;
    avg.location.y = (t1.location.y + t2.location.y) / 2;
    return avg;
}

int main() {
    Temperature t1 = {80, {10.0, 20.0}};
    Temperature t2 = {90, {15.0, 25.0}};

    Temperature avg = average_temperature(t1, t2);

    printf("Average Temperature: %.2f\n", avg.temperature);
    printf("Average Location (x, y): (%.2f, %.2f)\n", avg.location.x, avg.location.y);

    return 0;
}
