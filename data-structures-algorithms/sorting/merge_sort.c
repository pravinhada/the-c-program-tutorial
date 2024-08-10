#include <stdio.h>

#define SIZE 10

/* O(nlogn) time complexity, with additional space requirement */

void merge(int arr[], int low, int mid, int high) {
    int i, j, k;

    int s1 = mid - low + 1;
    int s2 = high - mid;

    /* temporary array */
    int left[s1];
    int right[s2];

    /* copy the data from original */
    for (i = 0; i < s1; i++)
        left[i] = arr[low + i];

    for (j = 0; j < s2; j++)
        right[j] = arr[mid + 1 + j];

    i = 0, j = 0, k = low;

    while (i < s1 && j < s2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < s1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < s2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int low, int high) {
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void print(int arr[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int data[10] = {5, 10, 4, 7, 2, 8, 3, 9, 1, 6};

    printf("Before:\n");
    print(data);
    merge_sort(data, 0, SIZE - 1);
    printf("After: \n");
    print(data);
    return 0;
}