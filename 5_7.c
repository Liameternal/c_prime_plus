//
// Created by liam on 8/16/21.
//
#include <stdio.h>

double Cube(double x) {
    return x * x * x;
}
int main(void) {
    double n;
    printf("enter a number(less equal 0 exit):");
    while (scanf("%lf", &n) == 1 && n > 0) {
        printf("The cube of %.6f is %.6f.\n", n, Cube(n));
        printf("enter a number(less equal 0 exit):");
    }
    printf("Done!\n");
}
