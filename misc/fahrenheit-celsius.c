#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

/*
 * print Fahrenheit-Celsius table from 0 to 300
 */
int main() {
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP) {
        printf("%3d\t %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
    return 0;
}