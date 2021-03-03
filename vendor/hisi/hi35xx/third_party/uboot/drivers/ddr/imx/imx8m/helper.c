#include <common.h>
#include <spl.h>
#include <asm/io.h>
#include <errno.h>
#include <asm/io.h>
#include <asm/arch/ddr.h>
#include <asm/arch/ddr.h>
#include <asm/arch/lpddr4_define.h>
#include <asm/sections.h>
#define IMEM_LEN 32768 /* byte */
#define DMEM_LEN 16384 /* byte */
#define IMEM_2D_OFFSET	49152
#define IMEM_OFFSET_ADDR 0x00050000
#define DMEM_OFFSET_ADDR 0x00054000
#define DDR_TRAIN_CODE_BASE_ADDR IP2APB_DDRPHY_IPS_BASE_ADDR(0)
#ifdef CONFIG_SPL_OF_CONTROL
#endif
