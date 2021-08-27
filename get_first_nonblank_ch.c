//
// Created by liam on 8/24/21.
//
#include <stdio.h>

char GetFirstNonBlankCH(void);
int main(void){
    char ch;
    ch=GetFirstNonBlankCH();
    printf("The first non blank character you entered is %c.\n",ch);
    return 0;
}

char GetFirstNonBlankCH(void){
    char ch;
    scanf(" %c",&ch);
    while (getchar()!='\n')
        continue;
    return ch;
}
