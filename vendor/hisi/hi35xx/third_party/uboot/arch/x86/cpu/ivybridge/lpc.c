#include <common.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <rtc.h>
#include <pci.h>
#include <asm/intel_regs.h>
#include <asm/interrupt.h>
#include <asm/io.h>
#include <asm/ioapic.h>
#include <asm/lpc_common.h>
#include <asm/pci.h>
#include <asm/arch/pch.h>
#define NMI_OFF				0
#define ENABLE_ACPI_MODE_IN_COREBOOT	0
#define TEST_SMM_FLASH_LOCKDOWN		0
#ifdef CONFIG_SERIRQ_CONTINUOUS_MODE
#else
#endif
#if DEBUG_PERIODIC_SMIS
#endif
