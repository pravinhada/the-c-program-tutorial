#include <stdio.h>

/*
Playing with structures
2023/02/11
Day of year 42
2023/09/15
Day of year 258
2024/09/15
Day of year 259
 */
struct simpledate {
    int day;
    int month;
    int year;
};

/* day_tab[0] is leap year */
static int day_tab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* set day of year from month, day */
int day_of_year(const struct simpledate *pd) {
    int day = pd->day;
    const int leap = pd->year % 4 == 0 && pd->year % 100 != 0 || pd->year % 400 == 0;
    for (int i = 1; i < pd->month; i++)
        day += day_tab[leap][i];
    return day;
}

/* print date from year, month, day */
void dump_date(const struct simpledate *pd) {
    /* The date should be in the following format - note that */
    /* The month and day are always two digits with leading zeros */
    //printf("2023/03/07\n");
    printf("%d/%02d/%d\n", pd->year, pd->month, pd->day);
}

int main() {
    printf("Playing with structures\n");
    struct simpledate sd;

    sd.year = 2023;
    sd.month = 2;
    sd.day = 11;
    dump_date(&sd);
    printf("Day of year %d\n", day_of_year(&sd));

    sd.year = 2023;
    sd.month = 9;
    sd.day = 15;
    dump_date(&sd);
    printf("Day of year %d\n", day_of_year(&sd));

    sd.year = 2024;
    sd.month = 9;
    sd.day = 15;
    dump_date(&sd);
    printf("Day of year %d\n", day_of_year(&sd));
}