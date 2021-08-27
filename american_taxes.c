//
// Created by liam on 8/23/21.
//
#include <stdio.h>
#include <stdlib.h>

const float RATE1 = 0.15f;
const float RATE2 = 0.28f;
const float SINGLE_BREAK = 17850;
const float OWNER_BREAK = 23900;
const float MARRIED_BREAK = 29750;
const float DIVORCED_BREAK = 14875;
const float SINGLE_BASE = SINGLE_BREAK * RATE1;
const float OWNER_BASE = OWNER_BREAK * RATE1;
const float MARRIED_BASE = MARRIED_BREAK * RATE1;
const float DIVORCED_BASE = DIVORCED_BREAK * RATE1;

void Taxes(float start, char flag);

void menu(void);

int main(void) {
    menu();
    return 0;
}

void Taxes(float start, char flag) {
    float money;
    float taxes;
    printf("Please enter the amount of money:");
    if (scanf("%f", &money)) {
        if (money < start)
            printf("you should pay %.2f taxes.\n", money * RATE1);
        else {
            switch (flag) {
                case 's':
                    taxes = SINGLE_BASE + (money - SINGLE_BREAK) * RATE2;
                    printf("you should pay %.2f taxes.\n", taxes);
                    break;
                case 'o':
                    taxes = OWNER_BASE + (money - OWNER_BREAK) * RATE2;
                    printf("you should pay %.2f taxes.\n", taxes);
                    break;
                case 'm':
                    taxes = MARRIED_BASE + (money - MARRIED_BREAK) * RATE2;
                    printf("you should pay %.2f taxes.\n", taxes);
                    break;
                case 'd':
                    taxes = DIVORCED_BASE + (money - DIVORCED_BREAK) * RATE2;
                    printf("you should pay %.2f taxes.\n", taxes);
                    break;
            }
        }
    } else
        printf("input error!\n");
    printf("Strike any key to continue.\n");
    getchar();
    getchar();
}

void menu(void) {
    char menu_order = 0;

    system("clear");
    printf("*********************************************************\n");
    printf("Enter the number corresponding to the desired pay rate "
           "or action:\n");
    printf("s) single                        o) owner\n");
    printf("m) married                       d) divorced\n");
    printf("q) quit\n");
    printf("*********************************************************\n");
    scanf("%c", &menu_order);
    switch (menu_order) {
        case 's':
            Taxes(SINGLE_BREAK, 's');
            menu();
            break;
        case 'o':
            Taxes(OWNER_BREAK, 'o');
            menu();
            break;
        case 'm':
            Taxes(MARRIED_BREAK, 'm');
            menu();
            break;
        case 'd':
            Taxes(DIVORCED_BREAK, 'd');
            menu();
            break;
        case 'q':
            exit(0);
        default:
            printf("Please enter a alpha before function.\n");
            menu();

    }

}
