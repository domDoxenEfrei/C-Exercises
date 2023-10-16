#include <stdio.h>

int main(void) {

    int base, power, powerOut=1;
    printf("Please enter two integers separated by a comma: ");
    scanf("%d, %d",&base, &power);
    
    for (int i=1; i <= power; i++) {
        powerOut *= base;
    }
    
    printf("%d raised to the power of %d is %d.", base, power, powerOut);
    return 0;
}