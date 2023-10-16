#include <stdio.h>
#include <stdbool.h>

void createArray(int array[], int *arraySize) {
    printf("How many integers would you like to enter?: ");
    scanf("%d", arraySize);

    printf("Please enter %d integers separated by commas:\n", *arraySize);
    for (int i = 0; i < *arraySize; i++) {
        scanf("%d,", &array[i]);
    }
}

bool isSorted(int array[], int arraySize) {
    for (int i = 0; i < arraySize - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

// Function to sort an array using bubble sort
void sortingFunction(int array[], int arraySize) {
    // Bubble sort to reorganize the array
    for (int i = 0; i < arraySize - 1; i++) {
        for (int j = 0; j < arraySize - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// Function to add integers to the array and perform actions
void insertFunction(int array[], int *arraySize) {
    char intAddChoice;
    printf("Would you like to insert some integers into your array? (Y/N): ");
    scanf(" %c", &intAddChoice);

    if (intAddChoice == 'Y' || intAddChoice == 'y') {
        int intAdd;
        printf("\nHow many numbers would you like me to add in? ");
        scanf("%d", &intAdd);

        printf("Option 1: Add at beginning, no sorting\n");
        printf("Option 2: Add at end, no sorting\n");
        printf("Option 3: Add to Array and re-sort array\n");
        printf("Option 4: Leave the program\n");

        int intAddOptions;
        printf("What is your choice?: ");
        scanf("%d", &intAddOptions);

        switch (intAddOptions) {
            case 1:
                // Add at beginning
                for (int i = *arraySize - 1; i >= 0; i--) {
                    array[i + intAdd] = array[i];
                }
                for (int i = 0; i < intAdd; i++) {
                    printf("Enter one integer to add: ");
                    scanf("%d", &array[i]);
                }
                (*arraySize) += intAdd;
                printf("The new array after adding at the beginning: ");
                for (int i = 0; i < *arraySize; i++) {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;
            case 2:
                // Add at end
                for (int i = 0; i < intAdd; i++) {
                    printf("Enter one integer to add: ");
                    scanf("%d", &array[*arraySize + i]);
                }
                (*arraySize) += intAdd;
                printf("The new array after adding at the end: ");
                for (int i = 0; i < *arraySize; i++) {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;
            case 3:
                // Add to Array and re-sort array
                for (int i = 0; i < intAdd; i++) {
                    printf("Enter one integer to add: ");
                    scanf("%d", &array[*arraySize + i]);
                }
                (*arraySize) += intAdd;
                sortingFunction(array, *arraySize);
                printf("The new sorted array after adding: ");
                for (int i = 0; i < *arraySize; i++) {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;
            case 4:
                // Leave the program
                break;
            default:
                printf("Invalid Choice\n");
        }
    } else {
        printf("You're No Fun! Goodbye.\n");
    }
}

int main() {
    int arraySize;
    int array[100]; // Declare an array with a maximum size, change this as needed

    createArray(array, &arraySize);

    printf("Array One: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", array[i]);
    }

    if (!isSorted(array, arraySize)) {
        char sortingChoice;
        printf("\nThe array is out of order, would you like me to sort it (Y/N): ");
        scanf(" %c", &sortingChoice);

        if (sortingChoice == 'Y' || sortingChoice == 'y') {
            sortingFunction(array, arraySize); // Call the sorting function to sort the array
            printf("\nThe sorted array is: ");
            for (int i = 0; i < arraySize; i++) {
                printf("%d ", array[i]);
            }
            insertFunction(array, &arraySize);
        } else {
            printf("You are no fun! Goodbye.\n");
        }
    } else {
        printf("\nThe array is already sorted.\n");
        insertFunction(array, &arraySize);
    }

    return 0;
}





