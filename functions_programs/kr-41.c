#include <stdio.h>

double faren(double celsius);

/* celsius to farenheit conversion */
int main() {
    printf("faren(42) is %.1f\n", faren(42.0));
    printf("faren(0) is %.1f\n", faren(0.0));
    printf("faren(-10) is %.1f\n", faren(-10.0));
    printf("faren(32) is %.1f\n", faren(32.0));
    printf("faren(100) is %.1f\n", faren(100.0));
    printf("faren(212) is %.1f\n", faren(212.0));
}

double faren(double celsius) {
    return (9.0 / 5.0) * celsius + 32;
}