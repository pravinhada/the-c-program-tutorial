#include <stdio.h>

int a = 0;

int main() {
    void print();
    printf("from main %d\n", a);
    print();
    printf("back to main %d\n", a);
    return 0;
}