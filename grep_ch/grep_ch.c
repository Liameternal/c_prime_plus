//
// Created by liam on 8/31/21.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 256

int main(int args, char **argv) {
    FILE *fp;
    char *line = (char *) malloc(MAXLEN * sizeof(char));
    char *find;
    if ((fp = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "Can't open %s.\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while (fgets(line, MAXLEN, fp) != NULL) {
        find = strchr(line, argv[1][0]);
        if (find)
            fputs(line, stdout);
    }
    free(line);
    fclose(fp);
    puts("Done!");

    return 0;
}

