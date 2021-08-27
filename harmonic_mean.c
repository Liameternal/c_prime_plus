//
// Created by liam on 8/24/21.
//
#include <stdio.h>

double HarmonicMean(double a, double b);

int main(void) {
    double a, b;
    double harmonic_mean;
    printf("Enter two number(q to quit):");
    while (scanf("%lf %lf", &a, &b)) {
        harmonic_mean = HarmonicMean(a, b);
        printf("The harmonic mean of %f and %f is %f.\n", a, b, harmonic_mean);
        printf("Enter two number(q to quit):");
    }
    printf("Bye!\n");
    return 0;
}

double HarmonicMean(double a, double b) {
    double c = (1 / a + 1 / b) / 2;
    return 1 / c;
}
