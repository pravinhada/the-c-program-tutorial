#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "blockchain.h"

void clear_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int transaction_count(transaction **transactions) {
    if (transactions == NULL) {
        return 0;
    }
    int count = 0;
    while (*transactions != NULL) {
        (*transactions)++;
        count++;
    }
    return count;
}

void create_new_transaction(transaction **txn) {
    // this is added to clear the input buffer
    clear_buffer();

    char s[20];
    char r[20];
    //char *receiver;
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

    if (txn == NULL) {
        printf("Transactions count is: %d\n", transaction_count(txn));
        transaction **t_list = malloc(sizeof(transaction));
        if (t_list == NULL) {
            return;
        }
        t_list[0] = t;
        txn = t_list;
    } else {
        printf("Transactions count is: %d\n", transaction_count(txn));
        txn = realloc(txn, (transaction_count(txn) + 1) * sizeof(transaction));
        if (txn == NULL) return;
        txn[transaction_count(txn) + 1] = t;
    }
    printf("Sender: %s\n", t->sender);
    printf("Receiver: %s\n", t->receiver);
    printf("Amount: %f\n", t->amount);

    free(t->sender);
    free(t->receiver);
    free(t);
    free(txn);
}
