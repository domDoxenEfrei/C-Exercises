#include <stdio.h>

// Function to remove duplicates from an array of integers
int removeDuplicates(int array[], int size) {
    if (size <= 1) {
        return size; // No duplicates to remove
    }

    int uniqueIndex = 1; // Initialize the unique index

    // Iterate through the array to find and remove duplicates
    for (int i = 1; i < size; i++) {
        int isDuplicate = 0; // Flag to check for duplicates

        // Check if the current element is a duplicate
        for (int j = 0; j < uniqueIndex; j++) {
            if (array[i] == array[j]) {
                isDuplicate = 1;
                break;
            }
        }

        // If not a duplicate, keep it and increment the unique index
        if (!isDuplicate) {
            array[uniqueIndex] = array[i];
            uniqueIndex++;
        }
    }

    return uniqueIndex; // Return the size of the array with duplicates removed
}

int main() {
    int array[] = {1, 2, 2, 3, 4, 4, 5, 5, 6};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    int newSize = removeDuplicates(array, size);

    printf("\nArray with Duplicates Removed: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}
