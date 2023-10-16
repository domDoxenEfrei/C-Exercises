/*
#define lets you also define macro (like functions with parameters)
for instance this macro will let you define a macro using printf
# define log(message) printf("message: %s, line: %d\n", message, __LINE__)
We want to use this mecanism to simplify our unit test writings.
Exercise
1. create a parametrized macro ASSERT(boolean_expression) which will print and error and quit if the assertion is false.
It should include : 
the line number using __LINE__
the file name using __FILE__
the failed assertion using #boolean_expression
2. Use the ASSERT in a small unit test
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define log(message) printf("message: %s\n", message)

#define ASSERT(boolean_expression)  \
    if (!(boolean_expression)) {  \
        printf("Assertion failed: %s, Line: %d, File: %s\n", #boolean_expression, __LINE__, __FILE__);  \
        exit(1); \
    }

int main() {
    int result = 2 + 2;
    bool add_check = (result == 5);
    ASSERT(add_check);

    log("Test passed");
    return 0;
}
