//
// Created by liam on 8/23/21.
//
#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int positive_num;
    bool is_prime = true;
    printf("Enter a positive number:");
    int status = scanf("%d", &positive_num);
    if (status && positive_num > 0) {
        for (int i = 2; i <= positive_num; ++i) {
            for (int j = 2; j * j < i; ++j) {
                if (i % j == 0) {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime) {
                printf("%d is prime.\n", i);
            }
            is_prime = true;
        }
    } else {
        printf("Done!");
    }
    return 0;
}

