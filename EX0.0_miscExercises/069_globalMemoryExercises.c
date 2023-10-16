#include <stdio.h>

int globalArray[10]= {34,5,67,4,37,23,4,8,67,20};
int globalArraySize = sizeof(globalArray)/sizeof(globalArray[0]);

void printArray (int *array, int *arraySize);
void arrayMinMax (int *array, int *arraySize); //First Exercise
void reverseArray (int *array, int *arraySize); //Second Exercise
int sumArray (int *array, int *arraySize); //Third Exercise
void swapElements (int *array); //Fourth Exercise
void removeDuplicates (int *array, int *arraySize); //Fifth Exercise
void sortAscending (int *array, int *arraySize); //Sixth Exercise

int main () {

    int *ptrA = globalArray;
    int *ptrASize = &globalArraySize;

    printArray (ptrA, ptrASize);
    arrayMinMax (ptrA, ptrASize);

    printf("Reversing the Array\n");
    reverseArray (ptrA, ptrASize);
    printArray (ptrA, ptrASize);
    int arraySum = sumArray(ptrA,ptrASize);
    printf("The sum total of all array elements is: %d\n", arraySum);

    printf("Reversing the Array... Again\n");
    reverseArray (ptrA, ptrASize);
    printArray (ptrA, ptrASize);

    printf("Swapping Elements 1&2\n");
    swapElements (ptrA);
    printArray (ptrA, ptrASize);

    printf("Removing Duplicates\n");
    removeDuplicates (ptrA,ptrASize);
    printArray (ptrA, ptrASize);

    printf("Sort Ascending...\n");
    sortAscending(ptrA, ptrASize);
    printArray (ptrA, ptrASize);
    
    return 0;
}   

//printArray function
void printArray (int *array,int *arraySize) {
    
    printf("The values of the global array: ");
    for (int i = 0; i<*arraySize; i++) {
        printf("%d, ", array[i]);
    }

    //printf("\nThe addresses of each element...\n");
    //for (int i = 0; i<*arraySize; i++) {
    //    printf("Element %2d: Value = %2d: Address = %9p\n",i, array[i], (void *)array[i]);
    //}
    printf("\n..........\n");
}

//First Exercise: array max
void arrayMinMax (int *array, int *arraySize) {    
    int arrayMin = array[0];
    int arrayMax = array [0];
    int i=1;

    while (i < *arraySize) {
        if (array[i] < arrayMin) {
            arrayMin = array[i];
        }
        if (array[i] > arrayMax) {
            arrayMax = array[i];
        }
        i++;
    }
    printf("The array Max is %d, and the array Min is %d\n", arrayMax, arrayMin);

}

//SecondExercise: reverse array and save
void reverseArray (int *array, int *arraySize) {
    int i=0;
    int j = *arraySize-1;
    int temp;

    while (i<j) {
        temp = array[i];
        array[i]=array[j];
        array[j] = temp;        
        i++;
        j--;
    }
}

//thirdExercise: sum Array
int sumArray (int *array, int *arraySize){
    int arraySum=0;
    for (int i = 0; i<*arraySize; i++) {
        arraySum += array[i];
    }
    return arraySum;
}

//fourthExercise: swap pos 1 and pos 2
void swapElements (int *array) {
    int temp = array[1];
    array[1] = array[2];
    array[2]= temp;
}

//fifthExercise: remove duplicates
void removeDuplicates (int *array, int *arraySize) {
    
    int uniqueCount = 1;

    for (int i = 1; i<*arraySize; i++){
        int isDuplicate=0;

        for (int j=0;j<uniqueCount; j++){
            if (array[i]==array[j]) {
                isDuplicate=1;
                break;
            }
        }
    
    if (!isDuplicate) {
        array[uniqueCount]=array[i];
        uniqueCount++;
    }
    }
    *arraySize = uniqueCount;
}

// SixthExercise: sort smallest to largest
void sortAscending(int *array, int *arraySize) {
    int swapped; 

    do {
        swapped = 0; 

        for (int i = 0; i < *arraySize - 1; i++) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1; 
            }
        }
    } while (swapped);
}