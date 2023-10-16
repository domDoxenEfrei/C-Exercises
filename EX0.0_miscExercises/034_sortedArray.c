#include <stdio.h>
#include <stdbool.h>

int main() {
    int array[] = {1, 9, 2, 8, 3, 7, 5, 6, 4, 0};
    int length = sizeof(array) / sizeof(array[0]);
    bool isSorted = true; 

    printf("Here is the array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }

    for (int i = 0; i < length - 1; i++) {
        if (array[i] > array[i + 1]) {
            isSorted = false;
            break;
        }
    }

    if (!isSorted) { // Check if the array is not sorted
        char sorting;
        printf("\nThe array is not sorted. Would you like me to sort it? (Y/N): ");
        scanf(" %c", &sorting); // Use " %c" to consume the newline character

        if (sorting == 'Y') {
            // Bubble sort to reorganize the array
            for (int i = 0; i < length - 1; i++) {
                for (int j = 0; j < length - i - 1; j++) {
                    if (array[j] > array[j + 1]) {
                        int temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
            }

            printf("The new array is: ");
            for (int i = 0; i < length; i++) {
                printf("%d ", array[i]);
            }
        } else if (sorting == 'N') {
            printf("Okay, byeeeeeeeeeeee.\n");
        } else {
            printf("Invalid choice. Please enter 'Y' or 'N'.\n");
        }
    } else {
        printf("\nThe array is already sorted.\n");
    }

    return 0;
}
