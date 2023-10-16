#include <stdio.h>

void reverseArrayPrint(int *ptrEnd, int size);
void forwardArrayPrint(int *ptrBegin, int size);
void reverseArraySet(int *ptrBegin, int *ptrEnd, int size);

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(array) / sizeof(array[0]);
    
    int *ptrBegin = array;
    int *ptrEnd = array + size - 1;

    //printf("%d\n%d\n",*ptrBegin,*ptrEnd);

    printf("Print forward array: ");
    forwardArrayPrint(ptrBegin, size);
    printf("\n");
    printf("Print forward array in reverse without re-setting the first array: ");
    reverseArrayPrint(ptrEnd, size);
    printf("\n");
    reverseArraySet(ptrBegin, ptrEnd, size);
    printf("Through some magic, now the forward array is set to be the reverse array\n");
    printf("I'll call the forward array now: ");
    forwardArrayPrint(ptrBegin,size);
    return 0;
}

void forwardArrayPrint(int *ptrBegin, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d, ", *(ptrBegin+i));
    }
}

void reverseArrayPrint(int *ptrEnd, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d, ", *(ptrEnd-i));
    }
}
void reverseArraySet (int *ptrBegin, int *ptrEnd, int size){
    while (ptrBegin < ptrEnd){
        int temp = *ptrBegin;
        *ptrBegin = *ptrEnd;
        *ptrEnd = temp;

        ptrBegin++;
        ptrEnd--;
    }

}
