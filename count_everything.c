//
// Created by liam on 8/29/21.
//
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

void Count(void);

int main(void) {
    Count();
    return 0;
}

void Count(void) {
    int ch;
    bool is_word = false;
    int words = 0;
    int upper = 0;
    int lower = 0;
    int punct = 0;
    int num = 0;
    while ((ch = getchar()) && ch != '#') {
        if (isalpha(ch))
            is_word = true;
        else {
            if(is_word){
                words++;
                is_word=false;
            }
        }
        if (isupper(ch))
            upper++;
        if (islower(ch))
            lower++;
        if (ispunct(ch))
            punct++;
        if (isdigit(ch))
            num++;
    }
    printf("words:%d\nupper:%d\nlower:%d\npunct:%d\nnum:%d\n",
           words, upper, lower, punct, num);
}
