#include <stdio.h>

/*
 * print Fahrenheit-Celsius table from 0 to 300
 */
int main() {
    const float lower = 0;
    const float upper = 300;

    float fahr = lower;
    printf("Fahrenheit\t Celsius\n");
    while (fahr <= upper) {
        const float step = 20;
        const float celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}