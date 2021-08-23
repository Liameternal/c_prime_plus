//
// Created by liam on 8/18/21.
//
#include <stdio.h>
int main(void) {
    long long count;
    printf("Enter a count number(less or equal to 0 exit!):");
    while (scanf("%lld", &count) && count > 0) {
        double sum_1 = 0;
        double sum_2 = 0;
        for (int i = 1; i <= count; ++i) {
            sum_1 += (double) 1 / i;
        }
        for (int i = 1; i <= count; ++i) {
            if (0 == i % 2) {
                sum_2 -= (double) 1 / i;
                continue;
            }
            if (1 == i % 2) {
                sum_2 += (double) 1 / i;
                continue;
            }
        }
        printf("%.1lf + %.1lf/%.1lf +...+%.1lf/%.1lf = %.1lf.\n",
               (double) 1, (double) 1, (double) 2, (double) 1, (double) count, sum_1);
        printf("%.1lf - %.1lf/%.1lf +...+%.1lf/%.1lf = %.1lf.\n",
               (double) 1, (double) 1, (double) 2, (double) 1, (double) count, sum_2);
        printf("Enter a count number(less or equal to 0 exit!):");
    }
    printf("Done!\n");
    return 0;
}
