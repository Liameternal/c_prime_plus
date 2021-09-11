//
// Created by liam on 9/6/21.
//
#include <stdio.h>

#define NAME_LEN 11         // store at most 10 ch
#define SOCIAL_NUMBER_LEN 10    //store at most 9 ch
typedef struct {
    char fname[NAME_LEN];
    char mname[NAME_LEN];
    char lname[NAME_LEN];
} NAME;
typedef struct {
    char social_insurance_id[SOCIAL_NUMBER_LEN];
    NAME individual;
} PERSON_INFO;

void Show(PERSON_INFO *person) {
    printf("%s, %s ", person->individual.fname,
           person->individual.lname);
    if (person->individual.mname[0] != '\0') {
        printf("%c. -- %s\n", person->individual.mname[0],
               person->social_insurance_id);
        return;
    }
    printf("-- %s\n", person->social_insurance_id);

}

int main(void) {
    PERSON_INFO people[5] = {
            {"302039823", {"Dribble",  "Majfli",  "Flossie"}},
            {"302039824", {"lafeliag", "",        "Flossie"}},
            {"302039825", {"flaieg",   "Wajflie", "Flossie"}},
            {"302039826", {"faligj",   "",        "Flossie"}},
            {"302039827", {"flaig",    "Oajfna",  "Flossie"}}
    };
    for (int i = 0; i < 5; ++i) {
        Show(&people[i]);
    }

    return 0;
}

