//
// Created by liam on 8/27/21.
//
#include <stdio.h>

void ArrayCopy1(double target[], const double source[], int len);

int main(void) {
    const double sources[3][5] = {
            {1.1, 2.2, 3.3, 4.4, 5.5},
            {1.1, 2.2, 3.3, 4.4, 5.5},
            {1.1, 2.2, 3.3, 4.4, 5.5}
    };
    double target1[3][5];
    for (int i = 0; i < 3; ++i) {
        ArrayCopy1(target1[i], sources[i], 5);
    }
    printf("Sources:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("%.2f ", sources[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
    printf("ArrayCopy1:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 5; ++j) {
            printf("%.2f ", target1[i][j]);
        }
        putchar('\n');
    }
    return 0;
}

void ArrayCopy1(double target[], const double source[], int len) {
    for (int i = 0; i < len; ++i) {
        target[i] = source[i];
    }
}

