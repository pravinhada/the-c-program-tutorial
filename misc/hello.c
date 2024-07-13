#include <stdio.h>

/* this is simple c program printing hello world!*/
int main() {
    char hello[] = "Hello, World!\n";
    printf("%s\n", hello);

    // basic data type in c
    // char <= short <= int <= long <= long long
    // float <= double <= long double

    // char type
    printf("char size = %lu byte\n", sizeof(char));
    printf("unsigned char size = %lu byte\n", sizeof(unsigned char));
    printf("signed char size = %lu byte\n", sizeof(signed char));

    // int type
    printf("int size = %lu byte\n", sizeof(int));
    printf("short int size = %lu byte\n", sizeof(short int));
    printf("long int size = %lu byte\n", sizeof(long int));
    printf("signed int size = %lu byte\n", sizeof(signed int));
    printf("unsigned int size = %lu byte\n", sizeof(unsigned int));

    // float type
    printf("float size = %lu byte\n", sizeof(float));
    printf("long double size = %lu byte\n", sizeof(long double));
    printf("long long size = %lu byte\n", sizeof(long long));

    printf("%d\n", 'A');
    printf("%d\n", '*');

    int x = 1 + 2 * 3 - 5 / 6;
    printf("value of x is %d\n", x);
    printf("computation of 99/100 is %d\n", 99 / 100);
    printf("value of 10>12 is %d\n", 10 > 12);
    if (42) {
        printf("42 is true\n");
    }

    int i, j;
    i = 42;
    j = i++;
    printf("value of j is %d\n", j);

    int a, b;
    a = 40;
    b = 1;
    a += ++b;
    printf("value of a after the code execute is %d\n", a);
}
