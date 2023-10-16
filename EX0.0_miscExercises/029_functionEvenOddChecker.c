#include <stdio.h>
#include <stdbool.h>

bool oddChecker (int userNum){
    if (userNum % 2 !=0) {
        return true;
    } else {
        return false;
    }
}

int main () {
    int userNum;
    printf("Please provide a positive integer: ");
    scanf("%d", &userNum);

    bool odd = oddChecker(userNum);
    if (odd==true) {
        printf("The number is odd");
    } else {
        printf("The number is even");
    }
return 0;
}