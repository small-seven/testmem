#include <common.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <malloc.h>
#include <pch.h>
#include <asm/cpu.h>
#include <asm/intel_regs.h>
#include <asm/io.h>
#include <asm/lapic.h>
#include <asm/lpc_common.h>
#include <asm/pci.h>
#include <asm/arch/model_206ax.h>
#include <asm/arch/pch.h>
#include <asm/arch/sandybridge.h>
#define GPIO_BASE		0x48
#define BIOS_CTRL		0xdc
#define RCBA_AUDIO_CONFIG	0x2030
#define RCBA_AUDIO_CONFIG_HDA	BIT(31)
#define RCBA_AUDIO_CONFIG_MASK	0xfe
#ifndef CONFIG_HAVE_FSP
#define IOBP_RETRY 1000
#endif /* CONFIG_HAVE_FSP */
#ifndef CONFIG_HAVE_FSP
#endif
