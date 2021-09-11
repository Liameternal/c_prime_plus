/*
 * Flight tickets order system
 */
// Supply StrGet(char *,int n,FILE *)
#include "../myhead/myself.h"
// Supply macro bool
#include <stdbool.h>
#include <stdio.h>
// Supply exit(int)
#include <stdlib.h>
/* Supply strcmp(char *,char *)
 * strncpy(char *, char *,int)
*/
#include <string.h>
// Supply sleep(int)
#include <unistd.h>

// Seats per flight
#define SEATS 12
// Flight number
#define FLIGHT_NUM 4
// Flight number len
#define FLIGHT_NUM_LEN 4
// Customer name no more than 10 characters
#define NAME_LEN 11
// Storage file
#define FLIGHT_INFO "flight"

typedef int STATUS;

// Template of each seat
typedef struct {
    unsigned short seat_num;
    bool is_not_ordered;
    char fname[NAME_LEN];
    char lname[NAME_LEN];
} SEAT;

// Template of each flight
typedef struct {
    char flight_num[FLIGHT_NUM];
    SEAT seat[SEATS];
} FLIGHT;

// flight number of each flight
char *flight_no[FLIGHT_NUM_LEN] = {"102", "311", "444", "519"};
/*
 * Initializing flight array to zero bytes
 */
FLIGHT flight[FLIGHT_NUM];

/*
 * Show customer guided line in center
 * Accept a string to be shown
*/
void Title(char *t);

/*
 * Level 1 menu, choose to which flight order
 * Return a char which is the flight you choose
*/
char MenuFlight(void);

/*
 * Level 2 menu, show a list of function
 * Accept a string representing flight which you want to take
 * Return a char which is the function you choose
*/
char Menu(char *flight);

/*
 * Call the function you choose in Menu()
 * Accept two parameters, first one is a string representing the flight you
 * take, the other one is the flight seat info
 */
void WhichFunc(char *flight, SEAT *s);

/*
 * Show the amount of empty seats
 * Accept two parameters, first one is flight seat info array, the other one
 * is seats amount
 */
void ShowEmptyNumbers(const SEAT *s, int len);

/*
 * Show the list of empty seats
 * Accept two parameters, first one is flight seat info array, the other one
 * is seats amount
 */
void ShowEmptyList(const SEAT *s, int len);

/*
 * Show seats info sorted by each customer first name or last name
 * Accept three parameters, first one is flight seat info array, the second one
 * is seats amount, the last one is a function pointer which points to the
 * compare function defined by user or C standard library function
 */
void ShowInfoSortedByName(const SEAT *s, int len,
                          int (*pf_compare)(char *, char *));


/*
 * Show seats info ordered by seat num
 * Accept two parameters, first one is flight seat info array, the other one
 * is seats amount
 */
static void ShowInfo(const SEAT *s, int len);

/*
 * Order ticket function
 * Accept two parameters, first one is flight seat info array, the other one
 * is seats amount
 * Return a positive value if order operation down successfully,otherwise
 * a negative value returned;
 */
STATUS OrderSeat(SEAT *s, int len);

/*
 * Delete the seat you ordered before
 * Accept two parameters, first one is flight seat info array, the other one
 * is seats amount
 * Return a positive value if delete operation down successfully,otherwise
 * a negative value returned;
 */
STATUS DeleteOrder(SEAT *s, int len);

/*
 * Customized function
 * Accept two string to be compared
 * return a positive number if a character is behind the other in ascii table
 * e.g.'B' compare to 'A' return -1,vice versa;
 */
int FirstNameCompare(char *str1, char *str2);

