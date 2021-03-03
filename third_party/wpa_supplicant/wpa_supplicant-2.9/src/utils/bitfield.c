#include "includes.h"
#include "common.h"
#include "bitfield.h"
struct bitfield * bitfield_alloc(size_t max_bits)
{
	struct bitfield *bf;

	bf = os_zalloc(sizeof(*bf) + (max_bits + 7) / 8);
	if (bf == NULL)
		return NULL;
	bf->bits = (u8 *) (bf + 1);
	bf->max_bits = max_bits;
	return bf;
}
void bitfield_free(struct bitfield *bf)
{
	os_free(bf);
}
