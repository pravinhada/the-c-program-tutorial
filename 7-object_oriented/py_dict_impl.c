#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dnode {
    char *key;
    char *value;
    struct dnode *next;
};

struct pydict {
    struct dnode *head;
    struct dnode *tail;
    int count;
};

/* Constructor - dct = dict() */
struct pydict *pydict_new() {
    struct pydict *p = malloc(sizeof(*p));
    p->head = NULL;
    p->tail = NULL;
    p->count = 0;
    return p;
}

/* Destructor - del(dct) */
void pydict_del(struct pydict *self) {
    struct dnode *cur, *next;
    cur = self->head;
    while (cur) {
        free(cur->key);
        free(cur->value);
        next = cur->next;
        free(cur);
        cur = next;
    }
    free((void *) self);
}

/* print(dct) */
/* {'z': 'W', 'y': 'B', 'c': 'C', 'a': 'D'} */
void pydict_print(struct pydict *self) {
    if (self->count > 0) {
        struct dnode *current = self->head;
        printf("{");
        while (current != NULL) {
            printf("'%s': '%s'%s", current->key, current->value, (current == self->tail) ? "" : ", ");
            current = current->next;
        }
        printf("}\n");
    }
}

int pydict_len(const struct pydict *self) {
    return self->count;
}

/* find a node - used in get and put */
struct dnode *pydict_find(struct pydict *self, char *key) {
    struct dnode *current = self->head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}

/* x.get(key) - Returns NULL if not found */
char *pydict_get(struct pydict *self, char *key) {
    struct dnode *node = pydict_find(self, key);
    return NULL != node ? node->value : NULL;
}

/* x[key] = value; Insert or replace the value associated with a key */
void pydict_put(struct pydict *self, char *key, char *value) {
    struct dnode *node = malloc(sizeof(*node));
    char *k = malloc(sizeof(key));
    char *val = malloc(sizeof(value));
    strcpy(k, key);
    strcpy(val, value);
    node->key = k;
    node->value = val;
    node->next = NULL;

    if (self->count == 0) {
        self->head = node;
        self->tail = node;
        self->count++;
    } else {
        struct dnode *n = pydict_find(self, key);
        if (n) {
            strcpy(n->value, value);
        } else {
            struct dnode *current;
            for (current = self->head; current->next != NULL; current = current->next);
            current->next = node;
            self->tail = node;
            self->count++;
        }
    }
}

int main(void) {
    struct dnode *cur;
    struct pydict *dct = pydict_new();

    setvbuf(stdout, NULL, _IONBF, 0);  /* Internal */

    pydict_put(dct, "z", "Catch phrase");
    pydict_print(dct);
    pydict_put(dct, "z", "W");
    pydict_print(dct);
    pydict_put(dct, "y", "B");
    pydict_put(dct, "c", "C");
    pydict_put(dct, "a", "D");
    pydict_print(dct);
    printf("Length =%d\n", pydict_len(dct));

    printf("z=%s\n", pydict_get(dct, "z"));
    printf("x=%s\n", pydict_get(dct, "x"));

    printf("\nDump\n");
    for (cur = dct->head; cur != NULL; cur = cur->next) {
        printf("%s=%s\n", cur->key, cur->value);
    }

    pydict_del(dct);
}