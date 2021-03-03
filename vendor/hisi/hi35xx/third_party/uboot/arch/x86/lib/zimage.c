#include <common.h>
#include <env.h>
#include <irq_func.h>
#include <malloc.h>
#include <asm/acpi_table.h>
#include <asm/io.h>
#include <asm/ptrace.h>
#include <asm/zimage.h>
#include <asm/byteorder.h>
#include <asm/bootm.h>
#include <asm/bootparam.h>
#ifdef CONFIG_SYS_COREBOOT
#include <asm/arch/timestamp.h>
#endif
#include <linux/compiler.h>
#include <linux/libfdt.h>
#define DEFAULT_SETUP_BASE	0x90000
#define COMMAND_LINE_OFFSET	0x9000
#define HEAP_END_OFFSET		0x8e00
#define COMMAND_LINE_SIZE	2048
#ifdef CONFIG_INTEL_MID
#endif
#ifdef CONFIG_GENERATE_ACPI_TABLE
#endif
#ifdef CONFIG_EFI_STUB
#endif
