#include <common.h>
#include <charset.h>
#include <command.h>
#include <dm.h>
#include <efi_loader.h>
#include <efi_selftest.h>
#include <env.h>
#include <errno.h>
#include <linux/libfdt.h>
#include <linux/libfdt_env.h>
#include <mapmem.h>
#include <memalign.h>
#include <asm-generic/sections.h>
#include <linux/linkage.h>
#if !CONFIG_IS_ENABLED(GENERATE_ACPI_TABLE)
#endif /* !CONFIG_IS_ENABLED(GENERATE_ACPI_TABLE) */
#if CONFIG_IS_ENABLED(GENERATE_ACPI_TABLE)
#else
#endif /* GENERATE_ACPI_TABLE */
#ifdef CONFIG_CMD_BOOTEFI_HELLO
#endif
#ifdef CONFIG_CMD_BOOTEFI_SELFTEST
#endif /* CONFIG_CMD_BOOTEFI_SELFTEST */
#ifdef CONFIG_CMD_BOOTEFI_SELFTEST
#endif
#ifdef CONFIG_SYS_LONGHELP
#ifdef CONFIG_CMD_BOOTEFI_HELLO
#endif
#ifdef CONFIG_CMD_BOOTEFI_SELFTEST
#endif
#endif
