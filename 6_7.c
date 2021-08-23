//
// Created by liam on 8/18/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char *word = (char *) malloc(20 * sizeof(char));
    int len;
    for (printf("Enter a string(CTRL+D exit:"),
         scanf("%s", word), len = strlen(word) - 1;
         len >= 0;
         --len) {
        putchar(word[len]);
    }
    return 0;
}
