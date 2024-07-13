#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF 1000
#define TRUE 1

/*
int main() {
    char input[BUF];
    int max = 0;
    int min = 0;

    while(TRUE) {
        fgets(input, BUF, stdin);
        input[strlen(input) - 1] = 0;
        if (strcmp(input, "done") == 0) {
            break;
        } else {
            int a  = atoi(input);
            if (max == 0 || a > max) {
                max = a;
            }
            if (min == 0 || a < min) {
                min = a;
            }
        }
    }
    printf("Maximum %d\n", max);
    printf("Minimum %d\n", min);
    return 0;
}*/

int main() {
    char input[BUF];
    int max = 0;
    int min = 0;

    while(fgets(input, BUF, stdin) != NULL) {
        input[strlen(input) - 1] = 0;
        if (strcmp(input, "done") == 0) {
            break;
        } else {
            int a  = atoi(input);
            if (max == 0 || a > max) {
                max = a;
            }
            if (min == 0 || a < min) {
                min = a;
            }
        }
    }
    printf("Maximum %d\n", max);
    printf("Minimum %d\n", min);
    return 0;
}