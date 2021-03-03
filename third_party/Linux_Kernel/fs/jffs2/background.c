#include <linux/kernel.h>
#include <stdio.h>
#include "nodelist.h"
#include "porting.h"
#if defined(CYGOPT_FS_JFFS2_GCTHREAD)
#define GC_THREAD_FLAG_TRIG 1
#define GC_THREAD_FLAG_STOP 2
#define GC_THREAD_FLAG_HAS_EXIT 4
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
