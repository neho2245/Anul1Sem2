//solved inefficiently

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct roman {
    char symbol;
    int value;
} TRoman;

int romanToInt(char* s) {
    int result = 0;
    char string[] = {"IVXLCDM"};
    int values[] = {1, 5, 10, 50, 100, 500, 1000};
    TRoman numerals[7];

    for (int i = 0; i < 7; i++) {
        numerals[i].symbol = string[i];
        numerals[i].value = values[i];
        printf("%c %d\n", numerals[i].symbol, numerals[i].value);
    }
    
    for (int i = 0; i < strlen(s); i++) {
        int found = 0;
        for (int j = 0; j < 6; j++) {
            for (int k = j + 1; k < 7; k++) {
                if (numerals[j].symbol == s[i] && numerals[k].symbol == s[i+1]) {
                    result += numerals[k].value - numerals[j].value;
                    found++;
                    i++;
                    break;
                }
            }
            if (found)
                break;
        }
        if (found == 0) {
            for (int q = 0; q < 7; q++) {
                if (numerals[q].symbol == s[i]) {
                    result += numerals[q].value;
                    break;
                }
            }
        }
    }
    return result;
}

int RomanToIntEfficient (char* s) {
    int result = 0;
    char string[] = {"IVXLCDM"};
    int values[] = {1, 5, 10, 50, 100, 500, 1000};
    TRoman numerals[7];

    for (int i = 0; i < 7; i++) {
        numerals[i].symbol = string[i];
        numerals[i].value = values[i];
        printf("%c %d\n", numerals[i].symbol, numerals[i].value);
    }

    for (int i = 0; i < strlen(s); i++) {
            
    }
}

int main() {
    printf("%d\n", romanToInt("MMLXXXII"));
    return 0;
}