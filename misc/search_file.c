#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Enter file name and search word as argument\n");
        return 0;
    }

    char *filename = argv[1];
    char *keyword = argv[2];
    const int len = strlen(keyword);

    FILE *pFile = fopen(filename, "r");
    if (!pFile) {
        printf("File name %s is not found\n", filename);
        return 0;
    }

    int found = 0;
    while (!feof(pFile)) {
        int c = fgetc(pFile);

        if (c == keyword[0]) {
            char word[100];
            int index = 0;
            do {
                word[index++] = c;
                c = getc(pFile);
            } while (!feof(pFile) && index < len && index < 100);
            word[index] = '\0';

            if (strcmp(keyword, word) == 0) {
                printf("%s", word);
                found++;
            } else {
                printf("%s", word);
            }

        }
        putchar(c);
    }
    printf("\nFound %d no of %s", found, keyword);
    fclose(pFile);
    pFile = NULL;
    return 0;
}