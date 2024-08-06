#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

struct Element {
    int data;
    struct Element *next;
};

struct Stack {
    struct Element *top;
    int count;
};

void Stack_push(struct Stack *self, int input) {
    struct Element *element;
    if (self->count > MAX_SIZE) {
        printf("Stack overflow\n");
        return;
    }

    element = (struct Element *) malloc(sizeof(*element));
    element->data = input;

    element->next = self->top;
    self->top = element;
    self->count++;
}

int Stack_pop(struct Stack *self) {
    int data;
    struct Element *cur;
    if (self == NULL || self->top == NULL) {
        printf("Stack underflow\n");
        return 0;
    }
    cur = self->top;
    data = cur->data;
    self->top = cur->next;
    free(cur);
    self->count--;
    return data;
}

int Stack_peek(struct Stack *self) {
    if (self->count == 0) {
        printf("Stack is empty!\n");
        return 0;
    }
    return self->top->data;
}

void Stack_del(struct Stack *self) {
    struct Element *cur, *next;
    cur = self->top;
    while (cur != NULL) {
        next = cur->next;
        free(cur);
        cur = next;
    }
    free((void *) self);
}

int Stack_length(struct Stack *self) {
    if (self == NULL) return 0;
    return self->count;
}

void Stack_display(struct Stack *self) {
    struct Element *cur;
    if (self == NULL || self->count == 0) return;
    cur = self->top;
    printf("Displaying contain of Stack:\n");
    while (cur != NULL) {
        printf("[%d]\n", cur->data);
        cur = cur->next;
    }
}

struct Stack *Stack_init(void) {
    struct Stack *stack = (struct Stack *) malloc(sizeof(*stack));
    if (NULL == stack) {
        printf("cannot allocate memory for stack!");
        exit(0);
    }
    stack->count = 0;
    stack->top = NULL;
    return stack;
}

struct queue {
    struct Stack *forwardStack;
    struct Stack *reverseStack;
};

int is_empty(struct queue *self) {
    return self->forwardStack->count == 0
           && self->reverseStack->count == 0;
}

int is_full(struct queue *self) {
    return self->forwardStack->count == MAX_SIZE
           || self->reverseStack->count == MAX_SIZE;
}

void enqueue(struct queue *self, int data) {
    if (is_full(self)) {
        printf("Queue is full\n");
        return;
    }
    if (!is_empty(self)) {
        int size = self->reverseStack->count;
        while (size != 0) {
            Stack_push(self->forwardStack, Stack_pop(self->reverseStack));
            size--;
        }
    }
    Stack_push(self->forwardStack, data);
}

int dequeue(struct queue *self) {
    if (is_empty(self)) {
        printf("Queue is empty\n");
        return 0;
    }
    int size = self->forwardStack->count;
    while (size != 0) {
        Stack_push(self->reverseStack, Stack_pop(self->forwardStack));
        size--;
    }
    return Stack_pop(self->reverseStack);
}

void Queue_del(struct queue *self) {
    free((void *) self);
}

struct queue *Queue_init() {
    struct queue *new = (struct queue *) malloc(sizeof(*new));
    if (NULL == new) {
        printf("cannot allocate memory for queue!");
        exit(0);
    }
    new->forwardStack = Stack_init();
    new->reverseStack = Stack_init();
    return new;
}

int main() {
    struct queue *new = Queue_init();
    enqueue(new, 1);
    enqueue(new, 2);
    enqueue(new, 3);
    enqueue(new, 4);
    enqueue(new, 5);
    enqueue(new, 6);
    Stack_display(new->forwardStack);
    printf("dequeue: %d\n", dequeue(new));
    enqueue(new, 7);

    Stack_display(new->forwardStack);

    Stack_del(new->forwardStack);
    Stack_del(new->reverseStack);
    Queue_del(new);
}

