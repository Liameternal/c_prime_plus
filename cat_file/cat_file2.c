//
// Created by liam on 8/31/21.
//
#include <stdio.h>

#define LINE 256

char *DIYFgets(char *, int n, FILE *fp);

int main(int args, char **argv) {
    FILE *fp1, *fp2;
    int line_num = 0;
    char line1[LINE];
    char line2[LINE];

    if ((fp1 = fopen(argv[1], "rb")) == NULL ||
        (fp2 = fopen(argv[2], "rb")) == NULL) {
        fprintf(stderr, "Can't open file.\n");
    }
    while (DIYFgets(line1, LINE, fp1) && fgets(line2, LINE, fp2)) {
        line_num++;
        printf("%d: ", line_num);
        fputs(line1, stdout);
        fputs(line2, stdout);
    }
    while (fgets(line1, LINE, fp1)) {
        line_num++;
        printf("%s %d: ", argv[1], line_num);
        fputs(line1, stdout);
    }
    while (fgets(line2, LINE, fp2)) {
        line_num++;
        printf("%s %d: ", argv[2], line_num);
        fputs(line2, stdout);
    }
    fclose(fp1);
    fclose(fp2);
    puts("Done!");

    return 0;
}

char *DIYFgets(char *str, int n, FILE *fp) {
    char *temp = str;
    temp = fgets(str, n, fp);
    if (temp) {
        while (*temp++ != '\n')
            continue;
        *--temp = ' ';
    } else
        return NULL;
    return temp;
}
