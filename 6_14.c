//
// Created by liam on 8/18/21.
//
#include <stdio.h>
int main(void) {
    int num[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int sum[8] = {0};
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            sum[i] += num[j];
        }
    }
    printf("num:");
    for (int i = 0; i < 8; ++i) {
        printf("%-2d ", num[i]);
    }
    putchar('\n');
    printf("sum:");
    for (int i = 0; i < 8; ++i) {
        printf("%-2d ", sum[i]);
    }
    return 0;
}
