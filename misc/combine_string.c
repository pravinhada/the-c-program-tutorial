#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *combineString(const char *p1, const char *p2) {

    if (NULL == p1 && NULL == p2) {
        return NULL;
    }

    int size = strlen(p1) + strlen(p2);
    char *presult = (char *) malloc(sizeof(char) * (size + 1)); // dynamically allocate memory

    //strcpy(presult, p1);
    //strcat(presult, p2);
    sprintf(presult, "%s%s", p1, p2);
    return presult;
}


int main() {
    char *presult = combineString("Hello ", "World!");

    if (NULL != presult) {
        printf("%s\n", presult);

        free(presult); // free memory and set to NULL
        presult = NULL;
    }
    return 0;
}
