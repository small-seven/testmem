#include <console.h>
#include <common.h>
#include <cpu_func.h>
#include <zynqmppl.h>
#include <zynqmp_firmware.h>
#include <linux/sizes.h>
#include <asm/arch/sys_proto.h>
#include <memalign.h>
#define DUMMY_WORD	0xffffffff
#define SWAP_NO		1
#define SWAP_DONE	2
#if defined(CONFIG_CMD_FPGA_LOAD_SECURE) && !defined(CONFIG_SPL_BUILD)
#endif
#if defined CONFIG_CMD_FPGA_LOAD_SECURE
#endif
