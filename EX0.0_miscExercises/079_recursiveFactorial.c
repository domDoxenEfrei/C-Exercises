#include <stdio.h>

long factorial(long n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void test_factorial() {
    struct {
        long input;
        long expected;
    } test_cases[] = {
        {0, 1},
        {1, 1},
        {5, 120},
        {10, 3628800}
    };

    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
        long result = factorial(test_cases[i].input);
        if (result == test_cases[i].expected) {
            printf("Test case %d passed\n", i + 1);
        } else {
            printf("Test case %d failed. Expected: %ld, Actual: %ld\n", i + 1, test_cases[i].expected, result);
        }
    }
}

int main() {
    long num = 5;
    long result = factorial(num);
    printf("%ld\n", result); 
    test_factorial();
    return 0;
}
