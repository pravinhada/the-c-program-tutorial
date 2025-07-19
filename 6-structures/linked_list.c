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

void list_add(struct list *lst, const int value) {
    /* Append the value to the end of the linked list. */
    struct lnode *node = malloc(sizeof(struct lnode));
    node->value = value;
    node->next = NULL;

    if ((lst->head == NULL && lst->tail == NULL) || lst->head == NULL) {
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

struct lnode *list_find(const struct list *lst, const int value) {
    struct lnode *current = lst->head;
    while (current != NULL) {
        if (current->value == value)
            return current;
        current = current->next;
    }
    return NULL;
}

void list_dump(const struct list *lst) {
    printf("\nDump:\n");
    for (const struct lnode *cur = lst->head; cur != NULL; cur = cur->next) {
        printf("  %d\n", cur->value);
    }
}

void list_del(const struct list *lst) {
    struct lnode *cur = lst->head;
    while (cur != NULL) {
        struct lnode *del = cur;
        cur = cur->next;
        free(del);
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

    const struct lnode *mynode = list_find(&mylist, 42);
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

    list_del((&mylist));
}

