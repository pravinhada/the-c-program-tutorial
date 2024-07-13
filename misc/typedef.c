#include <stdio.h>

struct Rectangle {
    int x1, y1, x2, y2;
};

typedef struct Rectangle RECT;

int main() {
    RECT r1, r2;
    r1.x1 = 1;
    r1.y1 = 1;
    r1.x2 = 4;
    r1.y2 = 4;

    printf("Rectangle x1 = %d, x2 = %d, y1 = %d and y2 = %d\n", r1.x1, r1.x2, r1.y1, r1.y2);
    return 0;

}