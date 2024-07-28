#include <stdio.h>
#include "array_util.h"


/* takes constant time O(1) to insert but O(n) to shift an element */
int main() {
    int arr[MAX] = {1, 2, 5, 7, 8};
    int new_item;
    int i, len;

    printf("the original array element: \n");
    print(arr);

    while (1) {
        len = count(arr);
        if (len >= MAX - 1) { /* one element is for '\0' */
            printf("array is full\n");
            break;
        }
        scanf("%d", &new_item);

        /* shift element */
        for (i = len; i >= 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = new_item;
    }

    printf("the array element after insertion: \n");
    print(arr);

    return 0;
}
