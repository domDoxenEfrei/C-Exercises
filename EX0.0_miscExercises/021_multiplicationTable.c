 #include <stdio.h>

int main (){
    int userNum;
    printf("Please provide an integer: ");
    scanf ("%d", &userNum);

    int times;
    printf("I'll generate the multiplication table for that number, to what number should I calculate it?: ");
    scanf ("%d", &times);
    
    for (int i=0; i<=times; i++){
        int result = i * userNum;
        printf("%d * %d = %d\n", userNum, i, result);
    }
}