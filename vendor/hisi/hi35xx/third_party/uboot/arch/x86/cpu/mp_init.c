#include <common.h>
#include <cpu.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <qfw.h>
#include <asm/atomic.h>
#include <asm/cpu.h>
#include <asm/interrupt.h>
#include <asm/lapic.h>
#include <asm/microcode.h>
#include <asm/mp.h>
#include <asm/msr.h>
#include <asm/mtrr.h>
#include <asm/processor.h>
#include <asm/sipi.h>
#include <dm/device-internal.h>
#include <dm/uclass-internal.h>
#include <dm/lists.h>
#include <dm/root.h>
#include <linux/linkage.h>
#if !defined(CONFIG_QEMU) && !defined(CONFIG_HAVE_FSP) && \
#endif
#ifdef CONFIG_QFW
#endif
#ifdef CONFIG_QFW
#endif
