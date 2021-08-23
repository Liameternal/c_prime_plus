#include <stdio.h>

int main(void){
    printf("The sizeof short = %zd,\n"
            "The sizeof int = %zd,\n"
            "The sizeof long = %zd,\n"
            "The sizeof long long = %zd.\n", 
            sizeof(short)*8,sizeof(int)*8,sizeof(long)*8,sizeof(long long)*8);
    return 0;
}
