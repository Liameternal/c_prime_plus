//
// Created by liam on 8/23/21.
//
#include <stdio.h>

int main(void) {
    char ch;
    long space = 0;
    long line_feed = 0;
    long other = 0;
    printf("enter a string (end with # exit):");
    while (scanf("%c", &ch) && ch != '#') {
        if (ch == ' ')
            space++;
        else if (ch == '\n')
            line_feed++;
        else
            other++;
    }
    printf("%s = %ld, %s = %ld, %s = %ld\n",
           space==1?"space":"spaces",space,
           line_feed==1?"line_feed":"line_feeds",line_feed,
           other==1?"other":"others",other);
    return 0;
}

