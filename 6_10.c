//
// Created by liam on 8/18/21.
//
#include <stdio.h>

int main(void) {
    long lower, upper;
    while (printf("Enter lower and upper interger limits:"),
           scanf("%ld %ld", &lower, &upper) && lower < upper) {
        long sum = 0;
        for (int i = lower; i <= upper; ++i) {
            sum += i * i;
        }
        printf("The sums of the squares from %ld to %ld is %ld.\n",
               lower, upper, sum);
    }
    printf("Done!\n");
    return 0;
}
