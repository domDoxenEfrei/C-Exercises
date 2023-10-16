#include <stdio.h>

float calcAbsValue (float userNum) {
    float userNumAbs;
    if (userNum < 0){
    userNumAbs = userNum*-1;
    } else {
    userNumAbs = userNum;
    } return userNumAbs; 
}

int main () {
    float userNumber, absVal;
    printf("Please input a number: ");
    scanf ("%f", &userNumber);
    absVal = calcAbsValue (userNumber);
    printf("The absolute value of the number is %g.", absVal);
    return 0;
}