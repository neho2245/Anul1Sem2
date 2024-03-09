#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int myAtoi(char *s) {
    char x = '0';
    int result = 0;
    for (int i = 0; i < strlen(s); i++) {
        int number = s[i] - x;
        result += pow(10, strlen(s) - 1 - i) * number;
    }
    return result;
}

int main() {
    char* string = malloc(sizeof(char) * 512);
    fscanf(stdin, "%s", string);
    printf("%d", myAtoi(string));
    return 0;
}