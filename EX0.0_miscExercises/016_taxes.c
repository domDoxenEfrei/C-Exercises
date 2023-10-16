#include <stdio.h>

int main(void) {
    float income;
    printf("What is your income?: ");
    scanf("%f",&income);
    
    float tax;
    
    if (income <= 10000){
        tax = 0.0;
    }
    
    else if (income <=30000) {
        tax = (income - 10000)*0.1;
    }
    
    else if (income <=60000) {
        tax = (20000*0.1) + ((income-30000)*0.3);
    }
    
    else {
        tax = (20000*0.1) + (30000*0.3) + ((income-60000)*0.5);
    }
    
    printf("Your income tax on $%g, is equal to $%g.", income, tax);
    return 0;
}