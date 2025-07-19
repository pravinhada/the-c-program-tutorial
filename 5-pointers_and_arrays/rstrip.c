#include <stdio.h>
#include <string.h>

/* python rstrip implementation */
void py_rstrip(char input[]) {
    const int len = strlen(input);
    char *t = input + len - 1;
    while (*(t) == ' ')
        t--;
    *(t + 1) = '\0';
}

int main() {
    char s1[] = "   Hello   World    ";
    py_rstrip(s1);
    printf("-%s-\n", s1);
}