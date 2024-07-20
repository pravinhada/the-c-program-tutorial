#include <stdio.h>
#include <stdlib.h>

struct lnode {
    int value;
    struct lnode *next;
};

struct list {
    struct lnode *head;
    struct lnode *tail;
};

void list_add(struct list *lst, int value) {
    /* Append the value to the end of the linked list. */
    struct lnode *node = malloc(sizeof(struct lnode));
    node->value = value;
    node->next = NULL;

    if (lst->head == NULL && lst->tail == NULL) {
        lst->head = node;
        lst->tail = node;
    } else {
        struct lnode *current = lst->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
        lst->tail = current->next;
    }
}

void list_remove(struct list *lst, int value) {
    struct lnode *current = lst->head;
    struct lnode *prev;

    if (lst->head->value == value) {
        lst->head = current->next;
        free(current);
        current = NULL;
    } else {
        prev = current;
        current = current->next;
        while (current != NULL) {
            if (current->value == value) {
                prev->next = current->next;
                free(current);
                current = NULL;
                break;
            }
            prev = current;
            current = current->next;
        }
    }
}

struct lnode *list_find(struct list *lst, int value) {
    struct lnode *current = lst->head;
    while (current != NULL) {
        if (current->value == value)
            return current;
        current = current->next;
    }
    return NULL;
}

void list_dump(struct list *lst) {
    struct lnode *cur;
    printf("\nDump:\n");
    for (cur = lst->head; cur != NULL; cur = cur->next) {
        printf("  %d\n", cur->value);
    }
}

int main() {
    struct list mylist;
    struct lnode *mynode;

    mylist.head = NULL;
    mylist.tail = NULL;

    list_add(&mylist, 10);
    list_add(&mylist, 20);
    list_add(&mylist, 30);
    list_dump(&mylist);

    list_remove(&mylist, 42);

    list_remove(&mylist, 10);
    list_dump(&mylist);

    list_remove(&mylist, 30);
    list_dump(&mylist);

    list_add(&mylist, 40);
    list_dump(&mylist);
}



