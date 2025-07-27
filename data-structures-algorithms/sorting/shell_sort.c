#include <stdio.h>

/* better than insertion sort */
/* complexity lies between O(n) and O(n^2) */
void swap(int *a, int *b) {
    const int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int a[], const int size) {
    for (int i = 0; i < size; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");
}

int min(const int a, const int b) {
    return a > b ? b : a;
}

void insertion_sort(int a[], const int size, const int startIndex, const int increment) {
    for (int i = startIndex; i < size; i = i + increment) {
        for (int j = min(i + increment, size - 1); j - increment >= 0; j = j - increment) {
            if (a[j] < a[j - increment]) {
                swap(&a[j], &a[j - increment]);
            } else {
                break;
            }
        }
        print(a, size);
    }
}

void shell_sort(int a[], const int size) {
    int increment = size / 3;
    while (increment >= 1) {
        for (int startIndex = 0; startIndex < increment; startIndex++) {
            insertion_sort(a, size, startIndex, increment);
        }
        increment = increment / 2;
    }
}


int main() {
    int data[] = {5, 10, 4, 7, 2, 8, 3, 9, 1, 6};
    const int size = sizeof(data) / sizeof(data[0]);
    shell_sort(data, size);
    return 0;
}