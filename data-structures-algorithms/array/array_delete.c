#include <stdio.h>
#include "array_util.h"

/* takes O(n) to move element */
int main() {
    int arr[MAX] = {1, 2, 5, 7, 8};
    int index;
    int i = 0;

    printf("the original array element: \n");
    print(arr);

    while (1) {
        const int len = count(arr);
        if (len <= 0) { /* one element is for '\0' */
            printf("array is empty\n");
            break;
        }
        printf("enter array index to delete (0-%d)\n", MAX - 2);
        scanf("%d", &index);

        /* shift element */
        for (i = index; i < len; i++) {
            arr[i] = arr[i + 1];
        }
        arr[i + 1] = '\0';
        printf("the array element after deletion: \n");
        print(arr);
    }
    return 0;
}