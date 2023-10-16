#include <stdio.h>

int main (){
    int userNum;
    printf("Please provide an integer: ");
    scanf ("%d", &userNum);

    if (userNum <=1) {
        printf("That is not prime");
    } else {
        int isPrime = 1;

        for (int divisor=2; divisor*divisor<=userNum; divisor++) {
            if (userNum % divisor ==0) {
            isPrime =0;
            break;
            }
        }
    if (isPrime==1){
        printf("The number is prime.");
    } else {
        printf ("That is not prime");
    }
    }
}
