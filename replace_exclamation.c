//
// Created by liam on 8/23/21.
//
#include <stdio.h>
int main(void){
    char ch;
    while(scanf("%c",&ch)&&ch!='#'){
        if(ch=='.') {
            putchar('!');
            continue;
        } else if(ch == '!') {
            printf("!!");
            continue;
        }
        putchar(ch);
    }
    return  0;
}

