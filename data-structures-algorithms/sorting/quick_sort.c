#include <stdio.h>

#define SIZE 10

/* O(nlogn) complexity of this algorithm, it is not adaptive sort and also takes extra space due to recursion and it is not stable */
/* it is preferred to merge sort */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int l = low;
    int h = high;

    while (l < h) {
        while (arr[l] <= pivot && l <= high - 1)
            l++;
        while (arr[h] > pivot && h >= low + 1)
            h--;
        
        if (l < h)
            swap(&arr[l], &arr[h]);
    }
    swap(&arr[low], &arr[h]);
    printf("Pivot: %d\n", pivot);
    print(arr);
    return h;
}

void quick_sort(int arr[], int low, int high) {
    if (low >= high) return;

    int pivot = partition(arr, low, high);
    quick_sort(arr, low, pivot - 1);
    quick_sort(arr, pivot + 1, high);
}

int main() {
    int data[10] = {5, 10, 4, 7, 2, 8, 3, 9, 1, 6};

    printf("Before:\n");
    print(data);
    quick_sort(data, 0, SIZE - 1);
    printf("After: \n");
    print(data);
    return 0;
}