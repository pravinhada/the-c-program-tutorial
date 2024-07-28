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
        lst->tail = node;
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

void list_dump(struct list *lst) {
    if (lst->head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct lnode *current;
    printf("\nDump:\n");
    for (current = lst->head; current != NULL; current = current->next) {
        printf("  %d\n", current->value);
    }
}

int main() {
    struct list mylist;

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

    list_remove(&mylist, 40);
    list_remove(&mylist, 20);
    list_dump(&mylist);
}



