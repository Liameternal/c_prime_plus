//
// Created by liam on 8/27/21.
//
#include <stdio.h>

#define LEN 4

void ArrAdd(double *tar, const double *arr1, const double *arr2, int len);

int main(void) {
    double arr1[LEN] = {2, 4, 5, 8};
    double arr2[LEN] = {1, 0, 4, 6};
    double tar[LEN];
    ArrAdd(tar, arr1, arr2, LEN);
    printf("arr1:\n");
    for (int i = 0; i < LEN; ++i) {
        printf("%.2f ", arr1[i]);
    }
    printf("\narr2:\n");
    for (int i = 0; i < LEN; ++i) {
        printf("%.2f ", arr2[i]);
    }
    printf("\ntar:\n");
    for (int i = 0; i < LEN; ++i) {
        printf("%.2f ", tar[i]);
    }
    return 0;
}

void ArrAdd(double *tar, const double *arr1, const double *arr2, int len) {
    for (int i = 0; i < len; ++i) {
        tar[i] = arr1[i] + arr2[i];
    }
}

