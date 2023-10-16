#include <stdio.h>

int main(void) {
    int userNum1;
    int userNum2;
    int userNum3;
    int userNum4;
    int userNum5;

    printf("Please enter five integers separated by commas: \n");
    scanf("%d, %d, %d, %d, %d", &userNum1, &userNum2, &userNum3, &userNum4, &userNum5);
    
    printf("Your numbers are %d %d %d %d %d \n", userNum1, userNum2, userNum3, userNum4, userNum5);
    
    int maximum = userNum1;
    
    if(userNum2 > maximum){
        maximum = userNum2;
    }
    
    if(userNum3 > maximum){
        maximum = userNum3;
    }
    
    if(userNum4 > maximum){
        maximum = userNum4;
    }
    
    if(userNum5 > maximum){
        maximum = userNum5;
    }
    
    printf("The maximum number is %d", maximum);
    return 0;
}