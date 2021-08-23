#include <stdio.h>
#define ADJUST 32

const float SCALE = 1.8;

float CelsiusToFahrenheit(float cel){
    return cel*SCALE+ADJUST;
}

int main(void){
    float celsius;
    float fahrenheit;
    printf("Enter celsius(°C):");
    while(scanf("%f",&celsius)!=EOF){
        fahrenheit = CelsiusToFahrenheit(celsius);
        printf("%.1f celsius is %.1f fahrenheit.\n",celsius,fahrenheit);
    }

    return 0;
}

