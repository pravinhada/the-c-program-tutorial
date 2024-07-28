#include <stdio.h>
#include "cal.h"

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

double push(double a) {
    if (sp < MAXVAL) {
        return (val[sp++] = a);
    } else {
        printf("error: stack is full, can't push %g\n", a);
        clear();
        return (0);
    }
}

double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void clear() {
    sp = 0;
}
