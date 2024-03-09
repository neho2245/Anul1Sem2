// solved

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int power(int base, int exponent) {
    if (exponent == 0)
        return 1;
    return base * power(base, exponent - 1);
}

void titleToNumber(char* columnTitle) {
    int result = 0;
    char x = 'A';
    for (int i = strlen(columnTitle) - 1; i >= 0; i--) {
        result += power(26, strlen(columnTitle) - 1 - i) * (columnTitle[i] - x + 1);
    }
    printf("%d", result);
}

int main() {
    char* title = malloc(sizeof(char) * 8);
    strcpy(title, "AA");
    titleToNumber(title);
    return 0;
}