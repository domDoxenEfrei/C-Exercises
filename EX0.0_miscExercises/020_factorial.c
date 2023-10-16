#include <stdio.h>

int main () {
    int userNum; 
    long long factorial=1;
    
    while (1) {
        printf("Please provide an integer: ");
        scanf("%d", &userNum);
    
        if (userNum>0){
            break;
        } else {
            printf("Factorial not defined for negative numbers. ");
        }

    }
    
    for (int i=1; i<=userNum; i++) {
            factorial *=i;
            printf("%lld\n", factorial); //print out after each step
        }

    printf("The factorial of %d is %lld.", userNum, factorial);
    return 0;
}
