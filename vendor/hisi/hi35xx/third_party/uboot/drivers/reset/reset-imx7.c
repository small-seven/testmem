#include <asm/io.h>
#include <common.h>
#include <dm.h>
#include <dt-bindings/reset/imx7-reset.h>
#include <dt-bindings/reset/imx8mq-reset.h>
#include <reset-uclass.h>
static int imx7_reset_free(struct reset_ctl *rst)
{
	return 0;
}
