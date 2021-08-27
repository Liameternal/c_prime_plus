//
// Created by liam on 8/27/21.
//
#include <stdio.h>
#include <stdlib.h>

#define ROW 3
#define COLUMN 5

void Copy(int row, int column, double target[row][column],
          const double source[row][column]);

void ShowArray(int row, int column, const double arr[row][column]);

int main(void) {
    double arr[ROW][COLUMN] = {
            {1.1, 2.2, 3.3, 4.4, 5.5},
            {1.2, 2.3, 3.4, 4.5, 5.6},
            {1.3, 2.4, 3.5, 4.6, 5.7}
    };
    double (*tar)[COLUMN] = (double *) malloc(ROW * COLUMN * sizeof(double));
    Copy(ROW, COLUMN, tar, arr);
    printf("sources:\n");
    ShowArray(ROW, COLUMN, arr);
    printf("copy:\n");
    ShowArray(ROW, COLUMN, tar);
    return 0;
}


void Copy(int row, int column, double target[row][column],
          const double source[row][column]) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            target[i][j] = source[i][j];
        }
    }
}

void ShowArray(int row, int column, const double arr[row][column]) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            printf("%.2f ", arr[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}
