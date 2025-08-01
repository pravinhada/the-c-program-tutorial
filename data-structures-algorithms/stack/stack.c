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
    free(self);
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
    struct Stack *stack = Stack_init();
    if (NULL == stack) {
        printf("stack is null\n");
        return -1;
    }
    Stack_push(stack, 5);
    Stack_push(stack, 4);
    Stack_push(stack, 7);
    Stack_push(stack, 3);
    Stack_push(stack, 9);
    Stack_display(stack);

    Stack_pop(stack);
    Stack_pop(stack);
    Stack_pop(stack);

    printf("stack length is: %d\n", Stack_length(stack));
    Stack_pop(stack);
    Stack_pop(stack);
    Stack_pop(stack);

    Stack_peek(stack);

    Stack_del(stack);
    return 0;
}