#include <stdio.h>

int findPosition (int tab[], int size, int n){
    for (int i=0; i<size; i++) {
        if (tab[i] ==n){
            return i;
        }
    }
    return -1;
}

int main () {
    int array[] = {0,1,2,1,2,3,4,5,6,7};
    int size = sizeof(array) / sizeof(array[0]);
    int n;

    printf("Please enter an integer to search for: ");
    scanf("%d", &n);
    
    printf("Here is the array: ");
    for (int i=0; i<size; i++) {
        printf("%d ", array[i]);
    }

    int position = findPosition (array, size, n);
        if (position !=-1){
            printf("\nThe first position of %d in the array was %d\n", n,position);
        } else {
            printf("\n%d was not found in the array.",n);
        }
    return 0;
}