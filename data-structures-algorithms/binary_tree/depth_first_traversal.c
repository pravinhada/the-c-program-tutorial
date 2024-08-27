#include "stdio.h"
#include "stdlib.h"

// binary tree depth first
// pre-order-traversal
// in-order-traversal
// post-order-traversal
// binary tree search has O(log n) for all search, insert and delete operation
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

    void (*pre_order)(struct node *self);

    void (*in_order)(struct node *self);

    void (*post_order)(struct node *self);

};

void Binary_Tree_insert(struct Binary_Tree *self, int data) {
    struct node *new = (struct node *) malloc(sizeof(*new));
    struct node *current, *parent;
    if (NULL == new) {
        printf("cannot create node\n");
        exit(0);
    }
    new->data = data;
    new->left = NULL;
    new->right = NULL;
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
                printf("not found: %d\n", data);
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

/* pre-order traversal using recursion */
void pre_order_traverse(struct node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    pre_order_traverse(root->left);
    pre_order_traverse(root->right);
}

/* in-order traversal using recursion */
void in_order_traverse(struct node *root) {
    if (root == NULL)
        return;
    in_order_traverse(root->left);
    printf("%d ", root->data);
    in_order_traverse(root->right);
}

/* post-order traversal using recursion */
void post_order_traverse(struct node *root) {
    if (root == NULL)
        return;
    post_order_traverse(root->left);
    post_order_traverse(root->right);
    printf("%d ", root->data);
}

/* find the minimum value in the tree using recursive */
int min_val(struct node *root) {
    if (NULL == root) 
        return 0;
    
    if (NULL == root->left)
        return root->data;
    
    return min_val(root->left);
}

/* find the maximum depth of tree using recursion */
int max_depth(struct node *root) {
    if (NULL == root)
        return 0;
    
    if (NULL == root->left && NULL == root->right) 
        return 0;

    int leftDepth = 1 + max_depth(root->left);
    int rightDepth = 1 + max_depth(root->right);

    return leftDepth > rightDepth ? leftDepth : rightDepth;
}

/* mirror the tree using recursion */
void mirror(struct node *root) {
    if (NULL == root)
        return;

    mirror(root->left);
    mirror(root->right);

    struct node *temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

struct Binary_Tree *Binary_Tree_init() {
    struct Binary_Tree *tree = (struct Binary_Tree *) malloc(sizeof(*tree));
    tree->root = NULL;
    tree->count = 0;
    tree->insert = &Binary_Tree_insert;
    tree->search = &Binary_Tree_search;
    tree->del = &Binary_Tree_del;
    tree->pre_order = &pre_order_traverse;
    tree->in_order = &in_order_traverse;
    tree->post_order = &post_order_traverse;
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
    tree->insert(tree, 2);
    tree->insert(tree, 3);
    tree->insert(tree, 4);

    tree->search(tree, 6);
    tree->search(tree, 9);

    printf("pre-order-traversal:\n");
    tree->pre_order(tree->root);
    printf("\nin-order-traversal:\n");
    tree->in_order(tree->root);
    printf("\npost-order-traversal:\n");
    tree->post_order(tree->root);
    printf("\n");

    printf("total element: %d\n", tree->count);

    printf("min value: %d\n", min_val(tree->root));

    printf("max depth: %d\n", max_depth(tree->root));

    mirror(tree->root);

    printf("\nin-order-traversal after mirror:\n");
    tree->in_order(tree->root);
    printf("\n");

    tree->del(tree);
    return 0;
}