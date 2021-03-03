#include <stdlib.h>
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long u64;
typedef unsigned __int128 u128;

typedef struct {
    u64 h[3];
    u64 s[2];
    u64 r[3];
} poly1305_internal;
#define POLY1305_BLOCK_SIZE 16
