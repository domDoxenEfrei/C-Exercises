#include <stdio.h>

void bounce (int n);

int main () {

int n;
printf("Please enter a positive integer: ");
scanf("%d", &n);

bounce (n);

return 0;
}

void bounce (int n) {
    if (n<=0) {
        return;
    } else {
        printf("%d ",n);
        bounce (n-1);
        printf("%d ",n);
    }

}