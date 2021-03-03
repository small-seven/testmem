#include <common.h>
#include <cpu_func.h>
#if !(defined(CONFIG_FIT) && defined(CONFIG_OF_LIBFDT))
#error "CONFIG_FIT and CONFIG_OF_LIBFDT are required for auto-update feature"
#endif
#if defined(CONFIG_UPDATE_TFTP) && !defined(CONFIG_MTD_NOR_FLASH)
#error "CONFIG_UPDATE_TFTP and !CONFIG_MTD_NOR_FLASH needed for legacy behaviour"
#endif
#include <command.h>
#include <env.h>
#include <flash.h>
#include <net.h>
#include <net/tftp.h>
#include <malloc.h>
#include <dfu.h>
#include <errno.h>
#include <mtd/cfi_flash.h>
#define UPDATE_FILE_ENV		"updatefile"
#ifndef CONFIG_UPDATE_LOAD_ADDR
#define CONFIG_UPDATE_LOAD_ADDR	0x100000
#endif
#ifndef CONFIG_UPDATE_TFTP_MSEC_MAX
#define CONFIG_UPDATE_TFTP_MSEC_MAX	100
#endif
#ifndef CONFIG_UPDATE_TFTP_CNT_MAX
#define CONFIG_UPDATE_TFTP_CNT_MAX	0
#endif
#ifdef CONFIG_MTD_NOR_FLASH
#endif
#ifdef CONFIG_MTD_NOR_FLASH
#if defined(CONFIG_SYS_FLASH_PROTECTION)
#else
#endif
#endif
#ifdef CONFIG_MTD_NOR_FLASH
#endif
