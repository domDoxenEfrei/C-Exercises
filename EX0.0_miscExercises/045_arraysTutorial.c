#include <stdio.h>

void printArray(int size, int tab[]);
int getNumber();
char getPosition();
void insertEnd (int n, int t[], int size, int tab[1]);
void insertBeginning (int n, int t[], int size, int tab1[]);

int main () {
    int tab[] = {1,2,3,4,5};
    int N = sizeof(tab) / sizeof(tab[0]);

    printArray(N,tab);
    int num = getNumber();
    char pos = getPosition();

    int tab1[N+1];
    if (pos == 'e') {
        insertEnd(num, tab, N, tab1);
    } else if (pos =='b') {
        insertBeginning(num, tab, N, tab1);
    }
    printArray(N+1, tab1);
    return 0;
}

//printArray Function Definition
void printArray(int size, int tab[]) {
    for (int i = 0; i < size; i++) {
        printf("%d ",tab[i]);
    }
    printf("\n");
}

//getNumber Function Definition
int getNumber (){
    int nb;
    printf("What number would you like to add?: ");
    scanf("%d", &nb);
    return nb;
}

//getPosition Function Definition
char getPosition (){
    char p;
    printf("Please choose where you would like to add the number. 'e' for end and 'b' for beginning: ");
    scanf(" %c",&p);
    return p;
}

//insertEnd Function Definition
void insertEnd (int n, int t[], int size, int tab1[]) {
    for (int i=0; i<size; i++){
        tab1[i]=t[i];
    }
    tab1[size]=n;
}

//insertBeginning Function Definition
void insertBeginning (int n, int t[], int size, int tab1[]) {
    tab1[0]=n;
    for (int i=0; i<size; i++){
        tab1[i+1]=t[i];
    }
}