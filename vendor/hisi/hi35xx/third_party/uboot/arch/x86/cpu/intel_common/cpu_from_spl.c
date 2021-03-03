#include <common.h>
#include <dm.h>
#include <errno.h>
#include <handoff.h>
#include <asm/cpu_common.h>
#include <asm/intel_regs.h>
#include <asm/lapic.h>
#include <asm/lpc_common.h>
#include <asm/msr.h>
#include <asm/mtrr.h>
#include <asm/post.h>
#include <asm/microcode.h>
#if CONFIG_IS_ENABLED(HANDOFF) && IS_ENABLED(CONFIG_USE_HOB)
#endif
