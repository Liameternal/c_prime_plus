//
// Created by liam on 8/17/21.
//
#include <stdio.h>
int main(void) {
    char ch = 'A';
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            putchar(ch++);
        }
        putchar('\n');
    }
    return 0;
}
