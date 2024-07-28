#include <stdio.h>

void print(int arr[]) {
    int i = 0;
    while (*arr != '\0') {
        printf("arr[%d] = %d\n", i++, *arr);
        arr++;
    }
}

int count(int arr[]) {
    int i = 0;
    while (*arr != '\0') {
        i++;
        arr++;
    }
    return i;
}