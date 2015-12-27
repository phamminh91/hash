#include "linprobe.h"
#include "fnv.h"
#include <stdio.h>
#include <stdlib.h>

/* linprobe.c - A hash table with linear probing strategy.
 */

HashMap* createHashMap(uint32_t capacity, float loadFactor) {
    // if (capacity < 0) {
    //     printf("Initial capacity must be positive: %d\n", capacity);
    //     exit(1);
    // }

    if (loadFactor < 0) {
        printf("loadFactor must be positive: %.2f\n", loadFactor);
        exit(1);
    }

    if (loadFactor > 1) {
        printf("loadFactor must be smaller than 1: %.2f\n", loadFactor);
        exit(1);
    }

    Entry **entries = (Entry **) calloc(capacity, sizeof(Entry*));

    HashMap *hmap = malloc(sizeof(HashMap));

    hmap->size = 0;
    hmap->capacity = capacity;
    hmap->loadFactor = loadFactor;
    hmap->entries = entries;

    return hmap;
}

/* Constructor and destructor */
void destroyHashMap(HashMap *hmap) {
    if (hmap) {
        // TODO: improve
        for (int i = 0; i < hmap->capacity; i++) {
            // printf("freeing entries[%d]..\n", i);
            Entry *entry = hmap->entries[i];
            if (!entry)
                continue;
            free(entry->key);
            free(entry->value);
            free(entry);
        }

        // printf("freeing entries..\n");
        free(hmap->entries);
    }
    // printf("freeing map..\n");
    free(hmap);
}

/* If the key is in table, return the corresponding value. Else return null */
void* hget(HashMap *hmap, void *key, uint32_t keySize) {
    if (!hmap)
        return NULL;

    uint32_t hash = fnv1a(key, keySize);
    int slot = hash % hmap->capacity;



    int *retval = malloc(sizeof(int));
    *retval = slot;

    return retval;
}

void hadd(HashMap *hmap, void *key, void *value) {
    if (hmap == NULL) {
        printf("HashMap should not be null");
        exit(1);
    }

    if (hmap->loadFactor * hmap->capacity >= hmap->size) {
        resize(hmap, hmap->size*2);
    }
}

void hremove(HashMap *hmap, void *key) {
}

/* Resize and rehash all elements. O(n) */
void resize(HashMap *hmap, int newSize) {
    Entry **entries = malloc(newSize * sizeof(Entry));
    if (!entries) {
        printf("Out of memory");
        exit(1);
    }
}
