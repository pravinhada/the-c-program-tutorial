#include <stdio.h>
#include "array_util.h"

/* takes constant time to update given if index is known O(1) */
int main() {
    int arr[MAX] = {1, 2, 5, 7, 8};
    int key, index;

    printf("the original array element: \n");
    print(arr);

    printf("enter element index to update: ");
    scanf("%d", &index);

    printf("enter new value: ");
    scanf("%d", &key);

    arr[index] = key;

    printf("the array element after insertion: \n");
    print(arr);
    return 0;
}