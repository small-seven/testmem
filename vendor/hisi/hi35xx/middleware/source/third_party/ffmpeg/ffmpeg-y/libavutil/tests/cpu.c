#include <stdio.h>
#include "config.h"
#include "libavutil/cpu.h"
#include "libavutil/avstring.h"
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#if !HAVE_GETOPT
#include "compat/getopt.c"
#endif
#if   ARCH_AARCH64
#elif ARCH_ARM
#elif ARCH_PPC
#elif ARCH_X86
#endif
