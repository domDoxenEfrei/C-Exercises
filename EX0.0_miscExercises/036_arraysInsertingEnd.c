#include <stdio.h>

    int main () {

    int array[] = {1,2,3,4,5};
    int originalLength = sizeof(array) / sizeof(array[0]);
    int n;

    printf("Please enter an integer: ");
    scanf("%d", &n);

    int newLength = originalLength + 1;
    int newArray[newLength];

    for (int i=0; i<originalLength; i++){
        newArray[i] = array [i];
    }

    newArray[newLength-1]=n;

    printf("Original Array: ");

    for (int i=0; i<originalLength; i++) {
        printf("%d ", array[i]);
    }

    printf("\n New Array: ");
    for (int i=0; i<newLength; i++) {
        printf("%d ",newArray[i]);
    }
    return 0;
}