//
// Created by liam on 9/6/21.
//
#include "../myhead/myself.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NAMELEN 11
#define TEAM 19
#define PLAYINFO "team_info"

typedef struct {
    unsigned short player_num;
    char fname[NAMELEN];
    char lname[NAMELEN];
    unsigned short on_court;
    unsigned short hit;
    unsigned short walk;
    unsigned short RBI;
    float adl;
} PLAYER;

PLAYER team[TEAM];

bool IsNotRecorded(PLAYER *t, unsigned short n);
void ShowTeam(const PLAYER *t);
void CalcADL(PLAYER *t);
int main(void) {
    const int LINE_LEN = 256;
    FILE *fp;
    char line[LINE_LEN];
    PLAYER temp = {.adl = 0.0f};

    if ((fp = fopen(PLAYINFO, "r")) == NULL) {
        fprintf(stderr, "Can't open file %s.\n", PLAYINFO);
        exit(EXIT_FAILURE);
    }
    puts("Reading...");
    while ((StrGet(line, LINE_LEN, fp)) != NULL) {
        sscanf(line, "%hu %s %s %hu %hu %hu %hu",
               &temp.player_num,
               temp.fname,
               temp.lname,
               &temp.on_court,
               &temp.hit,
               &temp.walk,
               &temp.RBI);
        if (IsNotRecorded(team, temp.player_num)) {
            team[temp.player_num] = temp;
        } else {
            team[temp.player_num].on_court += temp.on_court;
            team[temp.player_num].hit += temp.hit;
            team[temp.player_num].walk += temp.walk;
            team[temp.player_num].RBI += temp.RBI;
        }
    }
    puts("Done!");
    CalcADL(team);
    ShowTeam(team);
    puts("That's all!");
    puts("Bye!");

    return 0;
}
bool IsNotRecorded(PLAYER *t, unsigned short n) {
    for (int i = 0; i < TEAM; ++i) {
        if (t[i].player_num == n)
            return false;
    }
    return true;
}
void ShowTeam(const PLAYER *t) {
    puts("*********************************************************");
    for (int i = 0; i < TEAM; ++i) {
        if (t[i].player_num != 0) {
            printf("number first_name last_name  on_court hit walk RBI adl\n");
            printf("%-6hu %-10s %-10s %-8hu %-3hu %-4hu %-3hu %.2f\n",
                   t[i].player_num,
                   t[i].fname,
                   t[i].lname,
                   t[i].on_court,
                   t[i].hit,
                   t[i].walk,
                   t[i].RBI,
                   t[i].adl);
        }
    }
    puts("*********************************************************");
}
void CalcADL(PLAYER *t) {
    for (int i = 0; i < TEAM; ++i) {
        if (t[i].player_num != 0) {
            t[i].adl = (float) t[i].hit / (float) t[i].on_court;
        }
    }
}
