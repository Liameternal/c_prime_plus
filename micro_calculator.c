//
// Created by liam on 8/24/21.
//
#include <stdio.h>

void Menu(void);

void Add(void);

void Subtract(void);

void Multiply(void);

void Divide(void);

void GetOperators(float *operator_1, float *operator_2);

char GetOption(void);

void EraseRemainCH();

int main(void) {
    Menu();
    return 0;
}

void Menu(void) {
    char option;
    printf("Enter the operation of your choice:\n");
    printf("a. add                     s. subtract\n");
    printf("m. multiply                d. divide\n");
    printf("q.quit\n");
    option = GetOption();
    switch (option) {
        case 'a':
            Add();
            break;
        case 's':
            Subtract();
            break;
        case 'm':
            Multiply();
            break;
        case 'd':
            Divide();
            break;
        case 'q':
            printf("Bye!\n");
            break;
        default:
            break;
    }
}

void Add(void) {
    float operator_1, operator_2;
    float result = 0;
    GetOperators(&operator_1, &operator_2);
    result = operator_1 + operator_2;
    printf("%.2f + %.2f = %.2f\n", operator_1, operator_2, result);
    printf("Strike ant key to continue...\n");
    getchar();
    Menu();
}

void Subtract(void) {
    float operator_1, operator_2;
    float result = 0;
    GetOperators(&operator_1, &operator_2);
    result = operator_1 - operator_2;
    printf("%.2f - %.2f = %.2f\n", operator_1, operator_2, result);
    printf("Strike ant key to continue...\n");
    getchar();
    Menu();
}

void Multiply(void) {
    float operator_1, operator_2;
    float result = 0;
    GetOperators(&operator_1, &operator_2);
    result = operator_1 * operator_2;
    printf("%.2f * %.2f = %.2f\n", operator_1, operator_2, result);
    printf("Strike ant key to continue...\n");
    getchar();
    Menu();
}

void Divide(void) {
    float operator_1, operator_2;
    float result = 0;
    GetOperators(&operator_1, &operator_2);
    while (operator_2 == 0) {
        printf("Enter a number other than 0:");
        while (scanf("%f", &operator_2) != 1) {
            EraseRemainCH();
            printf("Please enter a number"
                   " ,such as 2.5, -1..78E8, or 3:");
        }
        EraseRemainCH();
    }
    result = operator_1 / operator_2;
    printf("%.2f / %.2f = %.2f\n", operator_1, operator_2, result);
    printf("Strike ant key to continue...\n");
    getchar();
    Menu();
}

void GetOperators(float *operator_1, float *operator_2) {
    printf("Enter first number:");
    while (scanf("%f", operator_1) != 1) {
        EraseRemainCH();
        printf("Please enter a number"
               " ,such as 2.5, -1..78E8, or 3:");
    }
    printf("Enter second number:");
    while (scanf("%f", operator_2) != 1) {
        EraseRemainCH();
        printf("Please enter a number"
               " ,such as 2.5, -1..78E8, or 3:");
    }
    EraseRemainCH();
}

char GetOption(void) {
    char option;
    while (scanf(" %c", &option) != 1) {
        EraseRemainCH();
        printf("Please enter alpha before function.\n");
    }
    while (option != 'a' && option != 's' && option != 'm' && option != 'd' &&
           option != 'q') {
        EraseRemainCH();
        printf("Please enter alpha before function.\n");
    }
    EraseRemainCH();
    return option;
}

void EraseRemainCH() {
    while (getchar() != '\n')
        continue;
}
