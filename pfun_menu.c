//
// Created by liam on 9/7/21.
//
#include <stdbool.h>
#include <stdio.h>

typedef void (*V_PF_V)(void);

void ShowA(void);
void ShowB(void);
void ShowC(void);
void ShowD(void);
char menu(void);
int main(void) {
    V_PF_V pfun[4] = {ShowA, ShowB, ShowC, ShowD};
    bool quit = false;
    while (!quit) {
        switch (menu()) {
            case 'a':
                pfun[0]();
                break;
            case 'b':
                pfun[1]();
                break;
            case 'c':
                pfun[2]();
                break;
            case 'd':
                pfun[3]();
                break;
            case 'q':
                quit = true;
                break;
            default:
                printf("Invalid\n");
                printf("Enter a character before function.\n");
        }
    }
    return 0;
}
void ShowA(void) {
    puts("A");
}
void ShowB(void) {
    puts("B");
}
void ShowC(void) {
    puts("C");
}
void ShowD(void) {
    puts("D");
}
char menu(void) {
    char ans;
    printf("Enter a character before function: \n");
    printf("a).Puts A          b).Puts B\n");
    printf("c).Puts C          D).Puts D\n");
    printf("f).quit\n");
    scanf(" %c", &ans);
    while (getchar() != '\n')
        continue;
    return ans;
}