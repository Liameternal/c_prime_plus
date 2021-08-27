//
// Created by liam on 8/23/21.
//
#include <stdio.h>

#define RATE1 0.15
#define RATE2 0.2
#define RATE3 0.25
#define BREAK1 300
#define BREAK2 450
#define BASE1 BREAK1*RATE1
#define BASE2 BASE1 + (BREAK2-BREAK1)*RATE2

int main(void) {
    const float NORMAL_TIME = 40; //regular work time
    const float SALARY = 1000;  //1000 dollars per hour
    const float TIME_RATE = 1.5f; //overtime calculate rate
    float hour_week = 0; //work hours a week
    double money = 0; //gross money
    double tax = 0; //taxes
    double net = 0; //net money

    printf("Enter hours you work every week(less or equal 0 exit):");
    while (scanf("%f", &hour_week) && hour_week > 0) {
        if (hour_week <= NORMAL_TIME) {
            money = hour_week * SALARY;
        } else {
            money = (hour_week + (hour_week - NORMAL_TIME) * TIME_RATE) *
                    SALARY;
        }
        if (money <= 300) {
            tax = money * RATE1;
            net = money - tax;
        } else if (money <= 450) {
            tax = BASE1 + (money - BREAK1) * RATE2;
            net = money - tax;
        } else {
            tax = BASE2 + (money - BREAK2) * RATE3;
            net = money - tax;
        }
        printf("total money: %.2f  tax: %.2f  net:%.2f.\n",
               money, tax, net);
        printf("Enter another hours you work every "
               "week(less or equal 0 exit):");
    }
    return 0;
}

