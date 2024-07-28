#include <stdio.h>

/* print words at a time */

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            printf("\n");
            continue;
        }
        putchar(c);
    }
}