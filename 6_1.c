//
// Created by liam on 8/17/21.
//
#include <stdio.h>
#define ALPHABET_NUM 26
int main(void) {
    char alphabet[ALPHABET_NUM];
    char i;
    int j;
    for (i = 'a', j = 0; j < ALPHABET_NUM; ++i, ++j) {
        alphabet[j] = i;
    }
    for (int k = 0; k < ALPHABET_NUM; ++k) {
        putchar(alphabet[k]);
        putchar(' ');
    }
    return 0;
}
