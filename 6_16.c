//
// Created by liam on 8/18/21.
//
#include <math.h>
#include <stdio.h>
int main(void) {
    const double rates = 0.05;
    double origin = 100.0;
    double deirdre, daphne;
    int year = 1;
    deirdre = origin * pow(1 + rates, (double) year);
    daphne = origin * (1 + 0.1 * year);
    while (deirdre < daphne) {
        year++;
        deirdre = origin * pow(1 + rates, (double) year);
        daphne = origin * (1 + 0.1 * year);
    }
    printf("After %d years, deirdre > daphne\ndeirdre    daphne\n", year);
    printf("%-10lf %-lf\n", deirdre, daphne);
    return 0;
}