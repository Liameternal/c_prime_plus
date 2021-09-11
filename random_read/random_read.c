//
// Created by liam on 9/1/21.
//
#include <stdio.h>
#include <stdlib.h>

#define FILELEN 81

int main(void) {
    char filename[FILELEN];
    FILE *fp;
    int ch;
    long pos;
    long count;

    printf("Which file do you want to access: ");
    scanf("%80s", filename);
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Can't open %s.\n", filename);
        exit(EXIT_FAILURE);
    }
    fseek(fp, 0L, SEEK_END);
    count = ftell(fp);

    printf("Enter a number between 1 and %ld.\n", count);
    while (scanf("%ld", &pos) && pos > 0 && pos < count) {
        fseek(fp, pos, SEEK_SET);
        while ((ch = fgetc(fp)) != '\n') {
            fputc(ch, stdout);
        }
        putchar('\n');
        printf("Enter a number between 1 and %ld.(-1 to quit)\n", count);
    }
    puts("Done!");
    fclose(fp);
    return 0;
}

