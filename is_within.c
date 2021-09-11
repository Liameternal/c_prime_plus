//
// Created by liam on 8/29/21.
//
#include <stdio.h>
#include <stdbool.h>

bool InStr(const char *str, int c);

int main(void) {
    char *str = "I am a string!";
    int c;
    bool is_in_string = true;
    printf("Test weather a character is in a string.");
    printf("\nEnter a character(# to exit):");
    while ((c = getchar()) && c != '#') {
        while (getchar() != '\n')
            continue;
        is_in_string = InStr(str, c);
        if (is_in_string)
            printf("yes,%c is in the str.\n", c);
        else
            puts("Sorry! It's not in there.");
        printf("Enter a character(# to exit):");
    }
    puts("Done!");
    return 0;
}

bool InStr(const char *str, int c) {
    while (*str) {
        if (*str == c)
            return true;
        str++;
    }
    return false;
}
