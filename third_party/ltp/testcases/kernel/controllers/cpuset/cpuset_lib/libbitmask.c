#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "bitmask.h"
#include "tst_minmax.h"
#define bitsperlong (8 * sizeof(unsigned long))
#define howmany(x,y) (((x)+((y)-1))/(y))
#define longsperbits(n) howmany(n, bitsperlong)
void bitmask_free(struct bitmask *bmp)
{
	if (bmp == 0)
		return;
	free(bmp->maskp);
	bmp->maskp = (unsigned long *)0xdeadcdef;	/* double free tripwire */
	free(bmp);
}
#define HEXCHUNKSZ 32		/* hex binary format shows 32 bits per chunk */
#define HEXCHARSZ 8		/* hex ascii format has up to 8 chars per chunk */
