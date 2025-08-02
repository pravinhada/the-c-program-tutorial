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

void Stack_push(struct Stack *self, const int input) {
    if (self == NULL) return;
    if (self->count > MAX_SIZE) {
        printf("Stack overflow\n");
        return;
    }

    struct Element *element = malloc(sizeof(*element));
    element->data = input;

    element->next = self->top;
    self->top = element;
    self->count++;
}

int Stack_pop(struct Stack *self) {
    if (self == NULL || self->top == NULL) {
        printf("Stack underflow\n");
        return 0;
    }
    struct Element *cur = self->top;
    const int data = cur->data;
    self->top = cur->next;
    free(cur);
    printf("popped: [%d]\n", data);
    self->count--;
    return data;
}

int Stack_peek(const struct Stack *self) {
    if (self == NULL || self->top == NULL) {
        printf("Stack underflow\n");
        return 0;
    }
    if (self->count == 0) {
        printf("Stack is empty!\n");
        return 0;
    }
    return self->top->data;
}

void Stack_del(struct Stack *self) {
    struct Element *cur = self->top;
    while (cur != NULL) {
        struct Element *next = cur->next;
        free(cur);
        cur = next;
    }
    free((void *) self);
}

int Stack_length(const struct Stack *self) {
    if (self == NULL) return 0;
    return self->count;
}

void Stack_display(const struct Stack *self) {
    if (self == NULL || self->count == 0) return;
    const struct Element *cur = self->top;
    printf("Displaying contain of Stack:\n");
    while (cur != NULL) {
        printf("[%d]\n", cur->data);
        cur = cur->next;
    }
}

struct Stack *Stack_init(void) {
    struct Stack *stack = malloc(sizeof(*stack));
    stack->count = 0;
    stack->top = NULL;
    return stack;
}

int main() {
    struct Stack *stack1 = Stack_init();
    struct Stack *stack2 = Stack_init();
    if (NULL == stack1 || NULL == stack2) {
        printf("Stack init failed\n");
        return -1;
    }

    int ele[] = {3, 5, 7, 2, 1, 9};
    const int len = 6;

    for (int i = 0; i < len; i++) {
        if (Stack_length(stack1) == 0) {
            Stack_push(stack1, ele[i]);
            Stack_push(stack2, ele[i]);
        } else {
            const int last = Stack_peek(stack2);
            if (ele[i] >= last)
                Stack_push(stack2, last);
            else
                Stack_push(stack2, ele[i]);
            Stack_push(stack1, ele[i]);
        }
    }
    printf("minimum is: %d\n", Stack_peek(stack2));

    Stack_del(stack1);
    Stack_del(stack2);
    return 0;
}