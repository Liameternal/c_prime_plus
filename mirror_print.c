//
// Created by liam on 8/17/21.
//
#include <stdio.h>
#include <string.h>
int main(void) {
    char mirror[100] = "abcdef";

    printf("Enter a string to be mirror printed(CTRL+D exit):");
    while (scanf("%s",mirror)!=EOF) {
        getchar();
        int row = strlen(mirror);
        int len = strlen(mirror);
        for (int i = 0; i < row; ++i) {
            int space = 0;
            while (space++ < i)
                putchar(' ');
            for (int j = len - 1 - i; j > 0; --j) {
                putchar(mirror[j]);
            }
            for (int j = 0; j < len - i; ++j) {
                putchar(mirror[j]);
            }
            putchar('\n');
        }
        printf("Enter a string to be mirror printed(CTRL+D exit):");
    }
    printf("Done!\n");
    return 0;
}
