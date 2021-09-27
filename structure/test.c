//
// Created by liam on 9/5/21.
//
#include <stdio.h>

typedef int (*I_FP_I_I_IP)(int, int, int *);

int Sum(int, int, int *);

void Show(I_FP_I_I_IP fp_sum, int, int, int *);

int main(void) {
    int x = 3, y = 5;
    int z;
    Show(Sum, x, y, &z);
    return 0;
}

int Sum(int x, int y, int *z) {
    *z = x * y;
    return x + y;
}

void Show(I_FP_I_I_IP fp_sum, int x, int y, int *z) {
    printf("sum of %d and %d is %d\n", x, y, fp_sum(x, y, z));
    printf("multiply of %d and %d is %d\n", x, y, *z);
}
