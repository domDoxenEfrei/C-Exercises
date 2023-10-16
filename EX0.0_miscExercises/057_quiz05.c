#include <stdio.h>
//put function's declaration here if you want to use test_main
void reverseTab(int tab[], int size);

//like main for testing
void test_main(){
int array1[] = {1,2,3,4,5};
int size1 = sizeof(array1)/sizeof(array1[0]);

reverseTab(array1, size1);

printf("Reversed array1: ");
for (int i=0; i<size1; i++){
    printf("%d ",array1[i]);
}
}

//put your function here
void reverseTab(int tab[], int size) {
    int start =0;
    int end = size-1;
    
    while (start < end){
    int temp = tab[start];
    tab[start]=tab[end];
    tab[end]=temp;
    
    start++;
    end--;
    }
}