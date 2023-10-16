#include <stdio.h>

int recursionPower (int n,int p);

int main () {

    int n;
    int p;
    printf("Please enter two positive integers separated by a comma. They will be used for a power calculation (base, power): ");
    scanf("%d, %d",&n,&p);

    int result = recursionPower(n,p);

    printf("%d raised to the power of %d is %d\n", n,p,result);

    return 0;
}

int recursionPower (int n, int p) {
    if (p==0) {
        return 1;
    } else {
        return n*recursionPower (n,p-1);
    }

}