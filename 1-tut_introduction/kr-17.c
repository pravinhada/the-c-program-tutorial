#include <stdio.h>

/* Write a program to copy its input to its output,
 * replacing each string of one or more blanks by a single blank */

int main() {
    int c;
    int bl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++bl;
            continue;
        }
        if (bl >= 1) {
            putchar(' ');
            bl = 0;
            putchar(c);
            continue;
        }
        if (bl < 1) {
            putchar(c);
        }
    }
}