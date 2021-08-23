//
// Created by liam on 8/16/21.
//
#include <stdio.h>

int main(void) {
    int days;
    const int DAYS_TO_WEEK = 7;  // 7 days a week
    const int DAYS_TO_YEAR = 365;// 365 days a year
    printf("enter a number(less equal 0 exit):");
    while (scanf("%d", &days) == 1 && days > 0) {
        int year;
        int week;
        int day;
        year = days / DAYS_TO_YEAR;
        week = (days - year * DAYS_TO_YEAR) / DAYS_TO_WEEK;
        day = days - year * DAYS_TO_YEAR - week * DAYS_TO_WEEK;
        printf("%d days is %d year(s) %d week(s) and %d day(s).\n", days, year, week, day);
        printf("enter a number(less equal 0 exit):");
    }
    printf("Done!\n");
}
