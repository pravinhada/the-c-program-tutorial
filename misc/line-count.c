#include "stdio.h"

int main() {
    int c, nl;
    nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++nl;
        }
    }
    printf("\n");
    printf("%d\n", nl);
    return 0;
}