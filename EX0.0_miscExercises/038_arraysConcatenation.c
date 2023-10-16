#include <stdio.h>

int main () {

    int arrayOne[] = {1,2,3,4,5};
    int arrayOneSize = sizeof(arrayOne)/sizeof(arrayOne[0]);

    int arrayTwo [] = {6,7,8,9,10};
    int arrayTwoSize = sizeof(arrayTwo)/sizeof(arrayTwo[0]);

    int combinedArraySize = arrayOneSize + arrayTwoSize;
    int combinedArray [combinedArraySize];
    
    for (int i=0; i<arrayOneSize; i++){
        combinedArray[i]=arrayOne[i];
    }

    for (int i=0; i<arrayTwoSize; i++) {
        combinedArray[i+arrayOneSize]=arrayTwo[i];
    }

    printf("Array One: ");
    for (int i=0; i<arrayOneSize; i++){
        printf("%d ",arrayOne[i]);
    }
    
    printf("\nArray Two: ");
    for (int i=0; i<arrayTwoSize; i++){
        printf("%d ", arrayTwo[i]);
    }

    printf("\nCombined Array: ");
    for (int i=0; i<combinedArraySize; i++){
        printf("%d ",combinedArray[i]);
    }
}