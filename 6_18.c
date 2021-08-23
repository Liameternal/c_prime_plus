//
// Created by liam on 8/19/21.
//
#include <stdio.h>
#include <iso646.h>
int main(void){
    int dunber=150;
    int week=0;
    int friends=5;
    while (friends<dunber){
        week++;
        friends-=1;
        friends*=2;
        printf("After %d weeks , I got %d friends.\n",week,friends);
    }
    return 0;
}
