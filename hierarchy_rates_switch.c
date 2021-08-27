//
// Created by liam on 8/23/21.
//
#include <stdio.h>
#include <stdlib.h>

#define RATE1 0.15
#define RATE2 0.2
#define RATE3 0.25
#define BREAK1 300
#define BREAK2 450
#define BASE1 BREAK1*RATE1
#define BASE2 BASE1 + (BREAK2-BREAK1)*RATE2

#define pay_rate1 8.75
#define pay_rate2 9.33
#define pay_rate3 10.00
#define pay_rate4 11.20


void PrintInfo(float pay) {
    const float NORMAL_TIME = 40; //regular work time
    const float TIME_RATE = 1.5f; //overtime calculate rate
    float hour_week = 0; //work hours a week
    double money = 0; //gross money
    double tax = 0; //taxes
    double net = 0; //net money

    printf("Enter hours you work every week(less or equal 0 exit):");
    while (scanf("%f", &hour_week) && hour_week > 0) {
        if (hour_week <= NORMAL_TIME) {
            money = hour_week * pay;
        } else {
            money = (hour_week + (hour_week - NORMAL_TIME) * TIME_RATE) * pay;
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
}

void menu(void) {
    short menu_order = 0;

    system("clear");
    printf("*********************************************************\n");
    printf("Enter the number corresponding to the desired pay rate "
           "or action:\n");
    printf("1) $%.2f/hr                        2) $%.2f/hr\n",
           pay_rate1, pay_rate2);
    printf("3) $%.2f/hr                       4) $%.2f/hr\n",
           pay_rate3, pay_rate4);
    printf("5) quit\n");
    printf("*********************************************************\n");
    scanf("%hd", &menu_order);
    switch (menu_order) {
        case 1:
            PrintInfo(pay_rate1);
            menu();
            break;
        case 2:
            PrintInfo(pay_rate2);
            menu();
            break;
        case 3:
            PrintInfo(pay_rate3);
            menu();
            break;
        case 4:
            PrintInfo(pay_rate4);
            menu();
            break;
        case 5:
            exit(0);
        default:
            printf("Please enter a number between 1 and 5\n");
            menu();

    }
}

int main(void) {
    menu();

    return 0;
}


