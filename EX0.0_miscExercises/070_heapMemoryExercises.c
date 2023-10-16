#include <stdio.h>
#include <stdlib.h>

void printArray(int *array, int *arraySize);
void arrayMinMax(int *array, int *arraySize); // First Exercise - modifies heap array in place
void reverseArray(int *array, int *arraySize); // Second Exercise - modifies heap array in place
int sumArray(int *array, int *arraySize); // Third Exercise - modifies heap array in place
void swapElements(int *array); // Fourth Exercise - modifies heap array in place
void removeDuplicates(int *array, int *arraySize); // Fifth Exercise - modifies heap array in place
void sortAscending(int *array, int *arraySize); // Sixth Exercise - modifies heap array in place
void insertBeginning(int **array, int *arraySize, int insertNumber); //Seventh Exercise - inserts at beginning of array
void insertEnd(int **array, int *arraySize, int insertNumber); //Eighth Exercise - inserts at end of array
void insertPosFive(int **array, int *arraySize, int insertNumber); //Ninth Exercise - inserts at position 5
void deleteBeginning(int **array, int *arraySize); //Tenth Exercise - deletes at beginning of array
void deleteEnd(int **array, int *arraySize); //Eleventh Exercise - deletes at end of array
void deletePosFive(int **array, int *arraySize); //Twelfth Exercise - deletes at position 5


int main() {

    int *ptrA = NULL;
    int *ptrASize = NULL;
    int globalArraySize = 10;

    // Allocate memory for the array
    ptrA = (int *)malloc(globalArraySize * sizeof(int));
    if (ptrA == NULL) {
        // Handle allocation failure
        exit(1);
    }

    // Initialize the array
    int initialValues[] = {34, 5, 67, 4, 37, 23, 4, 8, 67, 20};
    for (int i = 0; i < globalArraySize; i++) {
        ptrA[i] = initialValues[i];
    }

    ptrASize = &globalArraySize;

    printf("The original array:\n");
    printArray(ptrA, ptrASize);
    arrayMinMax(ptrA, ptrASize);

    printf("Reversing the Array\n");
    reverseArray(ptrA, ptrASize);
    printArray(ptrA, ptrASize);
    int arraySum = sumArray(ptrA, ptrASize);
    printf("The sum total of all array elements is: %d\n", arraySum);

    printf("Reversing the Array... Again\n");
    reverseArray(ptrA, ptrASize);
    printArray(ptrA, ptrASize);

    printf("Swapping Elements 1&2\n");
    swapElements(ptrA);
    printArray(ptrA, ptrASize);

    printf("Removing Duplicates\n");
    removeDuplicates(ptrA, ptrASize);
    printArray(ptrA, ptrASize);

    printf("Sort Ascending...\n");
    sortAscending(ptrA, ptrASize);
    printArray(ptrA, ptrASize);

    int insertNumber = 42;
    printf("Insert number at the beginning: 42\n");
    insertBeginning(&ptrA, ptrASize, insertNumber);
    printArray(ptrA, ptrASize);

    printf("Insert number at the end: 42\n");
    insertEnd(&ptrA, ptrASize, insertNumber);
    printArray(ptrA, ptrASize);

    printf("Insert number at position five: 42\n");
    insertPosFive(&ptrA, ptrASize, insertNumber);
    printArray(ptrA, ptrASize);

    printf("Deletes number at the beginning...\n");
    deleteBeginning(&ptrA, ptrASize);
    printArray(ptrA, ptrASize);

    printf("Deletes number at the end...\n");
    deleteEnd(&ptrA, ptrASize);
    printArray(ptrA, ptrASize);

    printf("Deletes number at position five...\n");
    deletePosFive(&ptrA, ptrASize);
    printArray(ptrA, ptrASize);
    
    free(ptrA);
    return 0;
}

// printArray function
void printArray(int *array, int *arraySize) {

    printf("The values of the global array: ");
    for (int i = 0; i < *arraySize; i++) {
        printf("%d, ", array[i]);
    }

    printf("\n..........\n");
}

