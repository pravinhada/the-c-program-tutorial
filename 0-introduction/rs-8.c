#include <stdio.h>

int main() {
    int guess;
    while (scanf("%d", &guess) != EOF) {

        if (guess == 42) {
            printf("Nice work!\n");
            break;
        }
        if (guess < 42) {
            printf("Too low - guess again\n");
        } else {
            printf("Too high - guess again\n");
        }
    }
    return 0;
}