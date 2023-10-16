#include <stdio.h>

int recursionSum (int n);

int main () {

    int n;
    printf("Please enter a positive integer: ");
    scanf("%d",&n);

    int result = recursionSum(n);
    printf("The sum of numbers 1 to %d is %d", n, result);
    
}

int recursionSum (int n) {
    if (n<=0) {
        return;
    } else {
        return n + recursionSum(n-1);
    }

}