// First Exercise: array max
void arrayMinMax(int *array, int *arraySize) {
    int arrayMin = array[0];
    int arrayMax = array[0];
    int i = 1;

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

// Second Exercise: reverse array and save
void reverseArray(int *array, int *arraySize) {
    int i = 0;
    int j = *arraySize - 1;
    int temp;

    while (i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
}

// Third Exercise: sum Array
int sumArray(int *array, int *arraySize) {
    int arraySum = 0;
    for (int i = 0; i < *arraySize; i++) {
        arraySum += array[i];
    }
    return arraySum;
}

// Fourth Exercise: swap pos 1 and pos 2
void swapElements(int *array) {
    int temp = array[1];
    array[1] = array[2];
    array[2] = temp;
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

//seventhExercise: insert beginning
void insertBeginning(int **array, int *arraySize, int insertNumber) {
    int newSize = *arraySize +1;

    int *newArray = (int *)malloc(newSize * sizeof(int));
        if (newArray == NULL){
            exit(1);
        }
    for (int i = 0; i < *arraySize; i++) {
        newArray[i + 1] = (*array)[i];
    }

    newArray[0] = insertNumber;

    free(*array);  
    *array = newArray;
    *arraySize = newSize;
}

//eighthExercise: insert end
void insertEnd(int **array, int *arraySize, int insertNumber) {
    int newSize = *arraySize +1;

    int *newArray = (int *)malloc(newSize * sizeof(int));
        if (newArray == NULL){
            exit(1);
        }

    for (int i = 0; i < *arraySize; i++) {
        newArray[i] = (*array)[i];
    }

    newArray[*arraySize] = insertNumber;


    free(*array);  
    *array = newArray;
    *arraySize = newSize;
}

//ninthExercise: insert position five
void insertPosFive(int **array, int *arraySize, int insertNumber) {
    int newSize = *arraySize + 1;

    int *newArray = (int *)malloc(newSize * sizeof(int));
    if (newArray == NULL) {
        exit(1);
    }

    for (int i = 0; i < 5; i++) {
        newArray[i] = (*array)[i];
    }

    newArray[5] = insertNumber;

    for (int i = 6; i < newSize; i++) {
        newArray[i] = (*array)[i - 1];
    }

    free(*array); 
    *array = newArray;
    *arraySize = newSize;
}

// tenthExercise: delete first element
void deleteBeginning(int **array, int *arraySize) {
    if (*arraySize <= 0) {
        return;
    }

    int newSize = *arraySize - 1;

    int *newArray = (int *)malloc(newSize * sizeof(int));
    if (newArray == NULL) {
        exit(1);
    }

    for (int i = 0; i < newSize; i++) {
        newArray[i] = (*array)[i];
    }

    free(*array);
    *array = newArray;
    *arraySize = newSize;
}

// eleventhExercise: delete last element
void deleteEnd(int **array, int *arraySize) {
    if (*arraySize <= 0) {
        return;
    }

    int newSize = *arraySize - 1;

    int *newArray = (int *)malloc(newSize * sizeof(int));
    if (newArray == NULL) {
        exit(1);
    }

    for (int i = 0; i < newSize; i++) {
        newArray[i] = (*array)[i + 1];
    }

    free(*array);
    *array = newArray;
    *arraySize = newSize;
}

// twelfthExercise: delete element at position five
void deletePosFive(int **array, int *arraySize) {
    if (*arraySize <= 0 || *arraySize <= 5) {
        return;
    }

    int newSize = *arraySize - 1;

    int *newArray = (int *)malloc(newSize * sizeof(int));
    if (newArray == NULL) {
        exit(1);
    }

    for (int i = 0; i < 5; i++) {
        newArray[i] = (*array)[i];
    }

    for (int i = 5; i < newSize; i++) {
        newArray[i] = (*array)[i + 1];
    }

    free(*array);
    *array = newArray;
    *arraySize = newSize;
}
