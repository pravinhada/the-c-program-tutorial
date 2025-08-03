#include <stdio.h>
#include <stdbool.h>

void function(const int x) {
    printf("x: %d\n", x);
}

int add(const int x, const int y) {
    return x + y;
}

int subtract(const int x, const int y) {
    return x - y;
}

int multiply(const int x, const int y) {
    return x * y;
}

int divide(const int x, const int y) {
    return x / y;
}

/* return pointer to function that take two argument int, int and return int */
int (*select_operation())(int, int) {
    int option;
    printf("Enter the operation: \n");
    printf("1) Add: \n");
    printf("2) Subtract: \n");
    printf("3) Multiply: \n");
    printf("4) Divide: \n");
    printf("Enter: ");
    scanf("%d", &option);

    if (option == 1) {
        return add;
    } else if (option == 2) {
        return subtract;
    } else if (option == 3) {
        return multiply;
    } else if (option == 4) {
        return divide;
    } else {
        return NULL;
    }
}

bool freeze_c(const int temperature) {
    return temperature <= 0;
}

bool freeze_f(const int temperature) {
    return temperature <= 32;
}

// call-back function
void is_freezing(bool (*freeze_check)(int)) {
    int temperature = 0;
    printf("Enter temperature:  ");
    scanf("%d", &temperature);

    if (freeze_check(temperature)) {
        printf("It's freezing\n");
    } else {
        printf("It's not freezing\n");
    }
}

int main() {

    void (*function_pointer)(int) = &function;
    (*function_pointer)(4);
    function_pointer(4); // same

    int (*add_pointer)(int, int) = &add;
    const int result = (*add_pointer)(30, 40);
    printf("result is %d\n", result);

    int (*array[])(int, int) = {add, subtract, multiply};
    const int product = (*array[1])(3, 4);

    printf("product is: %d\n", product);

    int (*operation)(int, int) = select_operation();
    printf("answer: %d\n", operation(20, 5));

    printf("Celsius: \n");
    is_freezing(freeze_c);
    return 0;
}