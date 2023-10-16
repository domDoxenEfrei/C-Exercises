#include <stdio.h>

int main(){

float userNum;
printf("Please enter a number: ");
scanf("%f", &userNum);

if (userNum < 0){
    float userNumABS = userNum*-1;
    printf("The absolute value of the number is %g.", userNumABS);
    }
else {
    printf("The absolute value of the number is %g.", userNum);
    } 

}