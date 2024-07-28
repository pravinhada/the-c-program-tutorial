#include <stdio.h>
#include <string.h>

/* keep only one line if not duplicate */
int main() {
    char line[1000];
    char keep[1000];

    while (fgets(line, 1000, stdin) != NULL) {
        if (strcmp(line, keep) == 0) {
            continue;
        }
        strcpy(keep, line);
        printf("%s\n", keep);
    }
}