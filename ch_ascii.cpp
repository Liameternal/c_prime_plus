//
// Created by liam on 8/24/21.
//
#include <stdio.h>

int main(void) {
    int ch;
    const int CH_PER_LINE = 10;
    int count = 0;
    while ((ch = getchar()) != EOF) {
        if (ch < 32) {
            if ((char) ch == '\n') {
                printf("\\n:%d\n", ch);
                count = 0;
                continue;
            }
            if ((char) ch == '\t') {
                printf("\\t:%d ", ch);
                count++;
                if (count % CH_PER_LINE == 0)
                    putchar('\n');
                continue;
            }
            putchar('^');
            putchar(ch + 64);
            printf(":%d ", ch);
            count++;
            if (count % CH_PER_LINE == 0)
                putchar('\n');
            continue;
        }
        putchar(ch);
        printf(":%d ", ch);
        count++;
        if (count % CH_PER_LINE == 0)
            putchar('\n');
    }
    return 0;
}
