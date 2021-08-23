//
// Created by liam on 8/17/21.
//
#include <stdio.h>
int main(void) {
    char ch = 'E';
    int row = ch - 'A' + 1;
    for (int i = 0; i < row; ++i) {
        int count = 0;
        while (count++ < row - i - 1)
            putchar(' ');
        for (int j = 0; j < i + 1; ++j) {
            putchar('A' + j);
        }
        for (int j = i - 1; j >= 0; --j) {
            putchar('A' + j);
        }
        putchar('\n');
    }
    return 0;
}
