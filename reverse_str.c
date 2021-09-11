//
// Created by liam on 8/29/21.
//
#include <stdio.h>

char *ReverseStr(char *str);
int main(void){
    char str[]="abcdefgh";
    puts(str);
    ReverseStr(str);
    puts(str);
    return 0;
}

char *ReverseStr(char *str){
    int len=0;
    char *temp=str;
    char t;
    while (*temp++)
        len++;
    for (int i = 0; i < (len-1)/2; ++i) {
        t=str[i];
        str[i]=str[len-1-i];
        str[len-1-i]=t;
    }
    return str;
}
