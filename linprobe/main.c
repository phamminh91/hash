#include <stdio.h>
#include <string.h>
#include "fnv.h"
#include "linprobe.h"

int main(int argc, char **argv) {
    char a[] = "hello";
    char b[] = "hell";
    char c[] = "hello1";

    printf("fnv(\"hello\") : %010u\n", fnv1a(a, (uint32_t) strlen(a)));
    printf("fnv(\"hell\")  : %010u\n", fnv1a(a, (uint32_t) strlen(b)));
    printf("fnv(\"hello1\"): %010u\n", fnv1a(a, (uint32_t) strlen(c)));

    /* Test hashmap construction */
    printf("\nLinear probing hash table test:\n");

    printf("  1. Create hash map\n");
    HashMap *hmap = createHashMap(64, 0.5f);
    printf("  2. Destroy hash map\n");
    destroyHashMap(hmap);

    /* Test add */

    /* Test remove */

    /* Test get */
    printf("  3. Test get\n");
    for (int i = 0; i < 10; i++) {
        int *value = (int *)hget(hmap, (void *)&i, (uint32_t)sizeof(int));
        if (value)
            printf("    Get(%d): %d\n", i, *value);
        else
            printf("    Get(%d): NULL\n", i);
    }

    printf("\nTest finished\n");

    return 0;
}
