#include <stdio.h>

extern int a; // this refers to the variable defined in extern.c

void print() {
    a = 20;
    printf("from print() %d\n", a);
}