#include <stdio.h>

/* change base-16 to base 10 */

int main() {
    int htoi(char s[]);
    printf("htoi('8adde') = %d\n", htoi("8adde"));
    printf("htoi('f') = %d\n", htoi("f"));
    printf("htoi('F0') = %d\n", htoi("F0"));
    printf("htoi('12fab') = %d\n", htoi("12fab"));
}

int htoi(char s[]) {
    int val;
    int n = 0;

    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            val = s[i] - '0';
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            val = s[i] - 'a' + 10;
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            val = s[i] - 'A' + 10;
        } else {
            val = 0;
        }
        n = 16 * n + val;
    }

    return n;
}