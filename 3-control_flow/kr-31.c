#include <stdio.h>
int main()
{
    char t[1000];
    void expand(char s[], char t[]);
    expand("Hello world", t);
    printf("%s\n", t);
    expand("Hello world\n", t);
    printf("%s\n", t);
    expand("Hello\tworld\n", t);
    printf("%s\n", t);
    expand("Hello\tworld\nHave a nice\tday\n", t);
    printf("%s\n", t);
}

void expand(char s[], char t[])
{
    int i, j;
    for (i = 0, j = 0; s[i]; i++)
    {
        switch (s[i])
        {
        case '\n':
            t[j++] = '\\';
            t[j++] = 'n';
            i++;
            break;
        case '\t':
            t[j++] = '\\';
            t[j++] = 't';
            i++;
            break;
        default: ;
        }
        t[j++] = s[i];
    }
    t[j] = '\0';
}