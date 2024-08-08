#include <stdio.h>

/* O(n^2) of time complexity and not adaptive
 * since we don't know the sort until it
 * completely end the loops */

/* swap using pointer */
void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");
}

/* O(n^2) complexity */
void selection_sort(int s[], int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (s[i] > s[j]) {
                swap(&s[i], &s[j]);
            }
            print(s, size);
        }
    }
}

int main() {
    int data[] = {5, 10, 4, 7, 2, 8, 3, 9, 1, 6};
    int size = sizeof(data) / sizeof(data[0]);
    selection_sort(data, size);
    return 0;
}