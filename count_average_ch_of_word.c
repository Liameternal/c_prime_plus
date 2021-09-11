//
// Created by liam on 8/24/21.
//
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void) {
    bool is_word = false;
    long word = 0;
    long alpha = 0;
    int ch;
    int ch_front;
    while ((ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            is_word = true;
            alpha++;
            continue;
        } else {
            if (is_word) {
                word++;
                is_word = false;
            }
        }
    }
    if (!word) {
        printf("Not a single  word is entered.\n");
        exit(1);
    }
    double average = 0;
    average = (double) alpha / word;
    printf("Evenly a word has %.2f alpha.\n", average);

    return 0;
}

