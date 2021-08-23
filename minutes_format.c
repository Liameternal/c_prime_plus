//
// Created by liam on 8/15/21.
//
#include <stdio.h>

int main(void) {
    const int SCALE = 60;
    int minute;
    int hour;
    int minutes;
    printf("Enter minutes(less equal 0 exit):____\b\b\b\b");
    while (scanf("%d", &minutes) && minutes > 0) {
        hour = minutes / SCALE;
        minute = minutes % SCALE;
        printf("%d transform to %d:%d(Hour:Minute).\n",
               minutes, hour, minute);
        printf("Enter minutes(less equal 0 exit):____\b\b\b\b");
    }
    printf("Done!\n");
}