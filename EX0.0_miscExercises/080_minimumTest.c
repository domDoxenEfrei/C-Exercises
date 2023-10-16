#include <stdio.h>

float minimum_three_numbers (float n1, float n2, float n3){
    float min = n1;
    if (n2 < min) {
        min = n2;
    } 
    
    if (n3 < min) {
        min = n3;
    }
    return min;
}

void test_minimum_three_numbers () {
    float test_cases [][3] = {
        {5.5,3.2,4.8},
        {5,5,5},
        {7.1,9.8,4.2},
        {-1,-2,-3}
    };

    for (int i=0; i < sizeof(test_cases)/sizeof(test_cases[0]); i++) {
        float n1 = test_cases [i][0];
        float n2 = test_cases [i][1];
        float n3 = test_cases [i][2];

        float result = minimum_three_numbers(n1,n2,n3);
        printf("Test case %d: min(%g, %g, %g) = %g\n", i + 1, n1, n2, n3, result);
    }
}


int main () {
    test_minimum_three_numbers();
    return 0;
}