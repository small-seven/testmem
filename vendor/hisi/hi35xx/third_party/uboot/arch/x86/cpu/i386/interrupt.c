#include <common.h>
#include <dm.h>
#include <efi_loader.h>
#include <irq_func.h>
#include <asm/control_regs.h>
#include <asm/i8259.h>
#include <asm/interrupt.h>
#include <asm/io.h>
#include <asm/lapic.h>
#include <asm/processor-flags.h>
#define DECLARE_INTERRUPT(x) \
#if CONFIG_IS_ENABLED(X86_64)
#else
#endif
#ifndef CONFIG_EFI_APP
#ifdef CONFIG_I8259_PIC
#endif
#ifdef CONFIG_APIC
#endif
#endif
