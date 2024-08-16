#include "stdio.h"
#include "stdlib.h"

#define QUEUE_SIZE 20

/* breadth-first-traversal, using Queue */
/* bft takes O(n) time complexity, where n is number of nodes */

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct Binary_Tree {
    struct node *root;
    int count;

    void (*insert)(struct Binary_Tree *self, int data);

    struct node *(*search)(struct Binary_Tree *self, int data);

    void (*del)(struct Binary_Tree *self);

    void (*breadth_first)(struct Binary_Tree *tree, struct node *root);

};

struct queue {
    int element[20];
    int head;
    int tail;
};

int is_empty(struct queue *self) {
    return self->head == -1;
}

int is_full(struct queue *self) {
    int next = (self->tail + 1) % QUEUE_SIZE;
    return next == self->head;
}

void enqueue(struct queue *self, int data) {
    if (is_full(self)) {
        printf("Queue is full\n");
        return;
    }
    self->tail = (self->tail + 1) % QUEUE_SIZE;
    self->element[self->tail] = data;

    if (self->head == -1)
        self->head = self->tail;
}

int dequeue(struct queue *self) {
    if (is_empty(self)) {
        printf("Queue is empty\n");
        return 0;
    }
    int index = self->head;
    int data = self->element[index];
    if (index == self->tail)
        self->head = -1;
    else
        self->head = (index + 1) % QUEUE_SIZE;

    return data;
}

struct queue *Queue_init() {
    struct queue *new = (struct queue *) malloc(sizeof(*new));
    if (NULL == new) {
        printf("could not create queue\n");
        exit(0);
    }
    new->head = -1;
    new->tail = -1;
    return new;
}

void Queue_del(struct queue *self) {
    free((void *) self);
}


void Binary_Tree_insert(struct Binary_Tree *self, int data) {
    struct node *new = (struct node *) malloc(sizeof(*new));
    struct node *current, *parent;
    if (NULL == new) {
        printf("cannot create node\n");
        exit(0);
    }
    new->data = data;
    if (self->root == NULL) {
        self->root = new;
        self->count++;
    } else {
        current = self->root;
        while (1) {
            parent = current;
            if (data < current->data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = new;
                    self->count++;
                    return;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = new;
                    self->count++;
                    return;
                }
            }
        }
    }
}

/* breadth-first-traversal */
void Binary_Tree_bf(struct Binary_Tree *tree, struct node *root) {
    if (root == NULL)
        return;
    struct queue *my_queue = Queue_init();
    enqueue(my_queue, root->data);

    while (!is_empty(my_queue)) {
        int last = dequeue(my_queue);
        struct node *cur = tree->search(tree, last); // queue can be created for node, just a hack for now
        printf("%d ", last);
        if (cur->left != NULL)
            enqueue(my_queue, cur->left->data);
        if (cur->right != NULL)
            enqueue(my_queue, cur->right->data);
    }
    printf("\n");
    Queue_del(my_queue);
}

struct node *Binary_Tree_search(struct Binary_Tree *self, int data) {
    struct node *current = self->root;
    if (current == NULL) {
        printf("tree is empty!\n");
        return NULL;
    }
    while (1) {
        if (current->data == data) {
            return current;
        } else {
            if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
            if (current == NULL) {
                return NULL;
            }
        }
    }
}

void delete_node(struct node *tnode) {
    if (tnode != NULL) {
        delete_node(tnode->left);
        delete_node(tnode->right);
        free(tnode);
        tnode = NULL;
    }
}

void Binary_Tree_del(struct Binary_Tree *self) {
    struct node *current = self->root;
    if (current != NULL) {
        delete_node(current);
    }
    free((void *) self);
}


struct Binary_Tree *Binary_Tree_init() {
    struct Binary_Tree *tree = (struct Binary_Tree *) malloc(sizeof(*tree));
    tree->root = NULL;
    tree->count = 0;
    tree->insert = &Binary_Tree_insert;
    tree->search = &Binary_Tree_search;
    tree->del = &Binary_Tree_del;
    tree->breadth_first = &Binary_Tree_bf;
    return tree;
}

int main() {
    struct Binary_Tree *tree = Binary_Tree_init();
    if (tree == NULL) {
        printf("tree is NULL\n");
        exit(0);
    }
    tree->insert(tree, 7);
    tree->insert(tree, 5);
    tree->insert(tree, 8);
    tree->insert(tree, 6);
    tree->insert(tree, 1);
    tree->insert(tree, 3);
    tree->insert(tree, 4);

    printf("breadth-first-traversal\n");
    tree->breadth_first(tree, tree->root);

    tree->del(tree);
    return 0;
}