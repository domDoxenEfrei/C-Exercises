/*
Using #define create a constant nameed PI which equals 3.1415
Create a variable v1 which equals PI
using gcc -E check that the constant is replaced before compilation
*/

//gcc -E 001_preprocessing.c

#define PI 3.14159;

int main () {

    int v1 = PI;
}