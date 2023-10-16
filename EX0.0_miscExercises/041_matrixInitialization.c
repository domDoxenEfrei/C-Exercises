#include <stdio.h>

int main() {
    int rows = 6;
    int columns = 6;
    int matrix[rows][columns];

    // Initialize the matrix and print it in one loop
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = i + j;
            printf("%d ", matrix[i][j]);
        }
        printf("\n"); // Move to the next row
    }

    return 0;
}
