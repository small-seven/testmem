#include <common.h>
#include <dm.h>
#include <errno.h>
#include <reset-uclass.h>
#include <asm/io.h>
#define MAX_RESETS	32
static int bcm6345_reset_free(struct reset_ctl *rst)
{
	return 0;
}
