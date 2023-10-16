#include <stdio.h>

int main() {
    int rows = 3;
    int columns = 3;
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printf("Original Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    int index = 0;
    int flattenedArray[rows * columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            flattenedArray[index++] = matrix[i][j];
        }
    }
    
    printf("\nFlattened Array: ");
    for (int i = 0; i < rows * columns; i++) {
        printf("%d ", flattenedArray[i]);
    }
    
    return 0;
}
