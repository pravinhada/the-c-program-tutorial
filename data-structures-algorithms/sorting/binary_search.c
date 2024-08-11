#include <stdio.h>

#define SIZE 10

/* the list has to be sorted first inorder to do the binary search 
    complexity of binary search in O(log n) and space complexity O(1)
*/
int binary_search(int arr[], int low, int high, int data) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == data) {
            return mid;
        }
        if (data <= arr[mid]) {
            return binary_search(arr, low, mid - 1, data);
        } else {
            return binary_search(arr, mid + 1, high, data);
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int data = 3;
    int result = binary_search(arr, 0, SIZE - 1, data);
    if (result == -1) {
        printf("not found\n");
    } else {
        printf("found %d\n", data);
    }
    return 0;
}