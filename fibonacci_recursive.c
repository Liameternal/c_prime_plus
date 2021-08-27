//
// Created by liam on 8/24/21.
//
#include <stdio.h>

long Fibonacci(long n);

int main(void) {
    long n;
    printf("How many fibonacci numbers do you want to show?");
    scanf("%ld", &n);
    for (int i = 0; i < n; ++i) {
        printf("%ld ", Fibonacci(i + 1));
        if ((i + 1) % 10 == 0)
            putchar('\n');
    }
    return 0;
}

long Fibonacci(long n) {
    if (n == 1 || n == 2)
        return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
