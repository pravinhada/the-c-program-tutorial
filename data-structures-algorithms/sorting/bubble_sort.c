#include <stdio.h>

/* O(n^2) time complexity, O(n^2) swapping and O(1) for space */
/* bubble sort is adaptive than selection sort, since the sorting
 * might complete earlier, which is indicated by boolean isSwapped,
 * if no swap occurred in a loop, then it's considered to be sorted */

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

void bubble_sort(int a[], const int size) {
    for (int i = 0; i < size; i++) {
        int isSwapped = 0;
        for (int j = size - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                swap(&a[j], &a[j - 1]);
                isSwapped = 1;
            }
        }
        if (isSwapped == 0)
            break;
        print(a, size);
    }
}

int main() {
    int data[] = {5, 10, 4, 7, 2, 8, 3, 9, 1, 6};
    const int size = sizeof(data) / sizeof(data[0]);
    bubble_sort(data, size);
    return 0;
}