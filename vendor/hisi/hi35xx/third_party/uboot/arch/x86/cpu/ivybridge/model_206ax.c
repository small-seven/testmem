#include <common.h>
#include <cpu.h>
#include <dm.h>
#include <fdtdec.h>
#include <malloc.h>
#include <asm/cpu.h>
#include <asm/cpu_common.h>
#include <asm/cpu_x86.h>
#include <asm/msr.h>
#include <asm/msr-index.h>
#include <asm/mtrr.h>
#include <asm/processor.h>
#include <asm/speedstep.h>
#include <asm/turbo.h>
#include <asm/arch/model_206ax.h>
#ifdef CONFIG_ENABLE_VMX
#else
#endif
