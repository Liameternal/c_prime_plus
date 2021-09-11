//
// Created by liam on 8/29/21.
//
#include <stdio.h>
#include <stdlib.h>

void Frequency(int fre[], int num[], int n);

int main(void) {
    int num[1000];
    int frequency[10];
    unsigned seed;
    int count = 0;
    printf("Enter a seed: ");
    scanf("%u", &seed);
    while (count++ < 10) {
        srand(seed);
        for (int i = 0; i < 1000; ++i) {
            num[i] = rand() % 10 + 1;
        }
        Frequency(frequency, num, 1000);
        for (int i = 0; i < 10; ++i) {
            printf("num %d: %d time\n", i + 1, frequency[i]);
        }
        printf("Enter another seed: ");
        scanf("%u", &seed);
    }
    return 0;
}

void Frequency(int fre[], int num[], int n) {
    for (int i = 0; i < 10; ++i) {
        fre[i] = 0;
    }
    for (int i = 0; i < 1000; ++i) {
        switch (num[i]) {
            case 1:
                fre[0]++;
                break;
            case 2:
                fre[1]++;
                break;
            case 3:
                fre[2]++;
                break;
            case 4:
                fre[3]++;
                break;
            case 5:
                fre[4]++;
                break;
            case 6:
                fre[5]++;
                break;
            case 7:
                fre[6]++;
                break;
            case 8:
                fre[7]++;
                break;
            case 9:
                fre[8]++;
                break;
            case 10:
                fre[9]++;
                break;
        }
    }
}
