#include <stdio.h>

int fibonacci(int n);

int main() {
    int n;
    printf("Please enter a positive integer to find the nth number in the Fibonacci sequence: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Please enter a non-negative integer.\n");
    } else {
        int result = fibonacci(n);
        printf("The %dth number in the Fibonacci sequence is: %d\n", n, result);
    }
    
    return 0;
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;  // Base case: Fib(0) is 0
    } else if (n == 1) {
        return 1;  // Base case: Fib(1) is 1
    } else {
        // Recursive case: Fib(n) = Fib(n-1) + Fib(n-2)
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
