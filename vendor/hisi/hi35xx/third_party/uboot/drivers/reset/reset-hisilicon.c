#include <asm/io.h>
#include <common.h>
#include <dm.h>
#include <dt-bindings/reset/ti-syscon.h>
#include <reset-uclass.h>
static int hisi_reset_free(struct reset_ctl *rst)
{
	return 0;
}
