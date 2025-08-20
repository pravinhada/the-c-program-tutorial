#pragma once

#define DEFAULT_SENDER  "santoshi"
#define DEFAULT_RECEIVER  "xxxxx"
#define DEFAULT_REWARD  6.25

typedef struct {
    char *sender;
    char *receiver;
    float amount;
    char *created_date;
} transaction;

typedef struct {
    transaction **data;
    int size;
} transactions;

struct block {
    int block_id;
    unsigned long block_hash;
    unsigned long prev_hash;
    char *nonce;
    struct block *next_block;
    transactions *transactions;
};

typedef struct {
    struct block *head_block;
    struct block *tail_block;
    int blocks_size;
} blockchain;

blockchain *create_blockchain(blockchain *chains);

void cleanup_blockchain(blockchain *blockchain);

void cleanup_block(struct block *head_block);

void cleanup_transaction(transactions *txn);

void mine_new_block(blockchain *blockchain);

void view_blockchain(const blockchain *blockchain);

unsigned long generate_block_hash();

void create_new_transaction(transactions *txn);

void view_transaction(transactions txn);

void submit_transactions(transactions *txn, const blockchain *blockchain);
