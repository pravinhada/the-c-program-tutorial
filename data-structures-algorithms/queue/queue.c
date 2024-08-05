#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 20

struct queue {
    int element[QUEUE_SIZE];
    int head;
    int tail;
};

int is_empty(struct queue *self) {
    return self->head == -1;
}

int is_full(struct queue *self) {
    int next = (self->tail + 1) % QUEUE_SIZE;
    return next == self->head;
}

void enqueue(struct queue *self, int data) {
    if (is_full(self)) {
        printf("Queue is full\n");
        return;
    }
    self->tail = (self->tail + 1) % QUEUE_SIZE;
    self->element[self->tail] = data;

    if (self->head == -1)
        self->head = self->tail;
}

int dequeue(struct queue *self) {
    if (is_empty(self)) {
        printf("Queue is empty\n");
        return 0;
    }
    int index = self->head;
    int data = self->element[index];
    if (index == self->tail)
        self->head = -1;
    else
        self->head = (index + 1) % QUEUE_SIZE;

    return data;
}

struct queue *Queue_init() {
    struct queue *new = (struct queue *) malloc(sizeof(*new));
    new->head = -1;
    new->tail = -1;
    return new;
}

void Queue_del(struct queue *self) {
    free((void *) self);
}

void display(struct queue *self) {
    if (is_empty(self)) {
        printf("Queue is empty\n");
        return;
    }
    int index = self->head;
    while (1) {
        if (index == self->tail) {
            printf("[%d]\n", self->element[index]);
            break;
        }
        printf("[%d]\n", self->element[index]);
        index = (index + 1) % QUEUE_SIZE;
    }
}

int main() {
    struct queue *my_queue = Queue_init();
    if (NULL == my_queue) {
        printf("memory allocation failed!\n");
        exit(0);
    }
    printf("isEmpty?: %d\n", is_empty(my_queue));

    enqueue(my_queue, 4);
    enqueue(my_queue, 7);
    enqueue(my_queue, 2);
    enqueue(my_queue, 6);
    enqueue(my_queue, 1);
    enqueue(my_queue, 9);
    display(my_queue);

    printf("dequeuing: %d\n", dequeue(my_queue));
    printf("dequeuing: %d\n", dequeue(my_queue));

    display(my_queue);
    Queue_del(my_queue);
    return 0;
}