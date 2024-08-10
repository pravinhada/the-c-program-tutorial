#include <stdio.h>

#define SIZE 10

/* O(nlogn) complexity of this algorithm, it is not adaptive sort and also takes extra space due to recursion and it is not stable */
/* it is preferred to merge sort */

void swap(int arr[], int low, int high) {
    int temp;
    temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
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
        while (arr[l] <= pivot && l < h)
            l++;
        while (arr[h] > pivot)
            h--;
        
        if (l < h)
            swap(arr, l ,h);
    }
    swap(arr, low, h);
    printf("Pivot: %d\n", pivot);
    print(arr);
    return pivot;
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