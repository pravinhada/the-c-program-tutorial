#include <stdio.h>

int main() {
    float f;
    float total = 0.0;
    for (int n = 0; n < 5; n++) {
        scanf("%f", &f);
        total += f;
    }

    printf("The total is: %.1f\n", total);
    printf("The average is: %.1f\n", total / 5);

}