#include <stdio.h>
#include "array_util.h"

/* takes O(n) times to search in an array of length n */
int main() {
    int arr[MAX] = {1, 2, 5, 7, 8};
    int key;
    int i = 0;

    printf("the original array element: \n");
    print(arr);

    printf("enter element to search: ");
    scanf("%d", &key);

    while (arr[i] != '\0') {
        if (arr[i] == key) {
            printf("found item %d at position %d\n", key, i);
            break;
        }
        i++;
    }
    return 0;
}