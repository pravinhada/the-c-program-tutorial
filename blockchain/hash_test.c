#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// DJB2 hash function for strings
unsigned long djb2_hash(const char *str, unsigned long hash) {
    //unsigned long hash = 5381; // Initial hash value (a common choice)
    int c;

    // Iterate through the string character by character
    while ((c = *str++)) {
        // hash = hash * 33 + c (simplified to bitwise operations for efficiency)
        hash = ((hash << 5) + hash) + c;
    }

    return hash;
}

int main() {

    srand(time(NULL));
    const unsigned long random_number = (rand() % 10000) + 1;
    printf("Random number: %lu\n", random_number);

    const char *my_string = "Hello, C programming hash!";
    const unsigned long hash_value = djb2_hash(my_string, random_number);

    printf("Original string: \"%s\"\n", my_string);
    printf("DJB2 Hash: %lu\n", hash_value);


    return 0;
}
