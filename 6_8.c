//
// Created by liam on 8/18/21.
//
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    long double num1, num2;
    while (scanf("%Lf %Lf", &num1, &num2) == 2) {
        long double diff = num1 - num2;
        long double production = num1 * num2;
        long double result = diff / production;
        printf("%.14Lf/%.14Lf=%.14Lf\n", diff, production, result);
    }
    printf("Done!");
    return 0;
}
