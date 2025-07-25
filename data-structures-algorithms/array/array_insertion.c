#include <stdio.h>

#define MAX 50

/* takes O(n) to insert an element */
int main() {
    int arr[MAX] = {1, 2, 5, 7, 8};
    const int new_item = 10;
    const int pos = 3;
    int n = 5;
    int i = 0, j = n;

    printf("the original array element: \n");
    for (i = 0; i < n; i++)
        printf("arr[%d] = %d\n", i, arr[i]);

    n = n + 1;

    /* shift element up */
    while (j >= pos) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[pos] = new_item;

    printf("the original array element: \n");
    for (i = 0; i < n; i++)
        printf("arr[%d] = %d\n", i, arr[i]);

    return 0;
}
