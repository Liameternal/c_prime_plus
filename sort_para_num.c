//
// Created by liam on 8/24/21.
//
#include <stdio.h>

void SortParaNum(double *x, double *y, double *z);

int main(void) {
    double x, y, z;
    printf("Enter three number(q to quit):");
    while (scanf("%lf %lf %lf", &x, &y, &z)) {
        printf("Before x:%.2f y:%.2f x:%.2f\n", x, y, z);
        SortParaNum(&x,&y,&z);
        printf("After x:%.2f y:%.2f x:%.2f\n", x, y, z);
        printf("Enter three number(q to quit):");
    }
    printf("Bye!\n");

    return 0;
}

void SortParaNum(double *x, double *y, double *z) {
    double a, b, c;
    a = *x;
    b = *y;
    c = *z;
    double min, max;
    min = (a < b) ? a : b;
    min = (min < c) ? min : c;
    max = (a > b) ? a : b;
    max = (max > c) ? max : c;
    *x = min;
    *z = max;
    if (a != min && a != max)
        *y = a;
    else if (b != min && b != max)
        *y = b;
    else if (c != min && c != max)
        *y = c;
}

