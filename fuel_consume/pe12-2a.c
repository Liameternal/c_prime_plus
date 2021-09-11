//
// Created by liam on 8/29/21.
//
#include <stdio.h>
#include "pe12-2a.h"

static int mode = 0;
static double distance = 0.0;
static double fuel = 0.0;

void SetMode(int m) {
    if (m == 0 || m == 1)
        mode = m;
    else {
        if (mode == 1)
            puts("Invalid mode specified. Mode 1(US) used.");
        else
            puts("Invalid mode specified. Mode 0(metric) used.");
    }
}

void GetInfo(void) {
    if (mode == 0) {
        printf("Enter distance traveled in kilometers: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in liters: ");
        scanf("%lf", &fuel);
    } else {
        printf("Enter distance traveled in miles: ");
        scanf("%lf", &distance);
        printf("Enter fuel consumed in gallons: ");
        scanf("%lf", &fuel);
    }
}

void ShowInfo(void) {
    if (mode == 0) {
        printf("Fuel consumption is %.2f liters per 100 km.\n",
               (fuel / distance) * 100);
    } else {
        printf("Fuel consumption is %.2f miles per 100 gallon.\n",
               distance / fuel);
    }
}

