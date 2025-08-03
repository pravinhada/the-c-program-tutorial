#include "stdio.h"

// count the character in line
int main() {
    long nc = 0;
    while (getchar() != EOF) {
        ++nc;
    }
    printf("\n");
    printf("%ld\n", nc);
}