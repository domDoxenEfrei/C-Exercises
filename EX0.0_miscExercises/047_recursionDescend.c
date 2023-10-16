#include <stdio.h>

void ascend (int n);
void descend (int n);

int main () {

    int n;
    printf("Enter a positive integer: ");
    scanf("%d",&n);

    printf("Ascending order: ");
    ascend (n);
    printf("\n");

    printf("Descending order: ");
    descend (n);
    printf("\n");

return 0;
}

// 1 2 3 4 5 
void ascend (int n) {
    if (n<=0) {
        printf("Please enter a positive integer.");
        return;
    }
    if (n>1){
        ascend (n-1);
        printf("%d ",n);
    } else {
        printf("%d ",n);
    }

}

void descend (int n) {
    if (n<=0) {
        printf("Please enter a positive integer.");
        return;
    } if(n>=1) {
        printf("%d ", n);
        descend (n-1);
    }
}