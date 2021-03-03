#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <pch.h>
#include <asm/cpu.h>
#include <asm/cpu_common.h>
#include <asm/intel_regs.h>
#include <asm/io.h>
#include <asm/lapic.h>
#include <asm/lpc_common.h>
#include <asm/microcode.h>
#include <asm/msr.h>
#include <asm/mtrr.h>
#include <asm/pci.h>
#include <asm/post.h>
#include <asm/processor.h>
#include <asm/arch/model_206ax.h>
#include <asm/arch/pch.h>
#include <asm/arch/sandybridge.h>
#define PCH_EHCI0_TEMP_BAR0 0xe8000000
#define PCH_EHCI1_TEMP_BAR0 0xe8000400
#define PCH_XHCI_TEMP_BAR0  0xe8001000
