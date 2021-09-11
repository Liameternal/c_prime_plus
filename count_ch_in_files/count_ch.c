//
// Created by liam on 8/31/21.
//
#include <stdio.h>
#include <stdlib.h>

int main(int args, char **argv) {
    FILE *fp;
    int count = 0;
    int ch;

    if (args == 1) {
        printf("\"Usage: %s [character] [filename]\"\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (args == 2) {
        fp = stdin;
        while ((ch = fgetc(fp)) != EOF) {
            if (ch == argv[1][0]) {
                count++;
            }
        }
        printf("%c appears %d times.\n",
               argv[1][0], count);
        count = 0;
        fclose(fp);
    } else {
        for (int i = 2; i < args; ++i) {
            if ((fp = fopen(argv[i], "rb")) == NULL) {
                fprintf(stderr, "Can't open %s.\n", argv[i]);
                continue;
            }
            while ((ch = fgetc(fp)) != EOF) {
                if (ch == argv[1][0]) {
                    count++;
                }
            }
            printf("%c appears %d times in file %s.\n",
                   argv[1][0], count, argv[i]);
            count = 0;
            fclose(fp);
        }
    }
    puts("Done!");

    return 0;
}
