#ifndef HASH_HS
#define HASH_HS

typedef struct Hashtable Hashtable;
typedef struct Entry Entry;

struct Entry {
    unsigned int size;
    unsigned int capacity;
}

struct HashTable {
    void* key;
    void* value;
}

HashTable* hinit(unsigned int capacity);
void hdestroy(HashTable *t);

void* hget(HashTable *t, void *key);
void* hadd(HashTable *t, void *key, void *value);
void* hrem(HashTable *t, void *key);

#endif
