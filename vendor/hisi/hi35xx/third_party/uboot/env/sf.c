#include <common.h>
#include <dm.h>
#include <env.h>
#include <env_internal.h>
#include <malloc.h>
#include <spi.h>
#include <spi_flash.h>
#include <search.h>
#include <errno.h>
#include <dm/device-internal.h>
#include <u-boot/crc.h>
#ifndef CONFIG_SPL_BUILD
#define CMD_SAVEENV
#define INITENV
#endif
#ifdef CONFIG_ENV_OFFSET_REDUND
#ifdef CMD_SAVEENV
#endif
#endif /* CONFIG_ENV_OFFSET_REDUND */
#ifdef CONFIG_DM_SPI_FLASH
#else
#endif
#if defined(CONFIG_ENV_OFFSET_REDUND)
#ifdef CMD_SAVEENV
#endif /* CMD_SAVEENV */
#else
#ifdef CMD_SAVEENV
#endif /* CMD_SAVEENV */
#endif
#if CONFIG_ENV_ADDR != 0x0
#endif
#if defined(INITENV) && (CONFIG_ENV_ADDR != 0x0)
#endif
#ifdef CMD_SAVEENV
#endif
#if defined(INITENV) && (CONFIG_ENV_ADDR != 0x0)
#endif
