//
// Created by liam on 8/24/21.
//
#include <stdio.h>

double Min(double, double);

int main(void) {
    double x_1, x_2;
    double min;
    printf("Enter two number(q to quit):");
    while (scanf("%lf %lf", &x_1, &x_2)) {
        min = Min(x_1, x_2);
        printf("Smaller one is %.2f\n", min);
        printf("Enter two number(q to quit):");
    }
    return 0;
}

double Min(double a, double b) {
    return a > b ? b : a;
}
