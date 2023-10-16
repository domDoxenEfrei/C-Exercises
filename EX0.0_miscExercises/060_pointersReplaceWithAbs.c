#include <stdio.h>

int replaceWithAbs (int *var1);

int main (){
    int var1=-19;
    replaceWithAbs(&var1);
    printf("Var1: %d", var1);
    return 0;
}

int replaceWithAbs (int *var1) {
    if (*var1 <0) {
        int temp = *var1*-1;
        *var1 = temp;
    } 
    return *var1;

}