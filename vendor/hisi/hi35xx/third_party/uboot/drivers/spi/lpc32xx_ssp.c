#include <common.h>
#include <linux/compat.h>
#include <asm/io.h>
#include <malloc.h>
#include <spi.h>
#include <asm/arch/clk.h>
#define SSP_CR1_SSP_ENABLE 0x0002
#define SSP_SR_TNF 0x0002
#define SSP_SR_RNE 0x0004
