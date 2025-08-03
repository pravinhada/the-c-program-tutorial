#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

struct Element {
    char data;
    struct Element *next;
};

struct Stack {
    struct Element *top;
    int count;
};

void Stack_push(struct Stack *self, const char input) {
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

char Stack_pop(struct Stack *self) {
    if (self == NULL || self->top == NULL) {
        printf("Stack underflow\n");
        return 0;
    }
    struct Element *cur = self->top;
    const char data = cur->data;
    self->top = cur->next;
    free(cur);
    self->count--;
    return data;
}

char Stack_peek(const struct Stack *self) {
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
    if (NULL == stack) {
        printf("Stack allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->count = 0;
    return stack;
}

int is_balance(struct Stack *self, const char *test) {
    int balance = 0;
    while (*test != '\0') {
        char s;
        printf("%c", *test);
        if (*test == '(' || *test == '{' || *test == '[')
            Stack_push(self, *test);

        switch (*test) {
            case ')':
                s = Stack_pop(self);
                balance = (s == '(') ? 1 : 0;
                break;
            case '}':
                s = Stack_pop(self);
                balance = (s == '{') ? 1 : 0;
                break;
            case ']':
                s = Stack_pop(self);
                balance = (s == '[') ? 1 : 0;
                break;
            default:
                break;
        }
        test++;
    }
    return balance;
}

int main() {
    int balance = 0;
    const char *test = "(ABC)[{ZXYS}]{PQR}[HELLO]";
    struct Stack *stack = Stack_init();

    balance = is_balance(stack, test);
    printf("\n");

    if (balance == 1 && Stack_length(stack) == 0)
        printf("expression is balance\n");
    else
        printf("expression is not balance\n");

    Stack_del(stack);
    stack = NULL;
    return 0;
}
