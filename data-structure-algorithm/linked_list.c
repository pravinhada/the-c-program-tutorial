#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode {
    char *data;
    struct lnode *next;
};

struct LinkedList {
    struct lnode *head;
    struct lnode *tail;
    int count;

    void (*add)(struct LinkedList *self, char *data);
    void (*del)(struct LinkedList *self);
    int (*size)(struct LinkedList *self);
    void (*display)(struct LinkedList *self);
    struct lnode *(*find)(struct LinkedList *self, char *keyword);
};

/* complexity of O(n) time to add new data in worst case */
void __LinkedList_add(struct LinkedList *self, char *data) {
    struct lnode *cur, *new;

    new = malloc(sizeof(*new));
    char *new_data = malloc(sizeof(*new_data));
    strcpy(new_data, data);
    new->data = new_data;
    new->next = NULL;

    if (self->head == NULL) {
        self->head = new;
        self->tail = new;
    } else {
        cur = self->head;
        while (cur->next != NULL)
            cur = cur->next;
        
        cur->next = new;
        self->tail = new;
    }
    self->count++;
}

void __LinkedList_del(struct LinkedList *self) {

    struct lnode *cur, *next;
    cur = self->head;

    while(cur!= NULL) {
        free(cur->data);
        next = cur->next;
        free(cur);
        cur = next;
    }
    free((void*)self);
}

int __LinkedList_size(struct LinkedList *self) {
    return self->count;
}

void __LinkedList_display(struct LinkedList *self) {
    printf("Displaying content of LinkedList:\n");
    struct lnode *cur = self->head;
    while (cur != NULL) {
        printf("%s\n", cur->data);
        cur = cur->next;
    }
}

/* complexity of O(n) to search in worse case */
struct lnode *__LinkedList_find(struct LinkedList *self, char *keyword) {
    struct lnode *cur = self->head;
    while(cur->next != NULL) {
        if (strcmp(cur->data, keyword) == 0)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

struct LinkedList *__LinkedList_new() {
    struct LinkedList *new = malloc(sizeof(*new));
    new->head = NULL;
    new->tail = NULL;
    new->add = &__LinkedList_add;
    new->del = &__LinkedList_del;
    new->size = &__LinkedList_size;
    new->display = &__LinkedList_display;
    new->find = &__LinkedList_find;
    return new;
}

int main() {
    struct LinkedList *list = __LinkedList_new();
    struct lnode *search;
    list->add(list, "this");
    list->add(list, "is");
    list->add(list, "c");
    list->add(list, "linked list");
    list->add(list, "data structure");

    printf("total element of linkedlist: %d\n", list->count);
    list->display(list);

    search = list->find(list, "java");
    if (NULL != search) 
        printf("found element: %s\n", search->data);
    else   
        printf("not found\n");

    list->del(list);
}