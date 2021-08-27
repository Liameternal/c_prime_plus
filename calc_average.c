//
// Created by liam on 8/23/21.
//
#include <stdio.h>

int main(void) {
    long number = -1;
    long even_number = 0;
    long odd_number = 0;
    double even_average = 0;
    double odd_average = 0;
    long even_sum = 0;
    long odd_sum = 0;
    printf("Enter a string of numbers divided by space(end with 0):");
    while (scanf("%ld", &number) && number != 0) {
        if (number % 2 == 0) {
            even_number++;
            even_sum += number;
        } else {
            odd_number++;
            odd_sum += number;
        }
    }
    if (even_number != 0)
        even_average = (double)even_sum / even_number;
    if (odd_number != 0)
        odd_average = (double)odd_sum / odd_number;
    printf("even numbers : %ld and average is : %.2f\n",
           even_number, even_average);
    printf("odd numbers : %ld and average is : %.2f\n",
           odd_number, odd_average);
    return 0;
}

