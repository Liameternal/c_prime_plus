//
// Created by liam on 8/30/21.
//
#include <stdio.h>
#include <stdlib.h>

int *MakeArray(int, int);

void ShowArray(const int *, int);

int main(void) {
    int *pa;
    int size;
    int value;

    printf("Enter the number of elements: ");
    while (scanf("%d", &size) == 1 && size > 0) {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = MakeArray(size, value);
        if (pa) {
            ShowArray(pa, size);
            free(pa);
        }
        printf("Enter the number of elements (<1 to quit): ");
    }
}

int *MakeArray(int size, int val) {
    int *temp = (int *) malloc(size * sizeof(int));
    if (!temp) {
        printf("Failed to allocate memory.\n");
        return NULL;
    }
    for (int i = 0; i < size; ++i) {
        temp[i] = val;
    }
    return temp;
}

void ShowArray(const int *ar, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", ar[i]);
        if ((i + 1) % 8 == 0)
            putchar('\n');
    }
    putchar('\n');
}
