#include <stdio.h>

int main (){
    
    int leftPart, rightPart;
    char operand;

    printf ("Please input the first integer: ");
    scanf ("%d", &leftPart);

    printf ("Please input the operator (+, -, *, /): ");
    scanf (" %c", &operand);

    printf ("Please input the second integer: ");
    scanf ("%d", &rightPart);

    switch (operand){
        case '+':
            printf ("%d + %d = %d\n", leftPart, rightPart,leftPart + rightPart);
            break;
        case '-':
            printf ("%d - %d = %d\n", leftPart, rightPart,leftPart - rightPart);
            break;
        case '*':
            printf ("%d * %d = %d\n", leftPart, rightPart, leftPart * rightPart);
            break;
        case '/':
            if (rightPart !=0) {
                printf("%d / %d = %f\n", leftPart, rightPart, (float) leftPart / rightPart);
            }
            else {
                printf("Division by Zero, error \n");
            }
        default:
            printf("Invalid Operator");
            break;
    }
    return 0;
}