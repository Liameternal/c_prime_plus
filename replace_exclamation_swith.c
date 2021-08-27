//
// Created by liam on 8/23/21.
//
#include <stdio.h>

int main(void) {
    char ch;
    while (scanf("%c", &ch) && ch != '#') {
        switch (ch) {
            case '.':
                printf("!");
                break;
            case '!':
                printf("!!");
                break;
            default:
                putchar(ch);
        }
    }
    return 0;
}


