#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode {
    char *data;
    struct lnode *next;
};

struct ListIter {
    struct lnode *current;

    struct lnode *(*next)(struct ListIter *self);

    void (*del)(struct ListIter *self);
};

struct LinkedList {
    struct lnode *head;
    struct lnode *tail;
    int count;

    void (*append)(struct LinkedList *self, const char *data);

    void (*prepend)(struct LinkedList *self, const char *data);

    void (*remove)(struct LinkedList *self, const char *keyword);

    void (*clean)(struct LinkedList *self);

    int (*length)(const struct LinkedList *self);

    void (*display)(const struct LinkedList *self);

    struct lnode *(*find)(const struct LinkedList *self, const char *keyword);

    void (*reverse)(struct LinkedList *self);

    struct ListIter *(*iter)(const struct LinkedList *self);
};

/* complexity of O(n) time to add new data in worst case */
void __LinkedList_append(struct LinkedList *self, const char *data) {
    struct lnode *new = malloc(sizeof(*new));
    char *new_data = malloc(sizeof(*new_data));
    strcpy(new_data, data);
    new->data = new_data;
    new->next = NULL;

    if (self->head == NULL) {
        self->head = new;
        self->tail = new;
    } else {
        struct lnode *cur = self->head;
        while (cur->next != NULL)
            cur = cur->next;

        cur->next = new;
        self->tail = new;
    }
    self->count++;
}

/* this should be constant time complexity O(n), since it add at the beginning */
void __LinkedList_prepend(struct LinkedList *self, const char *data) {
    struct lnode *new = malloc(sizeof(*new));
    char *new_data = malloc(sizeof(*new_data));

    strcpy(new_data, data);
    new->data = new_data;

    if (self->head == NULL) {
        self->head = new;
        self->tail = new;
        new->next = NULL;
    } else {
        new->next = self->head;
        self->head = new;
    }
    self->count++;
}

/* this is in an order of O(n) complexity */
void __LinkedList_remove(struct LinkedList *self, const char *keyword) {
    if (self->head == NULL) return;

    struct lnode *cur = self->head;
    if (strcmp(cur->data, keyword) == 0) {
        self->head = cur->next;
        free(cur->data);
        free(cur);
    } else {
        for (struct lnode *prev = cur; cur->next != NULL; prev = cur, cur = cur->next) {
            if (strcmp(cur->data, keyword) == 0) {
                prev->next = cur->next;
                free(cur->data);
                free(cur);
                break;
            }
        }
    }

    self->count--;
}

void __LinkedList_clean(struct LinkedList *self) {
    struct lnode *cur = self->head;

    while (cur != NULL) {
        free(cur->data);
        struct lnode *next = cur->next;
        free(cur);
        cur = next;
    }
    free(self);
}

int __LinkedList_length(const struct LinkedList *self) {
    return self->count;
}

void __LinkedList_display(const struct LinkedList *self) {
    printf("Displaying content of LinkedList:\n");
    const struct lnode *cur = self->head;
    while (cur != NULL) {
        printf("%s\n", cur->data);
        cur = cur->next;
    }
}

/* complexity of O(n) to search in worse case */
struct lnode *__LinkedList_find(const struct LinkedList *self, const char *keyword) {
    struct lnode *cur = self->head;
    while (cur->next != NULL) {
        if (strcmp(cur->data, keyword) == 0)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

/* O(n) time to reverse */
void __LinkedList_reverse(struct LinkedList *self) {
    struct lnode *prev = NULL;
    struct lnode *cur = self->head;

    while (cur != NULL) {
        struct lnode *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    self->head = prev;
}

struct lnode *__ListIter_next(struct ListIter *self) {
    struct lnode *result = self->current;
    if (result == NULL) return NULL;
    self->current = self->current->next;
    return result;
}

void __ListIter_del(struct ListIter *self) {
    free(self);
}

struct ListIter *__List_Iter(const struct LinkedList *self) {
    struct ListIter *new = malloc(sizeof(*new));
    new->current = self->head;
    new->next = &__ListIter_next;
    new->del = &__ListIter_del;
    return new;
}

void print_reverse(const struct lnode *node) {
    if (node != NULL) {
        print_reverse(node->next);
        printf("%s\n", node->data);
    }
}

struct LinkedList *__LinkedList_new() {
    struct LinkedList *new = malloc(sizeof(*new));
    new->head = NULL;
    new->tail = NULL;
    new->append = &__LinkedList_append;
    new->prepend = &__LinkedList_prepend;
    new->clean = &__LinkedList_clean;
    new->length = &__LinkedList_length;
    new->display = &__LinkedList_display;
    new->find = &__LinkedList_find;
    new->reverse = &__LinkedList_reverse;
    new->remove = &__LinkedList_remove;
    new->iter = &__List_Iter;
    return new;
}


int main() {
    struct LinkedList *list = __LinkedList_new();
    list->append(list, "this");
    list->append(list, "is");
    list->append(list, "c");
    list->append(list, "linked list");
    list->append(list, "data structure");

    printf("total element of linkedlist: %d\n", list->length(list));
    list->display(list);

    const struct lnode *search = list->find(list, "linked list");
    if (NULL != search)
        printf("found element: %s\n", search->data);
    else
        printf("not found\n");

    printf("reversing list: \n");
    list->reverse(list);
    list->prepend(list, "A");
    list->remove(list, "data structure");
    list->display(list);

    printf("total element in linkedlist is %d\n", list->length(list));

    printf("iterating the list:\n");
    struct ListIter *iter = list->iter(list);
    while (1) {
        const struct lnode *cur = iter->next(iter);
        if (cur == NULL) break;
        printf("%s\n", cur->data);
    }

    printf("Reversing the link list:\n");
    print_reverse(list->head);
    iter->del(iter);
    list->clean(list);
}