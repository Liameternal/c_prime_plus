#include <stdio.h>
#include <stdlib.h>

#define LINE 20
#define COLUMN 30
#define SOURCEFILE "image.data"
#define AIMFILE "pic"

int main(void) {
    FILE *fp_source, *fp_aim;
    int num[LINE][COLUMN];
    char pic[LINE][COLUMN + 1];
    const char color[10] = {' ', '.', '\'', ':', '-', '*', '=', '@', '%', '#'};

    if ((fp_source = fopen(SOURCEFILE, "r")) == NULL) {
        fprintf(stderr, "Can't open %s.\n", SOURCEFILE);
        exit(EXIT_FAILURE);
    }
    if ((fp_aim = fopen(AIMFILE, "w")) == NULL) {
        fprintf(stderr, "Can't open %s.\n", AIMFILE);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < LINE; ++i) {
        for (int j = 0; j < COLUMN; ++j) {
            num[i][j] = getc(fp_source) - '0';
            getc(fp_source);
        }
    }
    for (int i = 0; i < LINE; ++i) {
        for (int j = 0; j < COLUMN; ++j) {
            pic[i][j] = color[num[i][j]];
        }
        pic[i][COLUMN] = '\0';
    }
    for (int i = 0; i < LINE; ++i) {
        printf("%s\n", pic[i]);
        fputs(pic[i], fp_aim);
        fputs("\n", fp_aim);
    }
    fclose(fp_aim);
    fclose(fp_source);
    puts("Done!");
    return 0;
}

