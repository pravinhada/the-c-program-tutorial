#include <stdio.h>

#define LEN 10

int main() {
    int i, j, v, arr[LEN], result[LEN];
    for (i = 0; i < 10; i++) {
        scanf("%d", &v);
        arr[i] = v;
    }
    j = 0;
    for (i = LEN - 1; i >= 0; i--) {
        if (arr[i] == 100)
            result[j++] = i;
        printf("num[%d] = %d\n", i, arr[i]);
    }

    printf("Searching for entries equal to 100\n");
    for (i = j - 1; i >= 0; i--)
        printf("Found 100 at %d\n", result[i]);

    printf("Found %d entries with 100\n", j);
}