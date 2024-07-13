#include <stdio.h>

int main() /* Fix this to be Celsius-Fahrenheit table */
{
    int cel;
    for (cel = 0; cel <= 100; cel = cel + 20) {
        printf("%4d %6.1f\n", cel, (cel * 9.0f/5) + 32);
    }
}