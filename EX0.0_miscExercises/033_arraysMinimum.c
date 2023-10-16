#include <stdio.h>

int main () { //initializes main function

    int array[] = {1,2,3,4,5,6,0,7,8,9}; //creates an array of 10 integers
    int length = sizeof(array) / sizeof(array[0]);  //determines the length of said pre-defined array

    printf("Original Array: "); //Section is to print out the original array
    for (int i=0; i<length; i++){   // for loop that iterates on the array by one unit of length to the right
        printf("%d ",array[i]); //prints out each number of the original array 
    }   //ends the printing of the original array

    int min = array[0]; //Sets the minimum of the array to be the first integer in the array
    for (int i=1; i<length; i++){   //for loop starting at the second integer in the array, iterates one spot at a time moving to right
        if (array[i]<min){  //checks if each movement to the right results in a new minimum value
        min = array[i]; //updates the value of min if it finds a new min as it moves to the right
        }
    }
    printf("The min is %d", min);
return 0;
}