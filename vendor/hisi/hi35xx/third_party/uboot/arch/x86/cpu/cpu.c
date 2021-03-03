#include <common.h>
#include <acpi_s3.h>
#include <command.h>
#include <cpu_func.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <syscon.h>
#include <asm/acpi.h>
#include <asm/acpi_table.h>
#include <asm/control_regs.h>
#include <asm/coreboot_tables.h>
#include <asm/cpu.h>
#include <asm/lapic.h>
#include <asm/microcode.h>
#include <asm/mp.h>
#include <asm/mrccache.h>
#include <asm/msr.h>
#include <asm/mtrr.h>
#include <asm/post.h>
#include <asm/processor.h>
#include <asm/processor-flags.h>
#include <asm/interrupt.h>
#include <asm/tables.h>
#include <linux/compiler.h>
#ifdef CONFIG_BOOTSTAGE_STASH
#endif
#ifdef CONFIG_HAVE_ACPI_RESUME
#endif
#if !defined(CONFIG_SYS_COREBOOT) && !defined(CONFIG_EFI_STUB)
#ifdef CONFIG_HAVE_ACPI_RESUME
#endif
#ifdef CONFIG_GENERATE_ACPI_TABLE
#endif
#endif
#ifdef CONFIG_SMP
#else
#endif
#ifndef CONFIG_EFI_STUB
#ifdef CONFIG_ENABLE_MRC_CACHE
#endif
#ifdef CONFIG_SEABIOS
#endif
#ifdef CONFIG_HAVE_ACPI_RESUME
#ifdef CONFIG_HAVE_FSP
#endif /* CONFIG_HAVE_FSP */
#endif /* CONFIG_HAVE_ACPI_RESUME */
#endif
