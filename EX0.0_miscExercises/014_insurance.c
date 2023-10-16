#include <stdio.h>

int main(){
    
    float damage, deductible;
    printf ("Please input the $ amount of damage sustained: ");
    scanf ("%f", &damage);
    
    deductible = damage * 0.1;
    
    if (deductible <10) {
        printf("Your deductible is $10");
    }
    
    else if (deductible >500) {
        printf ("Your deductible is $500");
    }
    
    else {
        printf("Your deductible is $%g", deductible);
    }

    return 0;
}
