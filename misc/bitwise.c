#include <stdio.h>

int main() {

    const int n1 = 4; // 0100
    const int n2 = 5; // 0101

    const int result1 = n1 & n2;
    const int result2 = n1 | n2;
    const int result3 = n1 ^ n2;
    const unsigned int result4 = ~n1;
    const unsigned int result5 = n1 >> 1;
    const unsigned int result6 = n1 << 1;

    printf("%d & %d = %d\n", n1, n2, result1); // 0100
    printf("%d | %d = %d\n", n1, n2, result2); // 0101
    printf("%d ^ %d = %d\n", n1, n2, result3); // 0001
    printf("~%d = %d\n", n1, result4);
    printf("%d >> %d =  %d\n", n1, 1, result5); //0010
    printf("%d << %d =  %d\n", 1, n1, result6); //1000


}