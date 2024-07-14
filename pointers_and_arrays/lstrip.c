#include <stdio.h>
#include <string.h>

/* python lstrip implementation */
void py_lstrip(char input[]) {
    char *t = input;
    while (*t == ' ')
        t++;
    while ((*input++ = *t++) != '\0');
}

int main() {
    char s1[] = "   Hello   World    ";
    printf("-%s-\n", s1);
    py_lstrip(s1);
    printf("-%s-\n", s1);
}