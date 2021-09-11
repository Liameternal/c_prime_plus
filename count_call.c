//
// Created by liam on 8/29/21.
//
#include <stdio.h>

void CallMe(void){
    static int count=0;
    count++;
    printf("Being called %d times.\n",count);
}
int main(void){
    int n=5;
    while (n-->0)
        CallMe();
    return 0;
}

