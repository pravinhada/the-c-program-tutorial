#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../4-functions_programs/calculator/cal.h"
#include "../4-functions_programs/calculator/getch.c"

#define MAXWORD 100
#define NKEYS 13

struct key {
    char *word;
    int count;
} keytab[] = {
        "auto", 0,
        "break", 0,
        "case", 0,
        "char", 0,
        "const", 0,
        "continue", 0,
        "default", 0,
        "unsigned", 0,
        "void", 0,
        "volatile", 0,
        "while", 0,
        "else", 0,
        "enum", 0};

int getword(char *, int);

struct key *binsearch(const char *, struct key *, int);

int main() {
    struct key *p;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((p = binsearch(word, keytab, NKEYS)))
                p->count++;

    for (p = keytab; p < keytab + NKEYS; p++)
        if (p->count > 0)
            printf("%4d %s\n", p->count, p->word);

    return 0;
}

int getword(char *word, int n) {
    int c;
    char *w = word;

    while (isspace(c = getch()));

    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for (; --n > 0; w++) {
        if (!isalpha(*w = getch())) {
            ungetch(*w);
            break;
        }
    }

    *w = '\0';
    return word[0];
}

struct key *binsearch(const char *word, struct key tab[], const int n) {
    int cond;
    struct key *low = &tab[0];
    const struct key *high = &tab[n - 1];

    while (low < high) {
        struct key *mid = low + (high - low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return NULL;
}
