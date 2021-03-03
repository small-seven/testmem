#define __io
#include <common.h>
#include <asm/io.h>
#include "biosemui.h"
#ifndef CONFIG_X86EMU_RAW_IO
#endif
#undef DEBUG_IO_ACCESS
#ifdef DEBUG_IO_ACCESS
#define debug_io(fmt, ...)	printf(fmt, ##__VA_ARGS__)
#else
#define debug_io(x, b...)
#endif
#ifdef CONFIG_X86EMU_RAW_IO
#else
#endif
#if !defined(CONFIG_X86EMU_RAW_IO)
#define IS_TIMER_PORT(port) (0x40 <= port && port <= 0x43)
#define IS_CMOS_PORT(port)  (0x70 <= port && port <= 0x71)
#define IS_VGA_PORT(port)   (0x3C0 <= port && port <= 0x3DA)
#define IS_PCI_PORT(port)   (0xCF8 <= port && port <= 0xCFF)
#define IS_SPKR_PORT(port)  (port == 0x61)
#ifdef __KERNEL__
#else
#endif
#endif
#if !defined(CONFIG_X86EMU_RAW_IO)
#endif
#if !defined(CONFIG_X86EMU_RAW_IO)
#endif
#if !defined(CONFIG_X86EMU_RAW_IO)
#endif
#if !defined(CONFIG_X86EMU_RAW_IO)
#endif
#if !defined(CONFIG_X86EMU_RAW_IO)
#endif
#if !defined(CONFIG_X86EMU_RAW_IO)
#endif
