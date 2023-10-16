/*
Code a function named absolute_value which returns the absolute value of a number. It must have the following prototype: 
float absolute_value(float number)  

For example:
absolute_value(-3) must return 3
and absolute_value(2) must return 2
*/


#include <stdio.h>

int absVal (int num){
    if (num<0){
        num*-1;
    }
    return num;
}

int main () {
    int num1 = -5;
    num1 = absVal(num1);
    printf("%d\n",num1);

    int num2 = 5;
    num1 = absVal(num1);
    printf("%d\n",num1);
}