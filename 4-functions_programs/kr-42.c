#include <stdio.h>

/** extern variable */
extern int i;

int i = 0;

int bump() {
    return i++;
}

int main() {
    int bump();
    printf("bump() returns %d\n", bump());
    printf("bump() returns %d\n", bump());
    printf("bump() returns %d\n", bump());
    printf("bump() returns %d\n", bump());
    printf("bump() returns %d\n", bump());
}