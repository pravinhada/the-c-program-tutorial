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
        struct lnode *current = lst->tail;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
        lst->tail = current->next;
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

    mynode = list_find(&mylist, 42);
    if (mynode == NULL) {
        printf("Did not find 42\n");
    } else {
        printf("Looked for 42, found %d\n", mynode->value);
    }

    mynode = list_find(&mylist, 30);
    if (mynode == NULL || mynode->value != 30) {
        printf("Did not find 30\n");
    } else {
        printf("Found 30\n");
    }

    list_add(&mylist, 40);
    list_dump(&mylist);

}

