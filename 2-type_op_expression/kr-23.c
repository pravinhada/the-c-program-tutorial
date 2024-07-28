#include <stdio.h>

/* change ascii character to lowercase */

int main() {
    int lower(char c);
    printf("Lower M is %c\n", lower('M'));
    printf("Lower x is %c\n", lower('x'));
    printf("Lower @ is %c\n", lower('@'));
    printf("Lower K is %c\n", lower('K'));
}


int lower(char c) {
    return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}