//
// Created by liam on 9/5/21.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MONTH_PER_YEAR 12
#define MONTH_NAME_LEN 11
#define MONTH_ABB 3

typedef struct {
    char month_name[MONTH_NAME_LEN];
    char abb[MONTH_ABB];
    int days;
    int month_num;
} MONTH;
MONTH month[MONTH_PER_YEAR] = {
        {"January", "Jan", 31, 1},
        {"February", "Feb", 28, 2},
        {"March", "Mar", 31, 3},
        {"April", "Apr", 30, 4},
        {"May", "May", 31, 5},
        {"June", "Jun", 30, 6},
        {"July", "Jul", 31, 7},
        {"August", "Aug", 31, 8},
        {"September", "Sep", 30, 9},
        {"October", "Oct", 31, 10},
        {"December", "Dec", 30, 11},
        {"November", "Nov", 31, 12}
};
const int common_year[MONTH_PER_YEAR] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31,
                                         30, 31};
const int leap_year[MONTH_PER_YEAR] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31,
                                       30, 31};
typedef struct {
    unsigned short year;
    union {
        unsigned short month_num;
        char month_name[MONTH_NAME_LEN];
    };
    unsigned short days;
} CALENDAR;

void EraseBuff(void) {
    while (getchar() != '\n')
        continue;
}

bool IsCommonYear(unsigned short y) {
    if ((y % 4 == 0 && y % 100 == 0) || y % 400 == 0)
        return false;
    return true;
}

int main(void) {
    CALENDAR day;
    unsigned short total;
    printf("Enter a day of a year: ");
    while (total = 0, scanf("%hu", &day.days) == 1 &&
                      day.days != 0) {
        printf("Enter a month of a year: ");
        scanf("%hu", &day.month_num) == 1 || scanf("%10s", day.month_name);
//        if (scanf("%hu", &day.month_num) != 1) {
//            scanf("%10s", day.month_name);
//        }
        if (day.month_num < 1 || day.month_num > 12) {
            for (int i = 0; i < MONTH_PER_YEAR; ++i) {
                if (strcmp(day.month_name, month[i].month_name)==0 ||
                        strcmp(day.month_name, month[i].abb) == 0) {
                    day.month_num = (unsigned short) month[i].month_num;
                    break;
                }
            }
        }
        printf("Enter a year: ");
        if (scanf("%hu", &day.year) != 1) {
            continue;
        }
        if (IsCommonYear(day.year)) {
            for (int i = 0; i < day.month_num - 1; ++i) {
                total += common_year[i];
            }
            total += day.days;
            printf("Days:%hu\n", total);
        } else {
            for (int i = 0; i < day.month_num - 1; ++i) {
                total += leap_year[i];
            }
            total += day.days;
            printf("Days:%hu\n", total);
        }
        printf("Enter another day of a year(0 to quit): ");
    }
    puts("Done!");

    return 0;
}