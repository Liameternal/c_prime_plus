#include <stdio.h>

#define BASE_2 2
#define BASE_8 8
#define BASE_16 16

void to_binary(unsigned int dec, int base);

int main(void) {
    unsigned int decimal;
    int base = 2;
    printf("Enter a decimal number and base to be transfered"
           "( less than 65536 ,q to quit.):");
    while (scanf("%u %d", &decimal, &base) == 2) {
        printf("Number %u -- base %d: \n", decimal, base);
        to_binary(decimal, base);
        putchar('\n');
        printf("Enter a decimal number and base to be transfered"
               "( less than 65536 ,q to quit.):");
    }
    printf("Bye!\n");

    return 0;
}


void to_binary(unsigned int dec, int base) {
    int r;
    r = dec % base;
    if (dec >= base)
        to_binary(dec / base, base);
    if (base == 16) {
        if (r > 9 && r < 16)
            printf("%c", r + 55);
        else
            printf("%d", r);
    } else
        printf("%d", r);
}
