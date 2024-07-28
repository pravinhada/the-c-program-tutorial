#include <stdio.h>

/* if overtime (> 40hrs), rates is times-and-a-half */
void calcpay(float *p, float r, float h) {
    if (h > 40)
        *p = r * 40 + ((r + r / 2) * (h - 40));
    else
        *p = r * h;
}

int main() {
    int empno;
    float rate, hours, pay;

    while (1) {
        if (scanf("%d %f %f", &empno, &rate, &hours) < 3) break;
        calcpay(&pay, rate, hours);
        printf("Employee=%d Rate=%.2f Hours=%.2f Pay=%.2f\n", empno, rate, hours, pay);
    }

    return 0;
}