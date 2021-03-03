#include <common.h>
#include <errno.h>
#include <malloc.h>
#include "membuff.h"
int membuff_free(struct membuff *mb)
{
	return mb->end == mb->start ? 0 :
			(mb->end - mb->start) - 1 - membuff_avail(mb);
}
