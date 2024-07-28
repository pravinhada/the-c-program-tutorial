#include <stdio.h>
#include <string.h>

/* concat two string using strcpy and strcat library */
int main() {
    char a[100];
    char b[100];
    char result[200];
    printf("Enter two strings\n");
    scanf("%s\n", a);
    scanf("%[^\n]", b);
    strcpy(result, a);
    strcat(result, " & ");
    strcat(result, b);
    printf("you have entered %s \n", result);

}