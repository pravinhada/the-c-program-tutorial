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
    if (NULL == p) {
        printf("could not allocate memory for pylist\n");
        exit(0);
    }
    p->head = NULL;
    p->tail = NULL;
    p->count = 0;
    return p;
}

/* Destructor - del(lst) */
void pylist_del(struct pylist *self) {
    if (self == NULL || self->head == NULL) return;
    struct lnode *cur = self->head;
    while (cur) {
        free(cur->text);
        struct lnode *next = cur->next;
        free(cur);
        cur = next;
    }
    free(self);
}

/* print(lst) */
void pylist_print(const struct pylist *self) {
    if (self == NULL) return;
    if (self->head != NULL && self->tail != NULL) {
        const struct lnode *current = self->head;
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
    if (self == NULL) return 0;
    return self->count;
}

/* lst.append("Hello world") */
void pylist_append(struct pylist *self, const char *str) {
    struct lnode *node = malloc(sizeof(struct lnode));
    char *value = malloc(sizeof(strlen(str)));
    strcpy(value, str);
    node->text = value;
    node->next = NULL;

    if (NULL == node) {
        printf("couldn't allocate memory for node\n");
        exit(0);
    }

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
int pylist_index(const struct pylist *self, const char *str) {
    const struct lnode *current = self->head;
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