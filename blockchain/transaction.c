#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "blockchain.h"

void clear_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void create_new_transaction(transactions *txn) {
    // this is added to clear the input buffer
    clear_buffer();

    char s[20];
    char r[20];
    float amount;

    memset(s, 0, sizeof(s));
    printf("Creating new transaction:\n");
    printf("Enter sender:");
    if (fgets(s, sizeof(s), stdin) != NULL) {
        s[strcspn(s, "\n")] = '\0';
    }

    printf("Enter receiver:");
    if (fgets(r, sizeof(r), stdin) != NULL) {
        r[strcspn(r, "\n")] = '\0';
    }

    transaction *t = malloc(sizeof(transaction));
    if (t == NULL) {
        return;
    }
    t->sender = malloc(20 * sizeof(char));
    if (t->sender == NULL) return;
    strcpy(t->sender, s);

    t->receiver = malloc(20 * sizeof(char));
    if (t->receiver == NULL) return;
    strcpy(t->receiver, r);
    t->amount = 1;

    transaction **tt = realloc(txn->data, (txn->size + 1) * sizeof(transaction *));
    if (!tt) {
        free(t->sender);
        free(t->receiver);
        free(t);
        return;
    };
    txn->data = tt;
    txn->data[txn->size] = t;
    txn->size++;
}

void submit_transactions(transactions *txn, const blockchain *blockchain) {
    printf("Submitting transactions:\n");
    if (txn == NULL) return;
    struct block *tmp = blockchain->tail_block;
    if (tmp == NULL) return;
    tmp->transactions = txn;
    txn = NULL;
}

void cleanup_transaction(transactions *txn) {
    printf("Cleaning up all transactions:\n");
    for (int i = 0; i < txn->size; i++) {
        free(txn->data[i]->sender);
        txn->data[i]->sender = NULL;
        free(txn->data[i]->receiver);
        txn->data[i]->receiver = NULL;
        free(txn->data[i]);
        txn->data[i] = NULL;
    }
    free(txn->data);
    txn->data = NULL;
}

void view_transaction(const transactions txn) {
    for (int i = 0; i < txn.size; i++) {
        printf("transaction[%d]: sender[%s], receiver[%s], amount[%f]\n", i, txn.data[i]->sender, txn.data[i]->receiver,
               txn.data[i]->amount);
    }
}
