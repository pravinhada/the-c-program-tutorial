#include <stdio.h>
#include <pthread.h>

void *compute(void *arg);

int main() {
    pthread_t thread1;
    pthread_t thread2;

    int a = 1;
    int b = 2;
    pthread_create(&thread1, NULL, compute, &a);
    pthread_join(thread1, NULL);
    pthread_create(&thread2, NULL, compute, &b);

    pthread_join(thread2, NULL);

    return 0;
}


void *compute(void *arg) {
    const int a = *(int *) arg + 5;
    printf("running in thread: %d\n", a);
    return NULL;
}
