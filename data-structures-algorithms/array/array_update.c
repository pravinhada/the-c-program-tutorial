#include <stdio.h>
#include <stdlib.h>

#include "array_util.h"

/* takes constant time to update given if index is known O(1) */
int main() {
    int arr[MAX] = {1, 2, 5, 7, 8};
    char ch[10];

    printf("the original array element: \n");
    print(arr);

    printf("enter element index to update: ");
    scanf("%s", ch);
    const int index = atoi(ch);

    printf("enter new value: ");
    scanf("%s", ch);
    const int key = atoi(ch);

    arr[index] = key;

    printf("the array element after insertion: \n");
    print(arr);
    return 0;
}
