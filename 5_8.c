//
// Created by liam on 8/16/21.
//
#include <stdio.h>

int main(void) {
    int modulus;
    int first_operand;
    printf("enter a modulus(great then 0):");
    scanf("%d", &modulus);
    printf("Now enter the first operand(less equal 0 exit):");
    while (scanf("%d", &first_operand) == 1 && first_operand > 0) {
        printf("%d %% %d = %d.\n",
               first_operand, modulus, first_operand % modulus);
        printf("enter a number(less equal 0 exit):");
    }
    printf("Done!\n");
}
