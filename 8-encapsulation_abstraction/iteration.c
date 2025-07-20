#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MapEntry {
    char *key;  /* public */
    int value;  /* public */
    struct MapEntry *__prev;
    struct MapEntry *__next;
};

struct MapIter {
    struct MapEntry *__current;

    struct MapEntry *(*next)(struct MapIter *self);

    void (*del)(struct MapIter *self);
};

struct Map {
    /* Attributes */
    struct MapEntry *__head;
    struct MapEntry *__tail;
    int __count;

    /* Methods */
    void (*put)(struct Map *self, char *key, int value);

    int (*get)(struct Map *self, char *key, int def);

    int (*size)(const struct Map *self);

    void (*dump)(const struct Map *self);

    struct MapIter *(*iter)(const struct Map *self);

    void (*del)(struct Map *self);
};

void __Map_del(struct Map *self) {
    struct MapEntry *cur = self->__head;
    while (cur) {
        free(cur->key);
        /* value is just part of the struct */
        struct MapEntry *next = cur->__next;
        free(cur);
        cur = next;
    }
    free(self);
}

void __MapIter_del(struct MapIter *self) {
    free(self);
}

void __Map_dump(const struct Map *self) {
    printf("Object Map count=%d\n", self->__count);
    for (const struct MapEntry *cur = self->__head; cur != NULL; cur = cur->__next) {
        printf("  %s=%d\n", cur->key, cur->value);
    }
}

struct MapEntry *__Map_find(struct Map *self, char *key) {
    if (self == NULL || key == NULL) return NULL;
    for (struct MapEntry *cur = self->__head; cur != NULL; cur = cur->__next) {
        if (strcmp(key, cur->key) == 0) return cur;
    }
    return NULL;
}

int __Map_get(struct Map *self, char *key, int def) {
    struct MapEntry *retval = __Map_find(self, key);
    if (retval == NULL) return def;
    return retval->value;
}

int __Map_size(const struct Map *self) {
    return self->__count;
}

void __Map_put(struct Map *self, char *key, int value) {
    struct MapEntry *new;
    char *new_key;
    if (key == NULL) return;

    struct MapEntry *old = __Map_find(self, key);
    if (old != NULL) {
        old->value = value;
        return;
    }

    new = malloc(sizeof(*new));
    if (!new) {
        fprintf(stderr, "Memory allocation failed for new MapEntry\n");
        exit(EXIT_FAILURE);  // Handle malloc failure
    }
    new_key = malloc(strlen(key) + 1);
    if (!new_key) {
        fprintf(stderr, "Memory allocation failed for new_key\n");
        exit(EXIT_FAILURE);  // Handle malloc failure
    }
    strcpy(new_key, key);
    new->key = new_key;
    new->value = value;
    new->__next = NULL;

    if (__Map_size(self) == 0) {
        self->__head = new;
        self->__tail = new;
        self->__head->__prev = NULL;
    } else {
        struct MapEntry *curr;
        for (curr = self->__head; curr->__next != NULL; curr = curr->__next);
        new->__prev = curr;
        curr->__next = new;
    }
    self->__count++;
}

struct MapEntry *__MapIter_next(struct MapIter *self) {
    struct MapEntry *cur = self->__current;
    if (cur == NULL) return NULL;
    self->__current = self->__current->__next;
    return cur;
}

struct MapIter *__Map_iter(const struct Map *self) {
    struct MapIter *iter = malloc(sizeof(*iter));
    if (!iter) {
        fprintf(stderr, "Memory allocation failed for new MapIter\n");
        exit(EXIT_FAILURE);  // Handle malloc failure
    }
    iter->__current = self->__head;
    iter->next = &__MapIter_next;
    iter->del = &__MapIter_del;
    return iter;
}

struct Map *Map_new() {
    struct Map *p = malloc(sizeof(*p));
    if (!p) {
        fprintf(stderr, "Memory allocation failed for new Map\n");
        exit(EXIT_FAILURE);  // Handle malloc failure
    }

    p->__head = NULL;
    p->__tail = NULL;
    p->__count = 0;
    p->put = &__Map_put;
    p->get = &__Map_get;
    p->size = &__Map_size;
    p->dump = &__Map_dump;
    p->del = &__Map_del;
    p->iter = &__Map_iter;
    return p;
}

int main(void) {
    struct Map *map = Map_new();

    /* Make sure we see all output up to an error */
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("Map test\n");
    map->put(map, "z", 8);
    map->put(map, "z", 1);
    map->put(map, "y", 2);
    map->put(map, "b", 3);
    map->put(map, "a", 4);
    map->dump(map);

    printf("size=%d\n", map->size(map));

    printf("z=%d\n", map->get(map, "z", 42));
    printf("x=%d\n", map->get(map, "x", 42));

    printf("\nIterate\n");
    struct MapIter *iter = map->iter(map);
    while (1) {
        struct MapEntry *cur = iter->next(iter);
        if (cur == NULL) break;
        printf("%s=%d\n", cur->key, cur->value);
    }
    iter->del(iter);

    map->del(map);
}