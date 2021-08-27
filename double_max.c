//
// Created by liam on 8/26/21.
//
#include <stdio.h>
double Max(const double *arr,int len,int *index);
int main(void){
    const double arr[10]={2.3,4.2,5.1,2.8,5.5,2.3,2};
    int index;
    double max=Max(arr,10,&index);
    for (int i = 0; i < 10; ++i) {
        printf("arr[%d]:%.2f ",i,arr[i]);
    }
    putchar('\n');
    printf("Max value:%.2f  index:%d",max,index);
    return 0;
}

double Max(const double *arr,int len,int *index){
    double max=arr[0];
    *index=0;
    for (int i = 1; i < len; ++i) {
        if(max<arr[i]){
            max=arr[i];
            *index=i;
        }
    }
    return max;
}
