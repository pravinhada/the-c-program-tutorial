#include <stdio.h>
#include <stdlib.h>
#include "cal.h"

#define MAXOP 100

/* reverse Polish calculator */
/* 12-34+* = -7.00 */

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s, MAXOP)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: zero division\n");
                }
                break;
            case '=':
                printf("\t%f\n", push(pop()));
                break;
            case 'c':
                clear();
                break;
            case TOOBIG:
                printf("%.20s ... is to long\n", s);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}