#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode {
    char *data;
    struct lnode *prev;
    struct lnode *next;
};

struct ListIter {
    struct lnode *current;

    struct lnode *(*next)(struct ListIter *self);

    void (*del)(struct ListIter *self);
};

struct DoublyLinkedList {
    struct lnode *head;
    struct lnode *tail;
    int count;

    void (*append)(struct DoublyLinkedList *self, const char *data);

    void (*prepend)(struct DoublyLinkedList *self, const char *data);

    void (*remove)(struct DoublyLinkedList *self, const char *keyword);

    void (*clean)(struct DoublyLinkedList *self);

    int (*length)(const struct DoublyLinkedList *self);

    void (*display)(const struct DoublyLinkedList *self);

    struct lnode *(*find)(const struct DoublyLinkedList *self, const char *keyword);

    void (*reverse)(const struct DoublyLinkedList *self);

    struct ListIter *(*iter)(const struct DoublyLinkedList *self);
};

/* complexity of O(n) time to add new data in worst case */
void __DoublyLinkedList_append(struct DoublyLinkedList *self, const char *data) {
    struct lnode *new_node = malloc(sizeof(*new_node));
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
        struct lnode *cur = self->head;
        while (cur->next != NULL)
            cur = cur->next;

        cur->next = new_node;
        new_node->prev = cur;
        self->tail = new_node;
    }
    self->count++;
}

/* this should be constant time complexity O(n), since it add at the beginning */
void __DoublyLinkedList_prepend(struct DoublyLinkedList *self, const char *data) {
    struct lnode *new_node = malloc(sizeof(*new_node));
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

/* this is in an order of O(n) complexity, this depends on search function */
void __DoublyLinkedList_remove(struct DoublyLinkedList *self, const char *keyword) {
    struct lnode *result = self->find(self, keyword);
    if (result != NULL) {
        struct lnode *prev = result->prev;
        struct lnode *next = result->next;
        prev->next = next;
        next->prev = prev;
        free(result->data);
        free(result);
        self->count--;
    }
}

void __DoublyLinkedList_clean(struct DoublyLinkedList *self) {
    struct lnode *cur = self->head;

    while (cur != NULL) {
        free(cur->data);
        struct lnode *next = cur->next;
        free(cur);
        cur = next;
    }
    free(self);
}

int __DoublyLinkedList_length(const struct DoublyLinkedList *self) {
    return self->count;
}

void __DoublyLinkedList_display(const struct DoublyLinkedList *self) {
    printf("Displaying content of DoublyLinkedList:\n");
    const struct lnode *cur = self->head;
    while (cur != NULL) {
        printf("(%s) ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

/* complexity of O(n) to search in worse case */
struct lnode *__DoublyLinkedList_find(const struct DoublyLinkedList *self, const char *keyword) {
    struct lnode *cur = self->head;
    while (cur->next != NULL) {
        if (strcmp(cur->data, keyword) == 0)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

/* O(n) time to reverse, backward */
void __DoublyLinkedList_reverse(const struct DoublyLinkedList *self) {
    for (const struct lnode *cur = self->tail; cur != NULL; cur = cur->prev)
        printf("(%s) ", cur->data);

    printf("\n");
}

void __ListIter_del(struct ListIter *self) {
    free(self);
}

struct lnode *__ListIter_next(struct ListIter *self) {
    struct lnode *result = self->current;
    if (result == NULL) return NULL;
    self->current = self->current->next;
    return result;
}

struct ListIter *__List_iter(const struct DoublyLinkedList *self) {
    struct ListIter *new = malloc(sizeof(*new));
    new->current = self->head;
    new->next = &__ListIter_next;
    new->del = &__ListIter_del;
    return new;
}

struct DoublyLinkedList *__DoublyLinkedList_new() {
    struct DoublyLinkedList *new = malloc(sizeof(*new));
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
    new->iter = &__List_iter;
    return new;
}

int main() {
    struct DoublyLinkedList *list = __DoublyLinkedList_new();
    list->append(list, "a");
    list->append(list, "b");
    list->append(list, "c");
    list->append(list, "d");
    list->append(list, "e");

    printf("total element of DoublyLinkedList: %d\n", list->length(list));
    list->display(list);

    const struct lnode *search = list->find(list, "d");
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

    printf("removing c from list\n");
    list->remove(list, "c");
    list->display(list);
    printf("total element in DoublyLinkedList is %d\n", list->length(list));

    printf("iterating list:\n");
    struct ListIter *iter = list->iter(list);
    while (1) {
        struct lnode *cur = iter->next(iter);
        if (cur == NULL) break;
        printf("\t (%s)\n", cur->data);
    }
    iter->del(iter);
    list->clean(list);
}