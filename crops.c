#include <stdio.h>

#define SQUARES 64// exponent

int main(void) {
    const double CROP = 2E16;// annual production whole world
    double current, total;
    int count = 1;

    printf("square          grains          total          "
           "fraction of\n");
    printf("                added           grains         "
           "world total\n");
    total = current = 1.0;
    while (count < SQUARES) {

        printf("%4d            %-.2e        %-.2e       %-.2e\n", count,
               current,
               total, total / CROP);
        count++;
        current *= 2;
        total += current;
    }
    printf("That's all.\n");

    return 0;
}
