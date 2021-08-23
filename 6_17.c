//
// Created by liam on 8/19/21.
//
#include <stdio.h>
int main(void){
    double account=1e6;
    int year=0;
    while (account>=0){
        year++;
        account*=1.0+0.08;
        account-=1e5;
        printf("After %d years, account: %lf.\n",year,account);
    }
    return 0;
}
