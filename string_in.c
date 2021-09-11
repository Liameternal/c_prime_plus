//
// Created by liam on 8/29/21.
//
#include <stdio.h>

char *StrIn(const char*des,const char *sou);
int main(void){
    char *str1="hsafjliealaatfjlisalkjliw";
    char *str2="at";
    char *first_place= StrIn(str1,str2);
    if(first_place)
        printf("%s\n",first_place);
    else
        puts("None!");
    return 0;
}

char *StrIn(const char*des,const char *sou){
    char *first;
    char *l_des,*l_sou;
    l_des=(char *)des;
    l_sou=(char *)sou;
    while (*des){
        first=(char *)l_des;
        while (*l_des==*l_sou){
            if(!*++sou)
                return first;
            l_des++;
            l_sou++;
        }
        des++;
        l_des=(char *)des;
        l_sou=(char *)sou;
    }
    return NULL;
}
