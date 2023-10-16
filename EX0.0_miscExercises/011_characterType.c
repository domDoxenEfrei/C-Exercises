#include <stdio.h>

int main (){
    
    char userChar;
    printf ("Please input a single alphanumeric character: ");
    scanf ("%c", &userChar);

if (userChar >= 'A' && userChar <= 'Z')   {
    printf("Your character is UpperCase!");
}

else if (userChar >= 'a' && userChar <= 'z') {
    printf ("Your character is LowerCase!");
}

else if (userChar >= '0' && userChar <= '9') {
    printf ("Your character is a number!");
}

else 
    printf ("-");{
}

return 0;
}