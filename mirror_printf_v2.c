//
// Created by liam on 8/17/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void MirrorPrint(char mirror[], int len, int space);
int main(void) {
    const int MIRROR_LENGTH = 20;
    char *mirror = (char *) malloc(MIRROR_LENGTH * sizeof(char));
    printf("Enter a string to be mirror printed(CTRL+D exit):");

    while (scanf("%s", mirror) != EOF) {
        int len = strlen(mirror);
        int space = 0;
        MirrorPrint(mirror, len, space);
        printf("Enter a string to be mirror printed(CTRL+D exit):");
    }
    return 0;
}
void MirrorPrint(char mirror[], int len, int space) {
    if (1 == len) {
        int count = 0;
        while (count++ < space) {
            putchar(' ');
        }
        putchar(mirror[len - 1]);
        putchar('\n');
        return;
    }
    int count = 0;
    while (count++ < space) {
        putchar(' ');
    }
    for (int i = len - 1; i > 0; --i) {
        putchar(mirror[i]);
    }
    for (int i = 0; i < len; ++i) {
        putchar(mirror[i]);
    }
    putchar('\n');
    MirrorPrint(mirror, len - 1, space + 1);
}
