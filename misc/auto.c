#include <stdio.h>

void printNumber() {
    static int n = 0; // initialize first time it is call, subsequent it will be ignored
    n++;
    printf("number = %d\n", n);
}

int main() {
    int auto n = 100; //automatically allocated and deallocated in stack, optional

    printf("n = %d\n", n);

    register int i; // only recommendation from us to compiler, can't reference, stores in register memory
    for (i = 0; i < 100; i++) {
        printf("i = %d\n", i);
    }
    printNumber();
    printNumber();
    printNumber();
    return 0;
}