#include <stdio.h>

int main(){

int firstNum;
int secondNum;
int thirdNum;
int fourthNum;
int fifthNum;

printf("Please input five numbers: ");
scanf("%d %d %d %d %d", &firstNum,&secondNum,&thirdNum, &fourthNum, &fifthNum);

float sum = (float) firstNum + secondNum + thirdNum + fourthNum + fifthNum;
float mean = sum/5;

printf("The mean of the five numbers is %f \n", mean);
return 0;
}