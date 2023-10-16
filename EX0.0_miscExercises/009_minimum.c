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
    
    int minimum = userNum1;
    
    if(userNum2<minimum){
        minimum = userNum2;
    }
    
    if(userNum3<minimum){
        minimum = userNum3;
    }
    
    if(userNum4<minimum){
        minimum = userNum4;
    }
    
    if(userNum5<minimum){
        minimum = userNum5;
    }
    
    printf("The minimum number is %d",minimum);
    return 0;
}