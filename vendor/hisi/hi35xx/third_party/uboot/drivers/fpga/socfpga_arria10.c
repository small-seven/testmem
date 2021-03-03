#include <asm/io.h>
#include <asm/arch/fpga_manager.h>
#include <asm/arch/reset_manager.h>
#include <asm/arch/system_manager.h>
#include <asm/arch/sdram.h>
#include <asm/arch/misc.h>
#include <altera.h>
#include <asm/arch/pinmux.h>
#include <common.h>
#include <dm/ofnode.h>
#include <errno.h>
#include <fs_loader.h>
#include <wait_bit.h>
#include <watchdog.h>
#define CFGWDTH_32	1
#define MIN_BITSTREAM_SIZECHECK	230
#define ENCRYPTION_OFFSET	69
#define COMPRESSION_OFFSET	229
#define FPGA_TIMEOUT_MSEC	1000  /* timeout in ms */
#define FPGA_TIMEOUT_CNT	0x1000000
#define DEFAULT_DDR_LOAD_ADDRESS	0x400
#ifdef CONFIG_FS_LOADER
#endif
