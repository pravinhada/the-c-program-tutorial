#include <stdio.h>
#include <string.h>

void process(char line[]) {
    const int len = strlen(line);
    printf("\nString: %s\n", line);
    printf("Count=%d\n", len);
    for (int i = 0; i < len - 1; i++) {
        if (line[i] == ' ')
            line[i] = '-';
    }
    if (len > 10)
        printf("The ninth character is: %c\n", line[9]);
    printf("String: %s\n", line);
}

int main() {
    char line[1000];
    strcpy(line, "Hi there and welcome to LBS290");
    process(line);
    strcpy(line, "I love C");
    process(line);
}