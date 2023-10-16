#include <stdio.h>
#include <string.h>

int isWhiteSpace(char ch);
void trimString(char str[]);

int main() {
    char str[] = "            Hello, World!          ";

    printf("Original string: \"%s\"\n", str);
    trimString(str);
    printf("Trimmed string: \"%s\"\n", str);

}

int isWhiteSpace(char ch) {
    return (ch == ' ');
}

void trimString(char str[]) {
    int start = 0;
    while (isWhiteSpace(str[start])) {
        start++;
    }

    int end = strlen(str) - 1;
    while (end >= 0 && isWhiteSpace(str[end])) {
        end--;
    }

    int length = end - start + 1;
    for (int i = 0; i < length; i++) {
        str[i] = str[start + i];
    }
    str[length] = '\0'; 
}
