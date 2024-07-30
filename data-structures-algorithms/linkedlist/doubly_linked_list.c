#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode {
    char *data;
    struct lnode *prev;
    struct lnode *next;
};

struct DoublyLinkedList {
    struct lnode *head;
    struct lnode *tail;
    int count;

    void (*append)(struct DoublyLinkedList *self, char *data);

    void (*prepend)(struct DoublyLinkedList *self, char *data);

    void (*remove)(struct DoublyLinkedList *self, char *keyword);

    void (*clean)(struct DoublyLinkedList *self);

    int (*length)(struct DoublyLinkedList *self);

    void (*display)(struct DoublyLinkedList *self);

    struct lnode *(*find)(struct DoublyLinkedList *self, char *keyword);

    void (*reverse)(struct DoublyLinkedList *self);
};

/* complexity of O(n) time to add new data in worst case */
void __DoublyLinkedList_append(struct DoublyLinkedList *self, char *data) {
    struct lnode *cur, *new_node;

    new_node = malloc(sizeof(*new_node));
    char *new_data = malloc(sizeof(*new_data));
    strcpy(new_data, data);
    new_node->data = new_data;
    new_node->next = NULL;
    new_node->prev = NULL;

    /* first element */
    if (self->head == NULL) {
        self->head = new_node;
        self->tail = new_node;
    } else {
        cur = self->head;
        while (cur->next != NULL)
            cur = cur->next;

        cur->next = new_node;
        new_node->prev = cur;
        self->tail = new_node;
    }
    self->count++;
}

/* this should be constant time complexity O(n), since it add at the beginning */
void __DoublyLinkedList_prepend(struct DoublyLinkedList *self, char *data) {
    struct lnode *new_node = (struct lnode *) malloc(sizeof(*new_node));
    char *new_data = malloc(sizeof(*new_data));

    strcpy(new_data, data);
    new_node->data = new_data;

    if (self->head == NULL) {
        self->head = new_node;
        self->tail = new_node;
        new_node->next = NULL;
        new_node->prev = NULL;
    } else {
        new_node->next = self->head;
        new_node->prev = NULL;
        self->head = new_node;
    }
    self->count++;
}

/* this is in an order of O(n) complexity */
void __DoublyLinkedList_remove(struct DoublyLinkedList *self, char *keyword) {
    if (self->head == NULL) return;

    struct lnode *prev, *cur;

    cur = self->head;
    /* if first node */
    if (strcmp(cur->data, keyword) == 0) {
        self->head = cur->next;
        free(cur->data);
        free(cur);
    } else {
        for (prev = cur; cur->next != NULL; prev = cur, cur = cur->next) {
            if (strcmp(cur->data, keyword) == 0) {
                prev->next = cur->next;
                cur->next->prev = prev;
                free(cur->data);
                free(cur);
                self->count--;
                break;
            }
        }
    }
}

void __DoublyLinkedList_clean(struct DoublyLinkedList *self) {
    struct lnode *cur, *next;
    cur = self->head;

    while (cur != NULL) {
        free(cur->data);
        next = cur->next;
        free(cur);
        cur = next;
    }
    free((void *) self);
}

int __DoublyLinkedList_length(struct DoublyLinkedList *self) {
    return self->count;
}

void __DoublyLinkedList_display(struct DoublyLinkedList *self) {
    printf("Displaying content of DoublyLinkedList:\n");
    struct lnode *cur = self->head;
    while (cur != NULL) {
        printf("(%s) ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

/* complexity of O(n) to search in worse case */
struct lnode *__DoublyLinkedList_find(struct DoublyLinkedList *self, char *keyword) {
    struct lnode *cur = self->head;
    while (cur->next != NULL) {
        if (strcmp(cur->data, keyword) == 0)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

/* O(n) time to reverse, backward */
void __DoublyLinkedList_reverse(struct DoublyLinkedList *self) {
    struct lnode *cur;
    for (cur = self->tail; cur != NULL; cur = cur->prev)
        printf("(%s) ", cur->data);

    printf("\n");
}

struct DoublyLinkedList *__DoublyLinkedList_new() {
    struct DoublyLinkedList *new = (struct DoublyLinkedList *) malloc(sizeof(*new));
    new->head = NULL;
    new->tail = NULL;
    new->append = &__DoublyLinkedList_append;
    new->prepend = &__DoublyLinkedList_prepend;
    new->clean = &__DoublyLinkedList_clean;
    new->length = &__DoublyLinkedList_length;
    new->display = &__DoublyLinkedList_display;
    new->find = &__DoublyLinkedList_find;
    new->reverse = &__DoublyLinkedList_reverse;
    new->remove = &__DoublyLinkedList_remove;
    return new;
}

int main() {
    struct DoublyLinkedList *list = __DoublyLinkedList_new();
    struct lnode *search;
    list->append(list, "a");
    list->append(list, "b");
    list->append(list, "c");
    list->append(list, "d");
    list->append(list, "e");

    printf("total element of DoublyLinkedList: %d\n", list->length(list));
    list->display(list);

    search = list->find(list, "d");
    if (NULL != search)
        printf("found element: %s\n", search->data);
    else
        printf("not found\n");

    printf("reversing list: \n");
    list->reverse(list);

    printf("prepend x\n");
    list->prepend(list, "x");
    list->remove(list, "e");
    printf("append y\n");
    list->append(list, "y");
    list->display(list);

    printf("total element in DoublyLinkedList is %d\n", list->length(list));
    list->clean(list);
}