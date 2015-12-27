#ifndef HASH_LINPROBE
#define HASH_LINPROBE

#include <stdint.h>

#define DEFAULT_CAPACITY 64
#define DEFAULT_LOAD_FACTOR 0.5f

typedef struct HashMap HashMap;
typedef struct Entry Entry;

struct HashMap {
    uint32_t size;      /* Number of entries */
    uint32_t capacity;  /* Maximum number of entries, must be a power of 2 */
    float loadFactor;   /* When the current factor is larger the loadFactor, resize the table */
    Entry **entries;    /* Store the entries set */
};

struct Entry {
    void* key;
    void* value;
};

/* Constructor and destructor */
HashMap* createHashMap(uint32_t capacity, float loadFactor);
void destroyHashMap(HashMap *t);

/* If the key is in table, return the corresponding value. Else return null */
void* hget(HashMap *t, void *key, uint32_t keySize);
void hadd(HashMap *t, void *key, void *value);
void hremove(HashMap *t, void *key);


#endif