int main(void) {
    // Circle till quit is set to true
    bool quit = false;
    FILE *fp;

    // Initializing flight array, set seat order and is_not_ordered to true,
    // which represent the seat is empty
    for (int i = 0; i < FLIGHT_NUM; ++i) {
        strncpy(flight[i].flight_num, flight_no[i], FLIGHT_NUM_LEN);
        for (int j = 0; j < SEATS; ++j) {
            flight[i].seat[j].is_not_ordered = true;
        }
    }

    // Read file info
    if ((fp = fopen(FLIGHT_INFO, "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", FLIGHT_INFO);
        exit(EXIT_FAILURE);
    }
    // Create a buffer connected with file pointed by fp
    setvbuf(fp, NULL, _IOFBF, sizeof(FLIGHT));
    if (fread(flight, sizeof(FLIGHT), FLIGHT_NUM, fp) == FLIGHT_NUM) {
        puts("Read successfully.");
    } else {
        puts("Read failed.");
    }
    // C standard function, refresh screen
    system("clear");
    // Show currently ordering condition
    for (int i = 0; i < FLIGHT_NUM; ++i) {
        Title(flight[i].flight_num);
        ShowInfo(flight[i].seat, SEATS);
    }
    if (fclose(fp) != 0) {
        fprintf(stderr, "Error in closing %s.\n", FLIGHT_INFO);
    }
    // Make output still
    getchar();

    while (!quit) {
        switch (MenuFlight()) {
            case 'a':
                WhichFunc(flight[0].flight_num, flight[0].seat);
                break;
            case 'b':
                WhichFunc(flight[1].flight_num, flight[1].seat);
                break;
            case 'c':
                WhichFunc(flight[2].flight_num, flight[2].seat);
                break;
            case 'd':
                WhichFunc(flight[3].flight_num, flight[3].seat);
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
    // Write info to file
    if ((fp = fopen(FLIGHT_INFO, "w")) == NULL) {
        fprintf(stderr, "Can't open %s\n", FLIGHT_INFO);
        exit(EXIT_FAILURE);
    }
    // Create a buffer connected with file pointed by fp
    setvbuf(fp, NULL, _IOFBF, sizeof(FLIGHT));
    if (fwrite(flight, sizeof(FLIGHT), FLIGHT_NUM, fp) == FLIGHT_NUM) {
        puts("Write successfully.");
    } else {

        puts("Write failed.");
    }
    if (fclose(fp) != 0) {
        fprintf(stderr, "Error in closing %s.\n", FLIGHT_INFO);
    }
    puts("Bye!");

    return 0;
}

void Title(char *t) {
    unsigned short len = 80;
    for (int i = 0; i < len; ++i) {
        putchar('*');
        if (i == len - 1)
            putchar('\n');
    }
    for (int i = 0; i < (len - strlen(t)) / 2; ++i) {
        putchar(' ');
    }
    puts(t);
    for (int i = 0; i < len; ++i) {
        putchar('*');
        if (i == len - 1)
            putchar('\n');
    }
}

char MenuFlight(void) {
    char ans;
    char welcome[] = "Welcoming";

    system("clear");
    Title(welcome);
    puts("To choose a flight, enter its letter label:");
    puts("a) 102");
    puts("b) 311");
    puts("c) 444");
    puts("d) 519");
    puts("f) Quit");
    scanf(" %c", &ans);
    while (getchar() != '\n')
        continue;

    return ans;
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
    printf("Flight %3s is standing by....\n", flight);
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

void WhichFunc(char *flight, SEAT *s) {
    bool quit = false;

    while (!quit) {
        switch (Menu(flight)) {
            case 'a':
                ShowEmptyNumbers(s, SEATS);
                printf("Continue with any key...\n");
                getchar();
                break;
            case 'b':
                ShowEmptyList(s, SEATS);
                printf("Continue with any key...\n");
                getchar();
                break;
            case 'c':
                ShowInfoSortedByName(s, SEATS, FirstNameCompare);
                printf("Continue with any key...\n");
                getchar();
                break;
            case 'd':
                OrderSeat(s, SEATS);
                printf("Continue with any key...\n");
                getchar();
                break;
            case 'e':
                DeleteOrder(s, SEATS);
                printf("Continue with any key...\n");
                getchar();
                break;
            case 'f':
                puts("Ordered completely!");
                printf("Continue with any key...\n");
                getchar();
                return;
            default:
                printf("Invalid\n");
                printf("Continue with any key...\n");
                getchar();
        }
    }
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
    int empty = 0;

    printf("Empty seats number: ");
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
        for (int j = i + 1; j < len; ++j) {
            if (strcmp(temp[i].fname, "") != 0 &&
                strcmp(temp[j].fname, "") != 0)
                // Ascending
                if (pf_compare(temp[i].fname, temp[j].fname) > 0) {
                    swap = temp[i];
                    temp[i] = temp[j];
                    temp[j] = swap;
                }
        }
    }
    ShowInfo(temp, len);
}

static void ShowInfo(const SEAT *s, int len) {
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

