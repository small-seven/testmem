#define TEST 1
#include "libavutil/random_seed.c"
#undef printf
#define N 256
#define F 2
#include <stdio.h>
typedef uint32_t (*random_seed_ptr_t)(void);

int main(void)
{
    int i, j, rsf, retry;
    uint32_t seeds[N];
    random_seed_ptr_t random_seed[F] = {av_get_random_seed, get_generic_seed};
