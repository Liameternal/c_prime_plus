//
// Created by liam on 8/29/21.
//
#include <stdio.h>
#include "pe12-2a.h"

int main(void) {
    int mode;
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0) {
        SetMode(mode);
        GetInfo();
        ShowInfo();
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    puts("Done!");
    return 0;
}

