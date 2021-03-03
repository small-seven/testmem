#define _GNU_SOURCE
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <errno.h>
#include "modpost.h"
#include "../../include/generated/autoconf.h"
#include "../../include/linux/license.h"
#include "../../include/linux/export.h"
#define PRINTF __attribute__ ((format (printf, 1, 2)))
#define SYMBOL_HASH_SIZE 1024
#define strstarts(str, prefix) (strncmp(str, prefix, strlen(prefix)) == 0)
#define CRC_PFX     VMLINUX_SYMBOL_STR(__crc_)
#define KSYMTAB_PFX VMLINUX_SYMBOL_STR(__ksymtab_)
#if defined(STT_REGISTER) || defined(STT_SPARC_REGISTER)
#ifndef STT_SPARC_REGISTER
#define STT_SPARC_REGISTER STT_REGISTER
#endif
#endif
#ifdef CONFIG_HAVE_UNDERSCORE_SYMBOL_PREFIX
#endif
#define ALL_INIT_DATA_SECTIONS \
#define ALL_EXIT_DATA_SECTIONS \
#define ALL_INIT_TEXT_SECTIONS \
#define ALL_EXIT_TEXT_SECTIONS \
#define ALL_PCI_INIT_SECTIONS	\
#define ALL_XXXINIT_SECTIONS MEM_INIT_SECTIONS
#define ALL_XXXEXIT_SECTIONS MEM_EXIT_SECTIONS
#define ALL_INIT_SECTIONS INIT_SECTIONS, ALL_XXXINIT_SECTIONS
#define ALL_EXIT_SECTIONS EXIT_SECTIONS, ALL_XXXEXIT_SECTIONS
#define DATA_SECTIONS ".data", ".data.rel"
#define TEXT_SECTIONS ".text", ".text.unlikely", ".sched.text", \
#define OTHER_TEXT_SECTIONS ".ref.text", ".head.text", ".spinlock.text", \
#define INIT_SECTIONS      ".init.*"
#define MEM_INIT_SECTIONS  ".meminit.*"
#define EXIT_SECTIONS      ".exit.*"
#define MEM_EXIT_SECTIONS  ".memexit.*"
#define ALL_TEXT_SECTIONS  ALL_INIT_TEXT_SECTIONS, ALL_EXIT_TEXT_SECTIONS, \
#define DEFAULT_SYMBOL_WHITE_LIST					\
#define is_second_extable_reloc(Start, Cur, Sec)			\
#ifndef R_ARM_CALL
#define R_ARM_CALL	28
#endif
#ifndef R_ARM_JUMP24
#define R_ARM_JUMP24	29
#endif
#ifndef	R_ARM_THM_CALL
#define	R_ARM_THM_CALL		10
#endif
#ifndef	R_ARM_THM_JUMP24
#define	R_ARM_THM_JUMP24	30
#endif
#ifndef	R_ARM_THM_JUMP19
#define	R_ARM_THM_JUMP19	51
#endif
#if KERNEL_ELFCLASS == ELFCLASS64
#else
#endif
#if KERNEL_ELFCLASS == ELFCLASS64
#else
#endif
#define SZ 500
#define MODULE_NAME_LEN (64 - sizeof(Elf_Addr))
