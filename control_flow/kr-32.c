#include <stdio.h>
#include <string.h>

/*
    42 in base-2 is 101010
    42 in base-16 is 2a
    16 in base-2 is 10000
    16 in base-16 is 10
    59 in base-2 is 111011
    59 in base-16 is 3b
    100 in base-2 is 1100100
    100 in base-16 is 64
    254 in base-2 is 11111110
    254 in base-16 is fe
 */

/* reverse the string, You can use reverse(s) to reverse a string - make sure you pass a character array and not a string constant to reverse */
/* pointer implementation */
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

/* array implementation
 void reverse(char t[]) {
    int i, j, len;
    char tmp;
    len = strlen(t);
    for(i=0, j=len-1;;i++,j--) {
        if (j<i) break;
        tmp = t[i];
        t[i] = t[j];
        t[j] = tmp;
    }
    return;
}
 */

/* integer to binary base 2 */
void itob(int n, char s[]) {
    int i = 0;
    while (n > 1) {
        s[i++] = n % 2 + '0';
        n = n / 2;
    }
    s[i++] = 1 + '0';
    s[i] = '\0';
    reverse(s);
}

/* integer to hexadecimal */
void itoh(int n, char s[]) {
    int i = 0;
    while (n != 0) {
        int quotient = n % 16;
        switch (quotient) {
            case 10:
                s[i++] = 'a';
                break;
            case 11:
                s[i++] = 'b';
                break;
            case 12:
                s[i++] = 'c';
                break;
            case 13:
                s[i++] = 'd';
                break;
            case 14:
                s[i++] = 'e';
                break;
            case 15:
                s[i++] = 'f';
                break;
            default:
                s[i++] = quotient + '0';
                break;
        }
        n = n / 16;
    }
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[1000];

    itob(42, s);
    printf("42 in base-2 is %s\n", s);
    itoh(42, s);
    printf("42 in base-16 is %s\n", s);

    itob(16, s);
    printf("16 in base-2 is %s\n", s);
    itoh(16, s);
    printf("16 in base-16 is %s\n", s);

    itob(59, s);
    printf("59 in base-2 is %s\n", s);
    itoh(59, s);
    printf("59 in base-16 is %s\n", s);

    itob(100, s);
    printf("100 in base-2 is %s\n", s);
    itoh(100, s);
    printf("100 in base-16 is %s\n", s);

    itob(254, s);
    printf("254 in base-2 is %s\n", s);
    itoh(254, s);
    printf("254 in base-16 is %s\n", s);
}