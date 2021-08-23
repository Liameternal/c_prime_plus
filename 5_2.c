//
// Created by liam on 8/16/21.
//
#include <stdio.h>

int main(void) {
    int n;
    printf("enter a number(less equal 0 exit):");
    while (scanf("%d", &n) == 1 && n > 0) {
        int count = n;
        while (count <= n + 10) {
            printf("%d\t", count);
            count++;
        }
        putchar('\n');
        printf("enter a number(less equal 0 exit):");
    }
    printf("Done!\n");
}