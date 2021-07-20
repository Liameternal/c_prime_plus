#include <stdio.h>

double Cube(double cube);

double main(void){
    double cube;
    scanf("%lf",&cube);
    printf("The cube of %.3f.\n",cube);

    return 0;
}

double Cube(double cube){
    return cube*cube*cube;
}
