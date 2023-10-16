#include <stdio.h>

int main () {

//    int a = 10;
//    int *p = &a;
//    printf("p address: %d\n", p);
//    printf("p+1 address: %d\n", p+1);//increases by 4 because points to an int = 4bytes

//    char c;
//    char *p1 = &c;
//    printf("p1 address: %d\n", p1);
//    printf("p1+1 address: %d\n", p1+1);//increases by 1 because points to a char = 1 byte

//    int x = 5;
//    int *p = &x;
//    *p = 6;
//    int **q = &p;
//    int ***r = &q;
//    printf("*p: %d\n", *p); // DEREFERENCING
//    printf("&p: %d\n", &p);
//    printf("*q: %d\n", *q);

    int (*p)[3];
    int B[2][3] = {
        {1,2,3},
        {4,5,6}
    };
   
   p=B;
   printf("B = %d\n", B);
   printf("*B+1=%d\n", *(B+1));
   printf("B[1][1]=%d\n", B[1][1]);
   printf("B[1,1]=%d\n", *(*(B+1)+1));
   printf("B[1,2]=%d\n", *(p+6));

}