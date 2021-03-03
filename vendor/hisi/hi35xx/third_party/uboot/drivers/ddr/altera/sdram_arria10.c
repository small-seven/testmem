#include <common.h>
#include <cpu_func.h>
#include <errno.h>
#include <fdtdec.h>
#include <malloc.h>
#include <wait_bit.h>
#include <watchdog.h>
#include <asm/io.h>
#include <asm/arch/fpga_manager.h>
#include <asm/arch/misc.h>
#include <asm/arch/reset_manager.h>
#include <asm/arch/sdram.h>
#include <linux/kernel.h>
#define ARRIA10_SDR_ACTIVATE_FAWBANK	(0x1)
#define ARRIA_DDR_CONFIG(A, B, C, R) \
#define DDR_CONFIG_ELEMENTS	ARRAY_SIZE(ddr_config)
#define DDR_REG_SEQ2CORE        0xFFD0507C
#define DDR_REG_CORE2SEQ        0xFFD05078
#define DDR_READ_LATENCY_DELAY	40
#define DDR_SIZE_2GB_HEX	0x80000000
#define IO48_MMR_DRAMSTS	0xFFCFA0EC
#define IO48_MMR_NIOS2_RESERVE0	0xFFCFA110
#define IO48_MMR_NIOS2_RESERVE1	0xFFCFA114
#define IO48_MMR_NIOS2_RESERVE2	0xFFCFA118
#define SEQ2CORE_MASK		0xF
#define CORE2SEQ_INT_REQ	0xF
#define SEQ2CORE_INT_RESP_BIT	3
#define FW_MPU_FPGA_ADDRESS \
#define SOCFPGA_SDR_FIREWALL_MPU_FPGA_ADDRESS_OFFSET(ADDR) \
#define SOCFPGA_SDR_FIREWALL_L3_ADDRESS_OFFSET(ADDR) \
