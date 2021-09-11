//
// Created by liam on 8/30/21.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *GetWord(void);

int main(void) {
    int num;

    printf("How many words do you wish to enter? ");
    scanf("%d", &num);

    char **words = (char *) malloc(num * sizeof(char));

    printf("Enter %d words now:", num);
    for (int i = 0; i < num; ++i) {
        words[i] = GetWord();
    }
    puts("Here are your words:");
    for (int i = 0; i < num; ++i) {
        puts(words[i]);
        free(words[i]);
    }
    free(words);
    return 0;
}

char *GetWord(void) {
    char *temp, *word;
    int len;

    temp = (char *) malloc(81 * sizeof(char));
    if (!temp) {
        printf("Failed to allocate memory.\n");
        exit(-1);
    }
    scanf("%s", temp);
    len = strlen(temp);
    word = (char *) malloc((len + 1) * sizeof(char));
    if (!word) {
        printf("Failed to allocate memory.\n");
        exit(-1);
    }
    strncpy(word, temp, len);
    word[len] = '\0';
    free(temp);

    return word;
}
