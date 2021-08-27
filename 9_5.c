//
// Created by liam on 8/24/21.
//
#include <stdio.h>

void LargerOf(double *x, double *y);

int main(void) {
    double x, y;
    printf("Enter two number(q to quit):");
    while (scanf("%lf %lf", &x, &y)) {
        printf("Before x:%.2f y:%.2f\n", x, y);
        LargerOf(&x, &y);
        printf("After x:%.2f y:%.2f\n", x, y);
        printf("Enter two number(q to quit):");
    }
    printf("Bye!\n");

    return 0;
}

void LargerOf(double *x, double *y) {
    *x = *y = (*x > *y) ? *x : *y;
}

