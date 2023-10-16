#include <stdio.h>
void displayArray (int*Arr, int size);

int main(){
    int arr[5] = {10,15,20,25,30};
    int size = sizeof(arr, size);
    displayArray(arr,size);

}

void displayArray (int *arr, int size){
    for (int i=0; i<=size; i++){
        printf("%d, ",*(arr+i));
    }
}
