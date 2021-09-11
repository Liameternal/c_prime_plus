//
// Created by liam on 9/6/21.
//
#include "myhead/myself.h"
#include <stdio.h>

#define NAME_LEN 11
#define GRADE_NUM 3
#define CSIZE 4

typedef struct {
    char fname[NAME_LEN];
    char lname[NAME_LEN];
} NAME;

typedef struct {
    NAME name;
    double grade[GRADE_NUM];
    double average;
} STUDENT;

STUDENT GetInfo(STUDENT stu);
void CalcStuAverage(STUDENT *stu);
void CalcClassAverage(STUDENT *stu);
void ShowStu(const STUDENT *stu);
int main(void) {
    STUDENT class_1[CSIZE] = {
            {.name = {.fname = "liam"}},
            {.name = {.fname = "wenxi"}},
            {.name = {.fname = "shuan"}},
            {.name = {.fname = "yong"}}};
    for (int i = 0; i < CSIZE; ++i) {
        class_1[i] = GetInfo(class_1[i]);
        CalcStuAverage(&class_1[i]);
    }
    CalcClassAverage(class_1);
    ShowStu(class_1);

    return 0;
}
STUDENT GetInfo(STUDENT stu) {
    printf("Enter you last name: ");
    StrGet(stu.name.lname, NAME_LEN);
    for (int i = 0; i < GRADE_NUM; ++i) {
        printf("Enter your test grades %d# : ", i + 1);
        scanf("%lf", &stu.grade[i]);
    }
    while (getchar() != '\n')
        continue;

    return stu;
}
void CalcStuAverage(STUDENT *stu) {
    double total = 0;
    for (int i = 0; i < GRADE_NUM; ++i) {
        total += stu->grade[i];
    }
    stu->average = total / GRADE_NUM;
}
void CalcClassAverage(STUDENT *stu) {
    double total = 0;
    double ave;
    for (int i = 0; i < CSIZE; ++i) {
        total += stu[i].average;
    }
    ave = total / CSIZE;
    printf("The average grade of class is %.2f\n", ave);
    puts("******************************************");
}
void ShowStu(const STUDENT *stu) {
    for (int i = 0; i < CSIZE; ++i) {
        printf("name: %s, %s\n", stu[i].name.fname, stu[i].name.lname);
        for (int j = 0; j < GRADE_NUM; ++j) {
            printf("grade %d# %.2f\n", j + 1, stu[i].grade[j]);
        }
        printf("average grade: %.2f\n", stu[i].average);
        puts("******************************************");
    }
}
