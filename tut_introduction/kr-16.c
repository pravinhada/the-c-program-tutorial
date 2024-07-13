#include <stdio.h>

/* count new lines in input */
int main() {
    int c, nl, bl;
    nl = bl = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++nl;
        }
        if (c == ' ') {
            ++bl;
        }
    }
    printf("%d %d\n", bl, nl);
}