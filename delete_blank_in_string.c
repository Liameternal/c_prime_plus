//
// Created by liam on 8/29/21.
//
#include <stdio.h>
#include <string.h>

char *DeleteBlank(char *str);

int main(void) {
    char str[80];
    while (fgets(str, 80, stdin) && strcmp(str, "\n")) {
        fputs(str,stdout);
        DeleteBlank(str);
        fputs(str,stdout);
    }
    return 0;
}

char *DeleteBlank(char *str) {
    char *rel = str;
    char *p_str = str;
    char *b_str;
    char *mark;
    while (*p_str++) {
        if (*p_str == ' ') {
            mark = p_str;
            b_str = p_str;
            while (*b_str) {
                *b_str = *(++p_str);
                b_str++;
            }
            p_str = mark;
        }
    }
    return rel;
}
