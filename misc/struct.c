#include <stdio.h>

struct Point {
    float x;    // 4 bytes
    float y;    // 4 bytes
};

struct Point p1, p2;

void printPoint(const struct Point p) {
    printf("x = %f, y = %f\n", p.x, p.y);
}

// pass by value
void changePoint(struct Point p) {
    p.x = 15;
    p.y = 25;
}

// pass by reference
void changePointAgain(struct Point *p) {
    p->x = 30;
    p->y = 40;
}

int main() {

    p1.x = 10;
    p1.y = 20;
    printPoint(p1);
    changePoint(p1);
    printPoint(p1);
    changePointAgain(&p1);
    printPoint(p1);

    printf("Size of Point is %lu bytes\n", sizeof(p1));
    printf("Size of Point struct is %lu bytes\n", sizeof(struct Point));
}