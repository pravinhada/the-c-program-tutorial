#pragma once

#define DEFAULT_SENDER  "santoshi"
#define DEFAULT_RECEIVER  "xxxxx"
#define DEFAULT_REWARD  6.25

struct transaction {
    char *sender;
    char *receiver;
    float amount;
    char *created_date;
};

struct block {
    int block_id;
    unsigned long block_hash;
    unsigned long prev_hash;
    char *nonce;
    struct block *next_block;
    struct transaction *transaction[10];
};

typedef struct {
    struct block *head_block;
    struct block *tail_block;
    int blocks_size;
} blockchain;

blockchain *create_blockchain(blockchain *blockchain);

void cleanup_blockchain(blockchain *blockchain);

void cleanup_block(struct block *head_block);

void cleanup_transaction(struct transaction *transaction);

void mine_new_block(blockchain *blockchain);

void view_blockchain(const blockchain *blockchain);

unsigned long generate_block_hash();
