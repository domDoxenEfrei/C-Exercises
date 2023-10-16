#include <stdio.h>

int main(void){

int userNum;
printf("Please enter an integer: ");
scanf("%d", &userNum);

if (userNum % 2==0){
    printf("That number is even!");
    }
else {
    printf("That number is odd!");
    } 

}