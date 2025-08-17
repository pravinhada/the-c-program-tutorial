#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "blockchain.h"

int main() {
    printf("This is blockchain Program! Your default reward is: %f\n", DEFAULT_REWARD);
    blockchain *my_blockchain = NULL;
    transactions txn = {NULL, 0};
    int input = 0;
    char ch[1];
    do {
        printf("Blockchain Demo: \n");
        printf("1. Create a new blockchain \n");
        printf("2. Add a new transaction \n");
        printf("3. Mine a new blockchain \n");
        printf("4. View a blockchain \n");
        printf("5. View open transactions \n");
        printf("0. Exit \n");
        printf("Enter your choice: ");
        scanf("%s", ch);
        if (!isdigit(ch[0])) {
            printf("Please enter a number between 0 and 5.\n");
            return 1;
        }
        input = atoi(ch);
        if (input == 1) {
            my_blockchain = create_blockchain(my_blockchain);
        } else if (input == 2) {
            txn = create_new_transaction(txn);
        } else if (input == 3) {
            mine_new_block(my_blockchain);
        } else if (input == 4) {
            view_blockchain(my_blockchain);
        } else if (input == 5) {
            view_transaction(txn);
        }
    } while (input != 0);
    cleanup_blockchain(my_blockchain);
    cleanup_transaction(txn);
    return 0;
}
