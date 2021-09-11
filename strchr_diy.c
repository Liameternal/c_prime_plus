//
// Created by liam on 8/28/21.
//
#include <stdio.h>

char *StrChr(const char* str,int c);

int main(void){
    char str[81]="I am a string.";
    printf("which character you want to search?(# to exit)\n");

    int ch;
    char *find;
    while ((ch=getchar())&&ch!='#'){
        while (getchar()!='\n')
            continue;
        find= StrChr(str,ch);
        if(find){
            printf("I find the character: %s\n",find);
        }else{
            puts("Sorry!");
        }
    }
    puts("Done!");
    return 0;
}

char *StrChr(const char* str,int c){
    while (*str){
        if(*str==c)
            return (char *)str;
        str++;
    }
    return NULL;
}
