#include <common.h>
#include <debug_uart.h>
#include <efi.h>
#include <efi_api.h>
#include <errno.h>
#include <ns16550.h>
#include <asm/cpu.h>
#include <asm/io.h>
#include <linux/err.h>
#include <linux/types.h>
#ifndef CONFIG_X86
#error "This file needs to be ported for use on architectures"
#endif
void *memcpy(void *dest, const void *src, size_t size)
{
	unsigned char *dptr = dest;
	const unsigned char *ptr = src;
	const unsigned char *end = src + size;

	while (ptr < end)
		*dptr++ = *ptr++;

	return dest;
}
void *memset(void *inptr, int ch, size_t size)
{
	char *ptr = inptr;
	char *end = ptr + size;

	while (ptr < end)
		*ptr++ = ch;

	return ptr;
}
#ifdef CONFIG_EFI_STUB_32BIT
	typedef void (*func_t)(int bist, int unused, ulong info)
		__attribute__((regparm(3)));

	((func_t)addr)(0, 0, info);
#else
	cpu_call32(cs32, CONFIG_SYS_TEXT_BASE, info);
#endif
}
#ifdef CONFIG_EFI_STUB_64BIT
#endif
#ifdef CONFIG_EFI_STUB_64BIT
#ifdef DEBUG
#endif
#endif
#ifdef DEBUG
#endif
