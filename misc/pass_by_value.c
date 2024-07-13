#include <stdio.h>
#include <string.h>

/* using array */
void modify(char a[]) {
    int len = strlen(a);
    for (int i = 0; i < len - 1; i++) {
        if (a[i] == 'o') {
            a[i] = 'e';
        }
    }
}

/* using pointer */
void modifyAgain(char *s) {
    while (*s) {    // if we do while(s) {} then it will be segfault since address s can go on an on
        if (*s == 'e') {
            *s = 'o';
        }
        s++;
    }
}

int main() {
    char s[] = "Hello, World!";

    printf("before calling modify(): %s\n", s);
    modify(s);
    printf("after calling modify(): %s\n", s);
    modifyAgain(s);
    printf("after calling modifyAgain(): %s\n", s);
    return 0;
}