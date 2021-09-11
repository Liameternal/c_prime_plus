//
// Created by liam on 9/1/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define LINE 20
#define COLUMN 30
#define SOURCEFILE "image.data"
#define AIMFILE "pic"

int main(void) {
    FILE *fp_source, *fp_aim;
    int num[LINE][COLUMN];
    int num_correction[LINE][COLUMN];

    if ((fp_source = fopen(SOURCEFILE, "r")) == NULL) {
        fprintf(stderr, "Can't open %s.\n", SOURCEFILE);
        exit(EXIT_FAILURE);
    }
    if ((fp_aim = fopen(AIMFILE, "w")) == NULL) {
        fprintf(stderr, "Can't open %s.\n", AIMFILE);
        exit(EXIT_FAILURE);
    }
    for (int r = 0; r < LINE; ++r) {
        for (int c = 0; c < COLUMN; ++c) {
            num[r][c] = getc(fp_source) - '0';
            getc(fp_source);
        }
    }
    for (int i = 0; i < LINE; ++i) {
        for (int j = 0; j < COLUMN; ++j) {
            if (i == 0) {
                if (j == 0) {
                    if (fabs(num[i][j] - num[i + 1][j]) > 1 &&
                        fabs(num[i][j] - num[i][j + 1]) > 1) {
                        num_correction[i][j] =
                                (int) (num[i + 1][j] + num[i][j + 1]) / 2;
                        continue;
                    }
                }
                if (j == COLUMN - 1) {
                    if (fabs(num[i][j] - num[i + 1][j]) > 1 &&
                        fabs(num[i][j] - num[i][j - 1]) > 1) {
                        num_correction[i][j] =
                                (int) (num[i + 1][j] + num[i][j - 1]) / 2;
                        continue;
                    }
                }
                if (fabs(num[i][j] - num[i][j - 1]) > 1 &&
                    fabs(num[i][j] - num[i][j + 1]) > 1 &&
                    fabs(num[i][j] - num[i + 1][j]) > 1) {
                    num_correction[i][j] =
                            (int) (num[i + 1][j] + num[i][j + 1] +
                                   num[i][j - 1]) / 3;
                    continue;
                }
            }
            if (i == LINE - 1) {
                if (j == 0) {
                    if (fabs(num[i][j] - num[i - 1][j]) > 1 &&
                        fabs(num[i][j] - num[i][j + 1]) > 1) {
                        num_correction[i][j] =
                                (int) (num[i - 1][j] + num[i][j + 1]) / 2;
                        continue;
                    }
                }
                if (j == COLUMN - 1) {
                    if (fabs(num[i][j] - num[i - 1][j]) > 1 &&
                        fabs(num[i][j] - num[i][j - 1]) > 1) {
                        num_correction[i][j] =
                                (int) (num[i - 1][j] + num[i][j - 1]) / 2;
                        continue;
                    }
                }
                if (fabs(num[i][j] - num[i][j - 1]) > 1 &&
                    fabs(num[i][j] - num[i][j + 1]) > 1 &&
                    fabs(num[i][j] - num[i - 1][j]) > 1) {
                    num_correction[i][j] =
                            (int) (num[i - 1][j] + num[i][j + 1] +
                                   num[i][j - 1]) / 3;
                    continue;
                }
            }
            if (fabs(num[i][j] - num[i][j - 1]) > 1 &&
                fabs(num[i][j] - num[i][j + 1]) > 1 &&
                fabs(num[i][j] - num[i + 1][j]) > 1 &&
                fabs(num[i][j] - num[i - 1][j]) > 1) {
                num_correction[i][j] =
                        (int) (num[i + 1][j] + num[i][j + 1] +
                               num[i][j - 1] + num[i + 1][j]) / 4;
                continue;
            }
            num_correction[i][j] = num[i][j];
        }
    }
    puts("num:");
    for (int i = 0; i < LINE; ++i) {
        for (int j = 0; j < COLUMN; ++j) {
            printf("%d ", num[i][j]);
        }
        putchar('\n');
    }
    puts("num_correction:");
    for (int i = 0; i < LINE; ++i) {
        for (int j = 0; j < COLUMN; ++j) {
            printf("%d ", num_correction[i][j]);
        }
        putchar('\n');
    }

    for (int i = 0; i < LINE; ++i) {
        for (int j = 0; j < COLUMN; ++j) {
            fprintf(fp_aim, "%d ", num_correction[i][j]);
        }
        fputc('\n', fp_aim);
    }
    fclose(fp_aim);
    fclose(fp_source);
    puts("Done!");
    return 0;
}


