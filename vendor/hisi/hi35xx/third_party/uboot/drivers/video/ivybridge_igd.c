#include <common.h>
#include <bios_emul.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <pci_rom.h>
#include <vbe.h>
#include <asm/intel_regs.h>
#include <asm/io.h>
#include <asm/mtrr.h>
#include <asm/pci.h>
#include <asm/arch/pch.h>
#include <asm/arch/sandybridge.h>
#define GTT_RETRY 1000
