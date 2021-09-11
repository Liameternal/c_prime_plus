//
// Created by liam on 8/29/21.
//
#include <stdio.h>

int main(int args,char **argv){
    for (int i = args-1; i > 0; --i) {
        puts(argv[i]);
    }
    return 0;
}

