#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lnode {
    char *text;
    struct lnode *next;
};

struct pylist {
    struct lnode *head;
    struct lnode *tail;
    int count;
};

/* Constructor - lst = list() */
struct pylist *pylist_new() {
    struct pylist *p = malloc(sizeof(*p));
    p->head = NULL;
    p->tail = NULL;
    p->count = 0;
    return p;
}

/* Destructor - del(lst) */
void pylist_del(struct pylist *self) {
    struct lnode *cur, *next;
    cur = self->head;
    while (cur) {
        free(cur->text);
        next = cur->next;
        free(cur);
        cur = next;
    }
    free((void *) self);
}

/* print(lst) */
void pylist_print(struct pylist *self) {
    if (self->head != NULL && self->tail != NULL) {
        struct lnode *current = self->head;
        printf("[");
        while (current != NULL) {
            printf("'%s'%s", current->text, (current == self->tail) ? "" : ", ");
            current = current->next;
        }
        printf("]\n");
    }
}

/* len(lst) */
int pylist_len(const struct pylist *self) {
    return self->count;
}

/* lst.append("Hello world") */
void pylist_append(struct pylist *self, char *str) {
    struct lnode *node = malloc(sizeof(struct lnode));
    char *value = malloc(sizeof(strlen(str)));
    strcpy(value, str);
    node->text = value;
    node->next = NULL;

    if (self->count == 0) {
        self->head = node;
        self->tail = node;
    } else {
        struct lnode *current = self->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
        self->tail = node;
    }
    self->count++;
}

/* lst.index("Hello world") - if not found -1 */
int pylist_index(struct pylist *self, char *str) {
    struct lnode *current = self->head;
    int i = 0;
    while (current != NULL) {
        if (strcmp(current->text, str) == 0)
            return i;
        current = current->next;
        i++;
    }
    return -1;
}

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);  /* Internal */

    struct pylist *lst = pylist_new();
    pylist_append(lst, "Hello world");
    pylist_print(lst);
    pylist_append(lst, "Catch phrase");
    pylist_print(lst);
    pylist_append(lst, "Brian");
    pylist_print(lst);
    printf("Length = %d\n", pylist_len(lst));
    printf("Brian? %d\n", pylist_index(lst, "Brian"));
    printf("Bob? %d\n", pylist_index(lst, "Bob"));
    pylist_del(lst);
}