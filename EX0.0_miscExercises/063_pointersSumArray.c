#include <stdio.h>

int sumArray (int *arrayPtr, int size);

int main () {
    int array[]={1,2,3,4,5,6,7,8,9};
    int size = sizeof(array)/sizeof(array[0]);

    int *arrayPtr = array;
    int result = sumArray (arrayPtr, size);
    printf("%d is the sum.",result);

}

int sumArray (int *arrayPtr, int size) {
    int sum = 0;
    for (int i=0; i<size; i++) {
        sum += *arrayPtr;
        arrayPtr++;
    }
    return sum;
}