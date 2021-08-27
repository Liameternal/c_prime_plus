//
// Created by liam on 8/24/21.
//
#include <stdio.h>

void CHLine(char, int, int);

int main(void) {
    char ch;
    int i, j;
    printf("What a kind of character do you want to show?");
    ch = getchar();
    while (getchar() != '\n')
        continue;
    printf("How many line do you want to print?");
    scanf("%d", &i);
    printf("How many column do you want to print?");
    scanf("%d", &j);
    CHLine(ch, i, j);

    return 0;
}

void CHLine(char ch, int i, int j) {
    for (int k = 0; k < i; ++k) {
        for (int l = 0; l < j; ++l) {
            putchar(ch);
        }
        putchar('\n');
    }
}
