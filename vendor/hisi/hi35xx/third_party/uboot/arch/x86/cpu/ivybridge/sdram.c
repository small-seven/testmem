#include <common.h>
#include <errno.h>
#include <fdtdec.h>
#include <init.h>
#include <malloc.h>
#include <net.h>
#include <rtc.h>
#include <spi.h>
#include <spi_flash.h>
#include <syscon.h>
#include <sysreset.h>
#include <asm/cpu.h>
#include <asm/processor.h>
#include <asm/gpio.h>
#include <asm/global_data.h>
#include <asm/intel_regs.h>
#include <asm/mrccache.h>
#include <asm/mrc_common.h>
#include <asm/mtrr.h>
#include <asm/pci.h>
#include <asm/report_platform.h>
#include <asm/arch/me.h>
#include <asm/arch/pei_data.h>
#include <asm/arch/pch.h>
#include <asm/post.h>
#include <asm/arch/sandybridge.h>
#define CMOS_OFFSET_MRC_SEED		152
#define CMOS_OFFSET_MRC_SEED_S3		156
#define CMOS_OFFSET_MRC_SEED_CHK	160
