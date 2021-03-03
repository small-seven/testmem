#include <common.h>
#include <dm.h>
#include <errno.h>
#include <reset-uclass.h>
#include <stm32_rcc.h>
#include <asm/io.h>
#define RCC_CL 0x4
static int stm32_reset_free(struct reset_ctl *reset_ctl)
{
	return 0;
}
