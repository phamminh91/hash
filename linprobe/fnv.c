#include "fnv.h"

uint32_t fnv1a(void *x, uint32_t keySize) {
    uint32_t hash = FNV_OFFSET_BASIS;
    char *ptr = (char *) x;
    for (int i = keySize; i > 0; --i) {
        hash = (hash ^ (*ptr++)) * FNV_PRIME;
    }
    return (uint32_t)hash;
}
