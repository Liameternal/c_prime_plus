//
// Created by liam on 9/7/21.
//
#include "../myhead/myself.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SEATS 12
#define NAME_LEN 11
typedef int STATUS;

typedef struct {
    unsigned short seat_num;
    bool is_not_ordered;
    char fname[NAME_LEN];
    char lname[NAME_LEN];
} SEAT;

char Menu(char *flight);

void ShowEmptyNumbers(const SEAT *s, int len);

void ShowEmptyList(const SEAT *s, int len);

void ShowInfoSortedByName(const SEAT *s, int len,
                          int (*pf_compare)(char *, char *));

void ShowInfo(const SEAT *s, int len);

STATUS OrderSeat(SEAT *s, int len);

STATUS DeleteOrder(SEAT *s, int len);

int FirstNameCompare(char *str1, char *str2);

int main(void) {
    SEAT seat[SEATS] = {
            {1,  true},
            {2,  true},
            {3,  true},
            {4,  true},
            {5,  true},
            {6,  true},
            {7,  true},
            {8,  true},
            {9,  true},
            {10, true},
            {11, true},
            {12, true}};
    bool quit = false;

    while (!quit) {
        switch (Menu("102")) {
            case 'a':
                ShowEmptyNumbers(seat, SEATS);
                printf("Continue with any key...\n");
                getchar();
                break;
            case 'b':
                ShowEmptyList(seat, SEATS);
                printf("Continue with any key...\n");
                getchar();
                break;
            case 'c':
                ShowInfoSortedByName(seat, SEATS, FirstNameCompare);
                printf("Continue with any key...\n");
                getchar();
                break;
            case 'd':
                OrderSeat(seat, SEATS);
                printf("Continue with any key...\n");
                getchar();
                break;
            case 'e':
                DeleteOrder(seat, SEATS);
                printf("Continue with any key...\n");
                getchar();
                break;
            case 'f':
                quit = true;
                break;
            default:
                printf("Invalid\n");
                printf("Continue with any key...\n");
                getchar();
        }
    }
    puts("Bye!");

    return 0;
}

char Menu(char *flight) {
    char ans;
    unsigned short len = 80;
    char welcome[] = "Flight *** is standing by....";
    system("clear");
    for (int i = 0; i < len; ++i) {
        putchar('*');
        if (i == len - 1)
            putchar('\n');
    }
    for (int i = 0; i < (len - strlen(welcome)) / 2; ++i) {
        putchar(' ');
    }
    printf("Flight %3s is standing by....\n",flight);
    for (int i = 0; i < len; ++i) {
        putchar('*');
        if (i == len - 1)
            putchar('\n');
    }
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a assignment");
    puts("e) delete a seat assignment");
    puts("f) Quit");
    scanf(" %c", &ans);
    while (getchar() != '\n')
        continue;
    return ans;
}

void ShowEmptyNumbers(const SEAT *s, int len) {
    int empty = 0;
    for (int i = 0; i < len; ++i) {
        if (s->is_not_ordered)
            empty++;
        s++;
    }
    printf("There still has %d seats.\n", empty);
}

void ShowEmptyList(const SEAT *s, int len) {
    printf("Empty seats number: ");
    int empty = 0;
    for (int i = 0; i < len; ++i) {
        if (s->is_not_ordered) {
            if (i == len - 1) {
                printf("%d", i + 1);
                continue;
            }
            printf("%d, ", i + 1);
            empty++;
        }
        s++;
    }
    if (!empty)
        printf("Full!\n");
    putchar('\n');
}

void ShowInfoSortedByName(const SEAT *s, int len,
                          int (*pf_compare)(char *, char *)) {
    SEAT temp[len];
    SEAT swap;
    for (int i = 0; i < len; ++i) {
        temp[i] = s[i];
    }
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 1; j < len; ++j) {
            if (strcmp(temp[i].fname, "") != 0 &&
                strcmp(temp[j].fname, "") != 0)
                if (pf_compare(temp[i].fname, temp[j].fname) > 0) {
                    swap = temp[i];
                    temp[i] = temp[j];
                    temp[j] = swap;
                }
        }
    }
    ShowInfo(temp, len);
}

void ShowInfo(const SEAT *s, int len) {
    for (int i = 0; i < len; ++i) {
        if (!s[i].is_not_ordered) {
            printf("seat: %hu\n", s[i].seat_num);
            printf("first name: %s\n", s[i].fname);
            printf("last name: %s\n", s[i].lname);
        }
    }
}

STATUS OrderSeat(SEAT *s, int len) {
    unsigned short seat_num;
    printf("Which seat number do you want to order? ");
    while (scanf("%hu", &seat_num) != 1 || seat_num < 1 || seat_num > 12) {
        while (getchar() != '\n')
            continue;
        printf("Enter a seat number (1-12):");
    }
    if (!s[seat_num - 1].is_not_ordered) {
        printf("Sorry, this seat is preserved.\n");
        sleep(5);
        return 0;
    }
    while (getchar() != '\n')
        continue;
    printf("What's your first name? ");
    while (!StrGet(s[seat_num - 1].fname, NAME_LEN, stdin)) {
        printf("Enter a name: ");
    }
    printf("What's your last name? ");
    while (!StrGet(s[seat_num - 1].lname, NAME_LEN, stdin)) {
        printf("Enter a name: ");
    }
    s[seat_num - 1].is_not_ordered = false;
    return 1;
}

STATUS DeleteOrder(SEAT *s, int len) {
    unsigned short seat_num;
    printf("Ordered seat: ");
    for (int i = 0; i < len; ++i) {
        if (!s[i].is_not_ordered)
            printf("%hu, ", s[i].seat_num);
    }
    putchar('\n');
    printf("Which seat order do you want to delete? ");
    while (scanf("%hu", &seat_num) != 1 || seat_num < 1 || seat_num > 12) {
        while (getchar() != '\n')
            continue;
        printf("Enter a seat number (1-12):");
    }
    if (s[seat_num - 1].is_not_ordered) {
        printf("This seat is empty now.\n");
        sleep(5);
        return 0;
    }
    s[seat_num - 1].is_not_ordered = true;
    return 1;
}

int FirstNameCompare(char *str1, char *str2) {
    return strcmp(str1, str2);
}
