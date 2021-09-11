//
// Created by liam on 8/31/21.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41
#define LINE 256

int main(void) {
    FILE *fp;
    char words[MAX];
    int seq = 1;
    char line[LINE];

    if ((fp = fopen("wordy", "a+")) == NULL) {
        fprintf(stderr, "Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, LINE, fp)) {
        if (line[0] != '\n')
            seq++;
    }

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
//read a word
//    while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
//        fprintf(fp, "%d.%s\n", seq++, words);

//read a line
    while ((fgets(words, MAX, stdin)) != NULL) {
        fprintf(fp, "%d.", seq++);
        fputs(words, fp);
    }

    puts("File contents:");
    rewind(fp);
//print a word
//    while (fscanf(fp, "%s", words) == 1) {
//        puts(words);
//    }

//print a line
    while ((fgets(words, MAX, fp)) != NULL) {
        fputs(words, stdout);
    }

    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}