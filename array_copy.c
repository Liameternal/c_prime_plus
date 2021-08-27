//
// Created by liam on 8/26/21.
//
#include <stdio.h>

void ArrayCopy1(double target[], const double source[], int len);

void ArrayCopy2(double *target, const double *source, int len);

void ArrayCopy3(double *target, const double *source, double *stop);

int main(void) {
    const double sources[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];
    ArrayCopy1(target1, sources, 5);
    ArrayCopy2(target2, sources, 5);
    ArrayCopy3(target3, sources, sources + 5);
    printf("Sources:\n");
    for (int i = 0; i < 5; ++i) {
        printf("%.2f ", sources[i]);
    }
    putchar('\n');
    printf("ArrayCopy1:\n");
    for (int i = 0; i < 5; ++i) {
        printf("%.2f ", target1[i]);
    }
    putchar('\n');
    printf("ArrayCopy2:\n");
    for (int i = 0; i < 5; ++i) {
        printf("%.2f ", target2[i]);
    }
    putchar('\n');
    printf("ArrayCopy3:\n");
    for (int i = 0; i < 5; ++i) {
        printf("%.2f ", target3[i]);
    }
    return 0;
}

void ArrayCopy1(double target[], const double source[], int len) {
    for (int i = 0; i < len; ++i) {
        target[i] = source[i];
    }
}

void ArrayCopy2(double *target, const double *source, int len) {
    for (int i = 0; i < len; ++i) {
        target[i] = source[i];
    }
}

void ArrayCopy3(double *target, const double *source, double *stop) {
    while (source < stop) {
        *target++ = *source++;
    }
}

