#include <stdio.h>

int main(void){
    int digit;
    printf("Enter a number in decimal:");
    while(scanf("%d",&digit)==1){
       printf("the number you entered: \n"
               "Dex=%-10dOtc=%-10oHex=%-10x\n"
               "Dex=%#-10dOtc=%#-10oHex=%#-10x\n"
               ,digit,digit,digit,digit,digit,digit); 
    }
}
