#include "stdio.h"
#include "stdlib.h"

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

};

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
    } else {
        current = self->root;
        while (1) {
            parent = current;
            if (data < current->data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = new;
                    return;
                }
            } else {
                current = current->right;
                if (current == NULL) {
                    parent->right = new;
                    return;
                }
            }
        }
    }
    self->count++;
}

struct node *Binary_Tree_search(struct Binary_Tree *self, int data) {
    struct node *current = self->root;
    if (current == NULL) {
        printf("tree is empty!\n");
        return NULL;
    }
    while (1) {
        if (current->data == data) {
            printf("found data: %d\n", data);
            return current;
        } else {
            if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
            if (current == NULL) {
                printf("not found\n");
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


void in_order_traverse(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        in_order_traverse(root->left);
        in_order_traverse(root->right);
    }
}

struct Binary_Tree *Binary_Tree_init() {
    struct Binary_Tree *tree = (struct Binary_Tree *) malloc(sizeof(*tree));
    tree->root = NULL;
    tree->count = 0;
    tree->insert = &Binary_Tree_insert;
    tree->search = &Binary_Tree_search;
    tree->del = &Binary_Tree_del;
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

    tree->search(tree, 6);
    tree->search(tree, 9);

    in_order_traverse(tree->root);

    tree->del(tree);
    return 0;
}