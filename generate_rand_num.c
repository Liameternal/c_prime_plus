//
// Created by liam on 8/29/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int *SortDescend(int [], int);

int main(void) {
    int num[100];
    srand((unsigned int) time(0));
    for (int i = 0; i < 100; ++i) {
        num[i] = rand() % 10 + 1;
//        usleep(100000);
    }
    for (int i = 0; i < 100; ++i) {
        printf("%d ", num[i]);
        if ((i + 1) % 10 == 0)
            putchar('\n');
    }
    SortDescend(num, 100);
    puts("Sorted.");
    for (int i = 0; i < 100; ++i) {
        printf("%d ", num[i]);
        if ((i + 1) % 10 == 0)
            putchar('\n');
    }
    return 0;
}

int *SortDescend(int num[], int n) {
    int temp;
    int *rel = num;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (num[i] < num[j]) {
                temp = num[j];
                num[j] = num[i];
                num[i] = temp;
            }
        }
    }
    return rel;
}
