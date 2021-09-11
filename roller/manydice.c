//
// Created by liam on 8/30/21.
//
#include "diceroll.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int dice = 0;
    int sides = 0;
    int status = 0;
    int sets = 0;

    srand((unsigned int) time(0));
    printf("Enter the number of sets;enter q to stop.\n");
    while (scanf("%d", &sets) == 1 && sets != 'q') {
        int result[sets];
        printf("How many sides and how many dice?\n");
        if ((status = scanf("%d %d", &sides, &dice)) != 2) {
            if (status == EOF)
                break;
            else {
                printf("You should have entered two integer.");
                printf(" Let's begin again.\n");
                while (getchar() != '\n')
                    continue;
            }
            printf("Enter the number of sets;enter q to stop.\n");
            continue;
        }
        for (int i = 0; i < sets; ++i) {
            result[i] = RollNDice(dice, sides);
        }
        printf("Here are %d sets of %d %d=sided throws.\n",
               sets, dice, sides);
        for (int i = 0; i < sets; ++i) {
            printf("%d ", result[i]);
            if ((i + 1) % 10 == 0)
                putchar('\n');
        }
        putchar('\n');
        printf("Enter the number of sets;enter q to stop.\n");
    }
}

