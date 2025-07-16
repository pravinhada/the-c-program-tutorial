#include <stdio.h>

int main() {
    int usf;
    printf("Enter US Floor\n");
    scanf("%d\n", &usf);
    const int euf = usf - 1;
    printf("EU Floor %d\n", euf);
    return 0;
}