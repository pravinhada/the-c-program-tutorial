#include <stdio.h>
#include <string.h>

/* reverse the string */

char *copy(char s1[], char s2[]);

void reverse(char t[]);

int main() {
    char t[1000];
    copy("Hello world", t);
    printf("%s\n", t);
    reverse(t);
    printf("%s\n", t);
    reverse(copy("XY", t));
    printf("%s\n", t);
    reverse(copy("Even", t));
    printf("%s\n", t);
    reverse(copy("Odd", t));
    printf("%s\n", t);
    reverse(copy("civic", t));
    printf("%s\n", t);
}

/* copy s1 to s2; assume s2 big enough */
char *copy(char s1[], char s2[]) {
    int i;
    for (i = 0; (s2[i] = s1[i]); i++);
    return s2;
}

void reverse(char t[]) {
    int len = strlen(t);
    char *pHead = t;  // points to the first element or array
    char *pTail = t + (len - 1); // points to last element of array

    while (*pHead) {
        if (pHead > pTail) {
            break;
        }
        char temp = *pHead; //swap the first with last and so on.
        *pHead = *pTail;
        *pTail = temp;
        pHead++;
        pTail--;
    }
}