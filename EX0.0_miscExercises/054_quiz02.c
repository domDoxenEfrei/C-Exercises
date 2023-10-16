#include <stdio.h>

int main(){

    float tab[8]={75.3,80.4,95.2,98,68,85,88,91.6};
    float max = tab[0]; 
    float min = tab[0];
    float average = 0;
    float sum =0;
    
    for (int i =0;i<8; i++){
        if (tab[i]>max){
            max = tab[i];
        }
        if (tab[i] < min){
            min = tab[i];
        }
        sum += tab[i];
    }
    
    average = sum/8;
    
    printf("The min is %f\n The max is %f\n The average is %f\n",min, max, average);
}



