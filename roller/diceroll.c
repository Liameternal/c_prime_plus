//
// Created by liam on 8/30/21.
//

#include "diceroll.h"
#include <stdio.h>
#include <stdlib.h>

static int Roll(int sides) {
    return rand() % sides + 1;
}

int RollNDice(int dice, int sides) {
    int total = 0;
    if (sides < 2) {
        printf("Need at least 2 sides.\n");
        return -2;
    }
    if (dice < 1) {
        printf("Need at least 1 die.\n");
        return -1;
    }
    for (int i = 0; i < dice; ++i) {
        total += Roll(sides);
    }
    return total;
}
