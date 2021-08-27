#include <stdio.h>

void Ptr(const int *);

int main(void) {
    int arr[5] = {0};
    const int *pi;
    pi = &arr[3];
    Ptr(arr);
    putchar('\n');
    printf("lenth:%zd", sizeof arr);
    return 0;
}

void Ptr(const int *arr) {
    printf("lenth:%d", *arr);
}
