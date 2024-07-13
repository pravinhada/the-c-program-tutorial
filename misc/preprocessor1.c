#include <stdio.h>

// constants
#define PROGRAM_VERSION "1.2"

// macros
#define SUM(a, b)   ((a) + (b))

#define MAX(x, y)   ((x) > (y) ? (x) : (y))

inline int max(int a, int b) {
    return (a > b) ? a : b;
}

#define MAC

int main() {
    printf("Welcome to my latest version %s\n", PROGRAM_VERSION);

    int c = SUM(5, 5);

    printf("SUM macro result = %d\n", c);
    printf("MAX of 3 and 4 is = %d\n", MAX(3, 4));

    #if defined(WINDOWS)
        printf("Hello from windows\n");
    #elif defined(MAC)
        printf("Hello from mac\n");
    #elif defined(LINUX)
        printf("Hello from linux\n");
    #else
        printf("YOur are not in any platform\n");
    #endif


    return 0;
}