#include <stdio.h>

/* worst case if the list is reversed sorted */
/* O(n^2) time complexity, O(n^2) swapping and O(1) for space and similar to bubble sort this is also adaptive */
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

void insertion_sort(int a[], const int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j > 0; j--) {
            if (a[j] < a[j - 1]) {
                swap(&a[j], &a[j - 1]);
            } else {
                break;
            }
        }
        print(a, size);
    }
}

int main() {
    int data[] = {5, 10, 4, 7, 2, 8, 3, 9, 1, 6};
    const int size = sizeof(data) / sizeof(data[0]);
    insertion_sort(data, size);
    return 0;
}