#include <stdio.h>

int main (){

    char myCharacters[7];
        myCharacters[0]='H';
        myCharacters[1]='O';
        myCharacters[2]='O';
        myCharacters[3]='R';
        myCharacters[4]='A';
        myCharacters[5]='Y';
        myCharacters[6]='!';

    for (int i=0; i<7;i++) {
        printf("%c", myCharacters[i]);
    }
}