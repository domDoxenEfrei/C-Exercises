#include <stdio.h>

float absolute_value(float number){
    if (number < 0){
        number = number * -1;
        return number;
    } else { 
        return number;
    }
}

int main () {
    float num = -5;
    float result = absolute_value(num);
    printf("%g", result);
}