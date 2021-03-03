#include <common.h>
#include <bios_emul.h>
#include <dm.h>
#include <vbe.h>
#include <video.h>
#include <asm/cpu.h>
#include <asm/intel_regs.h>
#include <asm/io.h>
#include <asm/mtrr.h>
#include <asm/arch/cpu.h>
#include <asm/arch/iomap.h>
#include <asm/arch/pch.h>
#include "i915_reg.h"
#define GT_RETRY		1000
#define GT_CDCLK_337		0
#define GT_CDCLK_450		1
#define GT_CDCLK_540		2
#define GT_CDCLK_675		3
