#include <stdio.h>

int recursiveSequentialSearch(int tab[], int x, int a, int length);

int main() {
    int tab[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int length = sizeof(tab) / sizeof(tab[0]);
    int x = 6;
    int index = recursiveSequentialSearch(tab, x, 0, length);

    if (index != 1) {
        printf("%d found at index %d.\n", x, index);
    } else {
        printf("%d not found in the array.\n", x);
    }

    return 0;
}

int recursiveSequentialSearch(int tab[], int x, int a, int length) {
    if (a >= length) {
        return 1;
    }

    if (tab[a] == x) {
        return a;
    }

    return recursiveSequentialSearch(tab, x, a + 1, length);
}
