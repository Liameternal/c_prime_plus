//
// Created by liam on 8/18/21.
//
#include <stdio.h>
int main(void) {
    int up, down;
//    up = 8;
//    down = 1;
    printf("Enter a lower limit and a higher limit respectively"
           "(CTRL+D exit)");
    while (scanf("%d %d",&down,&up)!=EOF&&down<=up) {
        printf("n        n^2      n^3\n");
        for (int i = down; i <= up; ++i) {
            printf("%-8d %-8d %-d\n", i, i * i, i * i * i);
        }
        printf("Enter a lower limit and a higher limit respectively"
               "(CTRL+D exit)");
    }
    return 0;
}
