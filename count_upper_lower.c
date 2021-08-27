//
// Created by liam on 8/24/21.
//
#include <stdio.h>
#include <ctype.h>

int main(void) {
    long lower = 0;
    long upper = 0;
    int ch;
    while ((ch = getchar()) != EOF) {
        if (isupper(ch)) {
            upper++;
            continue;
        }
        if (islower(ch)) {
            lower++;
            continue;
        }
    }
    printf("This string has %ld lower cases.\n", lower);
    printf("This string has %ld upper cases.\n", upper);

    return 0;
}

