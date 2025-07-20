#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max line to be sorted */
#define MAXLEN 1000   /* max length of any input line */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);

void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int getlines(char a[], int);

char *alloc(int);

static char allocbuf[MAXLEN];
static char *allocp = allocbuf;

void freebuf(char *p);

void swap(char *lineptr[], int i, int j);

int main() {
    int nlines; /* number of input lines read */

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

int readlines(char *lineptr[], int maxlines) {
    int len;
    char *p, line[MAXLEN];

    int nlines = 0;
    while ((len = getlines(line, MAXLEN)) > 0) {
        if (nlines >= maxlines)
            return -1;
        else if ((p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    printf("\n");
    for (int i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
        freebuf(lineptr[i]);
    }
}

/* qsort: sort v[left] ... v[right] into increasing order */
void qsort(char *lineptr[], int left, int right) {
    if (left >= right)
        return;
    swap(lineptr, left, (left + right) / 2);
    int last = left;
    for (int i = left + 1; i <= right; i++) {
        if (strcmp(lineptr[i], lineptr[left]) < 0)
            swap(lineptr, ++last, i);
    }
    swap(lineptr, left, last);
    qsort(lineptr, left, last - 1);
    qsort(lineptr, last + 1, right);
}

void swap(char *lineptr[], int i, int j) {
    char *temp = lineptr[i];
    lineptr[i] = lineptr[j];
    lineptr[j] = temp;
}

int getlines(char a[], const int lim) {
    int c = 0, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        a[i] = c;
    }
    if (c == '\n')
        a[i++] = c;

    a[i] = '\0';
    return i;
}

char *alloc(const int n) {
    if (allocp + n <= allocbuf + MAXLEN) {
        allocp += n;
        return (allocp - n);
    } else
        return NULL;
}

void freebuf(char *p) {
    if (p >= allocbuf && p < allocbuf + MAXLEN)
        allocp = p;
}