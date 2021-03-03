#include <common.h>
#include <command.h>
#include <cpu_func.h>
#include <dm.h>
#include <elf.h>
#include <efi_loader.h>
#include <rtc.h>
#include <u-boot/crc.h>
#if defined(__aarch64__)
#define R_RELATIVE	R_AARCH64_RELATIVE
#define R_MASK		0xffffffffULL
#define IS_RELA		1
#elif defined(__arm__)
#define R_RELATIVE	R_ARM_RELATIVE
#define R_MASK		0xffULL
#elif defined(__i386__)
#define R_RELATIVE	R_386_RELATIVE
#define R_MASK		0xffULL
#elif defined(__x86_64__)
#define R_RELATIVE	R_X86_64_RELATIVE
#define R_MASK		0xffffffffULL
#define IS_RELA		1
#elif defined(__riscv)
#define R_RELATIVE	R_RISCV_RELATIVE
#define R_MASK		0xffULL
#define IS_RELA		1
#if (__riscv_xlen == 32)
#define R_ABSOLUTE	R_RISCV_32
#define SYM_INDEX	8
#elif (__riscv_xlen == 64)
#define R_ABSOLUTE	R_RISCV_64
#define SYM_INDEX	32
#else
#error unknown riscv target
#endif
#else
#error Need to add relocation awareness
#endif
#ifdef CONFIG_EFI_HAVE_RUNTIME_RESET
#endif
#ifdef CONFIG_CMD_POWEROFF
#endif
#ifdef CONFIG_EFI_GET_TIME
#else
#endif
#ifdef CONFIG_EFI_SET_TIME
#endif
#ifdef CONFIG_EFI_SET_TIME
#else
#endif
#ifdef IS_RELA
#else
#endif
#ifdef IS_RELA
#else
#endif
#ifdef R_ABSOLUTE
#ifdef IS_RELA
#endif
#endif
#ifndef IS_RELA
#endif
