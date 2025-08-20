#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

// Helper struct to manage dynamic array of Point struct pointers
typedef struct {
    Point **point;
    int size;
} IntPtrArray;

// Count function is now unnecessary, as size is tracked

void add_txn(IntPtrArray *arr, const int x, const int y) {
    Point *p = malloc(sizeof(Point));
    if (!p) {
        return;
    }
    p->x = x;
    p->y = y;

    Point **tmp = realloc(arr->point, (arr->size + 1) * sizeof(Point *));
    if (!tmp) {
        fprintf(stderr, "Reallocation failed\n");
        free(p);
        return;
    }
    arr->point = tmp;
    arr->point[arr->size] = p;
    arr->size++;
}

int main() {
    printf("double pointer example\n");
    IntPtrArray arr = {NULL, 0};
    add_txn(&arr, 2, 4);
    add_txn(&arr, 3, 6);
    add_txn(&arr, 5, 10);

    for (int i = 0; i < arr.size; i++) {
        printf("Point: (%d, %d)\n", arr.point[i]->x, arr.point[i]->y);
        free(arr.point[i]);
        arr.point[i] = NULL;
    }
    free(arr.point);
    arr.point = NULL;
    return 0;
}
