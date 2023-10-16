#include <stdio.h>
#include <stdbool.h>

// Function to find the maximum value in an array of floats
float findMaxValue(float numbers[], int size) {
    float max = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}

// Function to find the minimum value in an array of floats
float findMinValue(float numbers[], int size) {
    float min = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return min;
}

// Function to find the average value of an array of floats
float findAverage(float numbers[], int size) {
    float sum = 0.0;

    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }

    if (size > 0) {
        return sum / size;
    } else {
        // Handle the case where the array is empty to avoid division by zero.
        return 0.0;
    }
}

int main() {
    int numInputs;
    printf("How many numbers would you like to check?: ");
    scanf("%d", &numInputs);

    float userNumbers[numInputs];
    printf("Please input up to %d numbers, separated by commas: ", numInputs);

    for (int i = 0; i < numInputs; i++) {
        scanf("%f,", &userNumbers[i]);
    }

    printf("Your numbers are: ");
    for (int i = 0; i < numInputs; i++) {
        printf("%g ", userNumbers[i]);
    }
    printf("\n");

    int userChoice;
    bool exitProgram = false; // Added a boolean flag to control program exit

    while (!exitProgram) { // Loop until exitProgram is true
        printf("Option 1: Find the Maximum Value\n");
        printf("Option 2: Find the Minimum Value\n");
        printf("Option 3: Find the Average Value\n");
        printf("Option 4: Do all of these\n");
        printf("Option 5: Exit the program\n");
        printf("Please select one of those options: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1: {
                // Find and print the maximum value
                float max = findMaxValue(userNumbers, numInputs);
                printf("\nThe maximum value is: %g\n", max);
                break;
            }
            case 2: {
                // Find and print the minimum value
                float min = findMinValue(userNumbers, numInputs);
                printf("\nThe minimum value is: %g\n", min);
                break;
            }
            case 3: {
                // Find and print the average value
                float avg = findAverage(userNumbers, numInputs);
                printf("\nThe average value is: %g\n", avg);
                break;
            }
            case 4: {
                // Find and print all values
                float maxVal = findMaxValue(userNumbers, numInputs);
                float minVal = findMinValue(userNumbers, numInputs);
                float avgVal = findAverage(userNumbers, numInputs);
                printf("The minimum: %g,\nThe maximum: %g,\nThe average: %g\n", minVal, maxVal, avgVal);
                break;
            }
            case 5:
                // Exit the program
                exitProgram = true;
                printf("Goodbye");
                break;
            default:
                printf("Invalid selection, please choose 1, 2, 3, 4, or 5.\n");
        }
    }

    return 0;
}
