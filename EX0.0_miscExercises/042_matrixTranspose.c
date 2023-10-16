#include<stdio.h>

int main () {
    int rows=6;
    int columns=6;
    int matrix[rows][columns];
    //This section puts a number in each spot of the matrix instead of the user defining each, defined by an incremented counter
    //It assigns and prints each cell of the matrix
    int counter = 1; 
        for (int i=0; i<rows; i++) {
            for (int j=0; j<columns; j++) {
                matrix [i][j] = counter;
                printf("%3d ", matrix[i][j]);
                counter ++;
            }
        printf("\n");
        }
    
    //This section transposes the matrix by swappign the order of the for loops.
    int transposed[columns][rows];
        for (int i = 0; i < columns; i++) {
            for (int j = 0; j < rows; j++) {
                transposed[i][j] = matrix[j][i];
            }
        }
    
    //It prints the newly transposed matrix. I could combine it with the last step if I wanted, but just wrote it separately.
    printf("\nTransposed Matrix:\n");
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%3d ", transposed[i][j]);
        }
        printf("\n");
    }
    
return 0;
}