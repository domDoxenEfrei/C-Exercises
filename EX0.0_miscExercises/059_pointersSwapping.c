#include <stdio.h>

void swapVar (int*var1, int*var2);

int main(){
    int var1 = 5;
    int var2 = 10;
    printf("var1: %d\nvar2: %d\n",var1,var2);
    swapVar(&var1,&var2);

}

void swapVar (int*var1, int*var2) {
    int temp = *var1;
    *var1=*var2;
    *var2=temp;
    printf("var1 is now: %d\nvar2 is now: %d", *var1,*var2);
}
