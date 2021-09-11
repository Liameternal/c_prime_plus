//
// Created by liam on 8/31/21.
//
#include <stdio.h>

int main(int args, char **argv) {
    FILE *fs, *fa; //fs pointers to source file, fa pointers to aim file
    char ch;
    if ((fs = fopen(argv[1], "rb")) == NULL ||
        (fa = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Can't open file.\n");
    }
    while ((fread(&ch, sizeof(char), 1, fs)) > 0) {
        fwrite(&ch, sizeof(char), 1, fa);
    }
    fclose(fs);
    fclose(fa);
    puts("Down!");
    return 0;
}

