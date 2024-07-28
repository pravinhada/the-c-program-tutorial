#include <stdio.h>
#include <string.h>

/*
42 > 114 > 105 > 97 >
110 < < < < 66

 will be output as:
 Memory:
 Brian
 */

int main() {
    char memory[256], token[256];
    int position = 0, value;
    while (scanf("%s", token) == 1) {
        if (strcmp(token, "<") == 0)
            position--;
        else if (strcmp(token, ">") == 0)
            position++;
        else {
            sscanf(token, "%d", &value);
            memory[position] = value;
        }
    }
    printf("Memory:\n%s\n", memory);
}