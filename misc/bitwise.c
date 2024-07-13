#include <stdio.h>

int main() {

    int n1 = 4; // 0100
    int n2 = 5; // 0101

    int result1 = n1 & n2;
    int result2 = n1 | n2;
    int result3 = n1 ^ n2;
    unsigned int result4 = ~n1;
    unsigned int result5 = n1 >> 1;
    unsigned int result6 = n1 << 1;

    printf("%d & %d = %d\n", n1, n2, result1);
    printf("%d | %d = %d\n", n1, n2, result2);
    printf("%d ^ %d = %d\n", n1, n2, result3);
    printf("~%d = %d\n", n1, result4);
    printf("%d >> %d =  %d\n", n1, 1, result5); //0010
    printf("%d << %d =  %d\n", 1, n1, result6); //1000


}