#ifndef HASH_FNV
#define HASH_FNV

#include <stdint.h>

#define FNV_OFFSET_BASIS 2166136261U
#define FNV_PRIME 16777619U

// Return the fnv-1a 32bit hash
uint32_t fnv1a(void *x, uint32_t keySize);

#endif
