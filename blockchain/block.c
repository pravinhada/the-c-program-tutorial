#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "blockchain.h"

blockchain *create_blockchain(blockchain *my_blockchain) {
    if (my_blockchain != NULL) {
        printf("Blockchain already initialized!\n");
        return my_blockchain;
    }
    printf("Creating genesis block...\n");
    blockchain *chain = malloc(sizeof(blockchain));
    if (chain == NULL) {
        printf("Failed to allocate memory for blockchain.\n");
        return NULL;
    }
    struct block *genesis = malloc(sizeof(struct block));
    if (genesis == NULL) {
        printf("Failed to allocate memory for genesis block.\n");
        return NULL;
    }
    genesis->block_id = 1;
    genesis->block_hash = generate_block_hash();
    genesis->next_block = NULL;

    chain->head_block = genesis;
    chain->tail_block = genesis;
    chain->blocks_size = 1;
    return chain;
}

void mine_new_block(blockchain *blockchain) {
    if (blockchain == NULL) {
        printf("Current blockchain is empty!\n");
        return;
    }
    struct block *new_block = malloc(sizeof(*new_block));
    if (new_block == NULL) {
        printf("Failed to allocate memory for block.\n");
        return;
    }
    new_block->block_id = blockchain->blocks_size + 1;
    new_block->block_hash = generate_block_hash();
    new_block->next_block = NULL;
    new_block->prev_hash = blockchain->tail_block->block_hash;

    blockchain->tail_block->next_block = new_block;
    blockchain->tail_block = new_block;
    blockchain->blocks_size++;
}

void cleanup_blockchain(blockchain *blockchain) {
    printf("cleaning up blockchain data structure..\n");
    if (blockchain != NULL) {
        cleanup_block(blockchain->head_block);
        free(blockchain);
        blockchain = NULL;
        return;
    }
    printf("No blockchain is created!\n");
}

unsigned long generate_block_hash() {
    int c;
    srand(time(NULL));
    unsigned long hash = (rand() % 10000) + 1;
    char *str = "my blockchain demo";
    while ((c = *str++)) {
        // hash = hash * 33 + c (simplified to bitwise operations for efficiency)
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

void cleanup_block(struct block *head_block) {
    if (head_block == NULL) {
        return;
    }
    struct block *current_block = head_block;
    while (current_block != NULL) {
        struct block *next_block = current_block->next_block;
        free(current_block);
        current_block = next_block;
    }
}

void view_blockchain(const blockchain *blockchain) {
    if (blockchain == NULL) {
        return;
    }
    struct block *current_block = blockchain->head_block;
    while (current_block != NULL) {
        printf("Block ID: %i\n", current_block->block_id);
        printf("Block hash: %lu\n", current_block->block_hash);
        printf("Nonce: %lu\n", current_block->prev_hash);
        printf("\n");
        current_block = current_block->next_block;
    }
}

void cleanup_transaction(struct transaction *transaction) {
    if (transaction == NULL) {
        return;
    }
    free(transaction);
}
