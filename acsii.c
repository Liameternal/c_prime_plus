//
// Created by liam on 8/23/21.
//
#include <stdio.h>

int main(void) {
    const int LINE_CH = 8;
    char ch;
    printf("enter a string end with #:");
    int count = 0;
    while ((ch = getchar()) && ch != '#') {
        printf("%c:%d  ", ch, ch);
        count++;
        if (count % LINE_CH == 0)
            putchar('\n');
    }
    return 0;
}

