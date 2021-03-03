#include <common.h>
#include <bmp_layout.h>
#include <command.h>
#include <env.h>
#include <errno.h>
#include <fs.h>
#include <fdt_support.h>
#include <image.h>
#include <nand.h>
#include <sata.h>
#include <spi.h>
#include <spi_flash.h>
#include <splash.h>
#include <usb.h>
#ifdef CONFIG_SPI_FLASH
#else
#endif
#ifdef CONFIG_CMD_NAND
#else
#endif
#ifdef CONFIG_USB_STORAGE
#ifndef CONFIG_DM_USB
#endif
#else
#endif
#ifdef CONFIG_SATA
#else
#endif
#ifdef CONFIG_CMD_UBIFS
#else
#endif
#define SPLASH_SOURCE_DEFAULT_FILE_NAME		"splash.bmp"
#ifdef CONFIG_FIT
#endif /* CONFIG_FIT */
#ifdef CONFIG_FIT
#endif
