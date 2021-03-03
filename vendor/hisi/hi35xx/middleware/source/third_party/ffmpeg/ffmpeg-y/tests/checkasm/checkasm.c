#include "config.h"
#if CONFIG_LINUX_PERF
# ifndef _GNU_SOURCE
#  define _GNU_SOURCE // for syscall (performance monitoring API)
# endif
#endif
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checkasm.h"
#include "libavutil/common.h"
#include "libavutil/cpu.h"
#include "libavutil/intfloat.h"
#include "libavutil/random_seed.h"
#if HAVE_IO_H
#include <io.h>
#endif
#if HAVE_SETCONSOLETEXTATTRIBUTE
#include <windows.h>
#define COLOR_RED    FOREGROUND_RED
#define COLOR_GREEN  FOREGROUND_GREEN
#define COLOR_YELLOW (FOREGROUND_RED|FOREGROUND_GREEN)
#else
#define COLOR_RED    1
#define COLOR_GREEN  2
#define COLOR_YELLOW 3
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#if !HAVE_ISATTY
#define isatty(fd) 1
#endif
#if ARCH_ARM && HAVE_ARMV5TE_EXTERNAL
#include "libavutil/arm/cpu.h"
#endif
#if CONFIG_AVCODEC
#endif
#if CONFIG_AVFILTER
#endif
#if CONFIG_SWSCALE
#endif
#if CONFIG_AVUTIL
#endif
#if   ARCH_AARCH64
#elif ARCH_ARM
#elif ARCH_PPC
#elif ARCH_X86
#endif
typedef struct CheckasmFuncVersion {
    struct CheckasmFuncVersion *next;
    void *func;
    int ok;
    int cpu;
    CheckasmPerf perf;
} CheckasmFuncVersion;
typedef struct CheckasmFunc {
    struct CheckasmFunc *child[2];
    CheckasmFuncVersion versions;
    uint8_t color; /* 0 = red, 1 = black */
    char name[1];
} CheckasmFunc;
#if HAVE_SETCONSOLETEXTATTRIBUTE
#else
#endif
#if HAVE_SETCONSOLETEXTATTRIBUTE
#else
#endif
static void *checkasm_malloc(size_t size)
{
    void *ptr = calloc(1, size);
    if (!ptr) {
        fprintf(stderr, "checkasm: malloc failed\n");
        destroy_func_tree(state.funcs);
        exit(1);
    }
    return ptr;
}
#define is_red(f) ((f) && !(f)->color)
#if CONFIG_LINUX_PERF
#endif
#if !CONFIG_LINUX_PERF
#ifdef AV_READ_TIME
#else
#endif
#endif
#if CONFIG_LINUX_PERF
#else
#endif
#if CONFIG_LINUX_PERF
#endif
#if ARCH_ARM && HAVE_ARMV5TE_EXTERNAL
#endif
