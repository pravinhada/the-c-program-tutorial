#include <stdio.h>

/* recursive function to sum all the number in the series n
 * Also, in order to avoid stack overflow, if the provided number is above 100 return -1 and if less than 0 return 0 */

int sumseries(int n) {
    if (n <= 0) {
        return 0;
    } else if (n > 100) {
        return -1;
    } else if (n == 1) {
        return 1;
    } else {
        return (n + sumseries(n - 1));
    }
}

int main() {
    printf("sumseries(0) returns %d\n", sumseries(0));
    printf("sumseries(1) returns %d\n", sumseries(1));
    printf("sumseries(5) returns %d\n", sumseries(5));
    printf("sumseries(42) returns %d\n", sumseries(42));
    printf("sumseries(-42) returns %d\n", sumseries(-42));
    printf("sumseries(100) returns %d\n", sumseries(100));
    printf("sumseries(101) returns %d\n", sumseries(101));
    printf("sumseries(1000) returns %d\n", sumseries(1000));
}