//
// Created by liam on 9/7/21.
//
#include <math.h>
#include <stdio.h>

#define ARRAY_LEN 100

double Plus(double);
double Sub(double);
void Transform(double *, double *, int, double (*)(double));

int main(void) {
    double sou[ARRAY_LEN];
    double tar[ARRAY_LEN];
    for (int i = 0; i < ARRAY_LEN; ++i) {
        sou[i] = i + 1.01;
    }
    for (int i = 0; i < ARRAY_LEN; ++i) {
        printf("%-6.2f ", sou[i]);
        if ((i + 1) % 20 == 0)
            putchar('\n');
    }
    puts("After plus:");
    Transform(sou, tar, ARRAY_LEN, Plus);
    for (int i = 0; i < ARRAY_LEN; ++i) {
        printf("%-6.2f ", tar[i]);
        if ((i + 1) % 20 == 0)
            putchar('\n');
    }
    puts("After sub:");
    Transform(sou, tar, ARRAY_LEN, Sub);
    for (int i = 0; i < ARRAY_LEN; ++i) {
        printf("%-6.2f ", tar[i]);
        if ((i + 1) % 20 == 0)
            putchar('\n');
    }
    puts("After sin:");
    Transform(sou, tar, ARRAY_LEN, sin);
    for (int i = 0; i < ARRAY_LEN; ++i) {
        printf("%-6.2f ", tar[i]);
        if ((i + 1) % 20 == 0)
            putchar('\n');
    }
    puts("After cos:");
    Transform(sou, tar, ARRAY_LEN, cos);
    for (int i = 0; i < ARRAY_LEN; ++i) {
        printf("%-6.2f ", tar[i]);
        if ((i + 1) % 20 == 0)
            putchar('\n');
    }

    return 0;
}
double Plus(double x) {
    return x + 1;
}
double Sub(double x) {
    return x - 1;
}
void Transform(double *source, double *target, int len, double (*pf)(double)) {
    for (int i = 0; i < len; ++i) {
        target[i] = pf(source[i]);
    }
}
