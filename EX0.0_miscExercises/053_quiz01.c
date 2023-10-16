#include <stdio.h>
void main() {
    
    int k=4;
    int a=5;
    int b=20;
    int result;
    
    printf("The multiples of %d from %d to %d are: ", k, a,b);
    for (int i=0; i<=b; i++){
        result = k*i;
        if (result>=a && result<=b){
            printf("%d ",result);
        }
        
    }
    return 0;
}
