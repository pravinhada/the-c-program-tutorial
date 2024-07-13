#include <stdio.h>

/* static variable 8 */
static int i;

int bump() {
    return i++;
}

void start(int a) {
    i = a;
}


int main() {
    printf("bump() returns %d\n", bump());
    printf("bump() returns %d\n", bump());
    printf("bump() returns %d\n", bump());
    start(42);
    printf("bump() returns %d\n", bump());
    printf("bump() returns %d\n", bump());
}

