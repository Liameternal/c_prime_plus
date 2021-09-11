//
// Created by liam on 8/31/21.
//
#include <stdio.h>
#include <stdlib.h>

int main(int args, char **argv) {
    FILE *fp;
    const char *file_name = "data";
    double num;
    int count = 0;
    double sum = 0;
    if (args < 2) {
        fp = stdin;
    } else if (args == 2) {
        if ((fp = fopen(file_name, "r")) == NULL) {
            fprintf(stderr, "Can't open file %s.\n", file_name);
            exit(EXIT_FAILURE);
        }
    } else {
        printf("\"Usage: %s [filename]\"\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    while (fscanf(fp, "%lf", &num) != EOF) {
        count++;
        sum += num;
    }
    if (count)
        printf("The average is %.2f\n", sum / count);
    else
        puts("Find no value.Done!");
    fclose(fp);
    return 0;
}
