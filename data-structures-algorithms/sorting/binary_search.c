#include <stdio.h>

#define SIZE 10

/* the list has to be sorted first inorder to do the binary search 
    complexity of binary search in O(log n) and space complexity O(1)
*/
int binary_search(int arr[], const int low, const int high, const int data) {
    if (low <= high) {
        const int mid = low + (high - low) / 2;

        if (arr[mid] == data) {
            return mid;
        }
        if (data <= arr[mid]) {
            return binary_search(arr, low, mid - 1, data);
        }
        return binary_search(arr, mid + 1, high, data);
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int data = 8; // search 3 from the arr
    const int result = binary_search(arr, 0, SIZE - 1, data);
    if (result == -1) {
        printf("not found\n");
    } else {
        printf("found %d\n", data);
    }
    return 0;
}