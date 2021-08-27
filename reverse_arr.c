//
// Created by liam on 8/27/21.
//
#include <stdio.h>
#include <stdlib.h>

#define LEN 10

void ReverseArr(double *target, const double *resource, int len);

int main(void) {
    const double arr[LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double *tar = (double *) malloc(LEN * sizeof(double));
    ReverseArr(tar,arr,LEN);
    printf("Sources:\n");
    for (int i = 0; i < LEN; ++i) {
        printf("%.2f ",arr[i]);
    }
    printf("\nReversed:\n");
    for (int i = 0; i < LEN; ++i) {
        printf("%.2f ",tar[i]);
    }
    return 0;
}

void ReverseArr(double *target, const double *resource, int len) {
    for (int i = 0; i < len; ++i) {
        target[i] = resource[len - i - 1];
    }
}
