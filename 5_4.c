//
// Created by liam on 8/16/21.
//
#include <stdio.h>

int main(void) {
    float height;
    const float CENTIMETERS_TO_FEET = 0.032808f;// 1cm = 0.032808 ft
    const int FEET_TO_INCHES = 12;              // 1 ft = 12 inches
    printf("Enter a height in centimeters(less equal 0 exit):");
    while (scanf("%f", &height) == 1 && height > 0) {
        float feet;
        float inches;
        feet = (int) (height * CENTIMETERS_TO_FEET);
        inches = (height * CENTIMETERS_TO_FEET - feet) * (float) FEET_TO_INCHES;
        printf("%.1f height = %.1f feet, %.1f inches \n", height, feet, inches);
        printf("enter a number(less equal 0 exit):");
    }
    printf("Done!\n");
}
