//
// Created by liam on 8/24/21.
//
#include <stdio.h>

int GetNum();

char GetAnswer();

int main(void) {
    int num;
    num = GetNum();
    int low = 0;
    int high = 100;
    int medium = (low + high) / 2;
    char anwser;
    while (low <= high) {
        printf("%d is the number you entered.Yes or No?\n", medium);
        anwser = GetAnswer();
        if (anwser == 'y') {
            printf("Yes! I got it!\n");
            printf("Bye!\n");
            break;
        } else {
            printf("Oh! What a pity!\n");
            printf("Is that number bigger? Yes or No?");
            anwser = GetAnswer();
        }
        if (anwser == 'y') {
            low = medium;
            medium = (low + high) / 2;
        } else {
            high = medium;
            medium = (low + high) / 2;
        }
    }
    return 0;
}

int GetNum() {
    int num;
    printf("Please enter a number (0-100):");
    while (scanf("%d", &num) != 1 && num >= 0 && num <= 100) {
        while (getchar() != '\n')
            continue;
        printf("Please enter a number (0-100):");
    }
    while (getchar() != '\n')
        continue;
    return num;
}

char GetAnswer() {
    char answer;
    while ((answer = getchar()) != 'y') {
        if (answer == 'n') {
            while (getchar() != '\n')
                continue;
            return answer;
        } else {
            printf("Sorry! I can only know yes or no!\n");
        }
    }
    while (getchar() != '\n')
        continue;
    return answer;
}
