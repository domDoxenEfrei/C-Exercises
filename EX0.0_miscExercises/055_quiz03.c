#include <stdio.h>
#include <string.h>

int count_digits_in_string (char string[]);

int main(){
    char string1[] = "Hello World";
    char string2[] = "C programming 2023";
    
    int count1 = count_digits_in_string(string1);
    int count2 = count_digits_in_string(string2);
    
    printf("\"%s\" contains %d digits.\n", string1, count1);
    printf("\"%s\" conttains %d digits. \n", string2, count2);
}

int count_digits_in_string (char string[]){
    int count = 0;
    int length = strlen(string);
    
    for (int i=0; i<length; i++){
        if (string[i]>= '0' && string [i]<= '9'){
            count++;
        }
    }
    return count;
}
