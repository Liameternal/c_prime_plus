//
// Created by liam on 8/18/21.
//
#include <math.h>
#include <stdio.h>
int main(void) {
    int exp[8];
    for (int i = 1; i <= 8; ++i) {
        exp[i - 1] = (int) pow(2.0, (double) i);
    }
    int i = 1;
    do {
        printf("2 to the power of %d is %d\n", i, exp[i - 1]);
        i++;
    } while (i <= 8);
    printf("Done!\n");
    return 0;
}
