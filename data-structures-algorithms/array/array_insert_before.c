#include <stdio.h>
#include "array_util.h"

/* takes O(n) to move element */
int main() {
    int arr[MAX] = {1, 2, 5, 7, 8};
    int new_item, index;
    int i = 0;

    printf("the original array element: \n");
    print(arr);

    while (1) {
        const int len = count(arr);
        if (len >= MAX - 1) { /* one element is for '\0' */
            printf("array is full\n");
            break;
        }
        printf("enter before index to insert (0-%d)\n", MAX - 2);
        scanf("%d", &index);
        printf("enter new item:\n");
        scanf("%d", &new_item);
        /* shift element */
        for (i = len; i >= index - 1; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index - 1] = new_item;
        printf("the array element after insertion: \n");
        print(arr);
    }
    return 0;
}
