#include <stdio.h>

#define MAX 1000

int main() {
    char line[MAX];
    printf("Enter line\n");
    fgets(line, MAX, stdin);
    printf("Line: %s\n", line);
    return 0;
}