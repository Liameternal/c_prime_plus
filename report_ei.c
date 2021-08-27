//
// Created by liam on 8/23/21.
//
#include <stdio.h>
#include <stdbool.h>

int main(void) {
    char ch;
    char ch_front;
    int time = 0;
    bool is_first_ch = true;
    while (scanf("%c", &ch) && ch != '#') {
        if (is_first_ch) {
            ch_front = ch;
            is_first_ch = false;
            continue;
        }
        if (ch_front == 'e' && ch == 'i') {
            time++;
        }
        ch_front = ch;

    }
    printf("ei appeared %d times.\n", time);
    return 0;
}

