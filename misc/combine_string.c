#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *combineString(const char *p1, const char *p2) {

    if (!p1 && !p2) {
        return NULL;
    }

    const int size = strlen(p1) + strlen(p2);
    char *pResult = malloc(sizeof(char) * (size + 1)); // dynamically allocate memory

    //strcpy(presult, p1);
    //strcat(presult, p2);
    sprintf(pResult, "%s%s", p1, p2);
    return pResult;
}


int main() {
    char *pResult = combineString("Hello ", "World!");

    if (pResult) {
        printf("%s\n", pResult);

        free(pResult); // free memory and set to NULL
        pResult = NULL;
    }
    return 0;
}
