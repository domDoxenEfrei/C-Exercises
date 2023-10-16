/*
To create a constant with the preprocessor, you can use the #define directive like that : 
#define constantname value;
1. Create a constant named UNIVERSE which equals 42 with the pre-processor. 
2. Create a variable v1 which equals to UNIVERSE. Display v1;
Please not that it is not a variable but an hardcoded value replaced by the preprocessor in the code.
3. compile the file with gcc -E youfile.c > preprocessed.c and open it. Look for main function. What was changed
*/

//the command for terminal to run this is...
    //gcc -E 001_preprocessorConst.c

#define UNIVERSE 42

int main () {
    int v1 = UNIVERSE;
}
