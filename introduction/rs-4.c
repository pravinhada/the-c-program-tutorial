#include <stdio.h>

int main() {
    char line[1000];
    printf("Enter line\n");
    scanf("%[^\n]", line);
    printf("Line: %s\n", line);
    return 0;
}