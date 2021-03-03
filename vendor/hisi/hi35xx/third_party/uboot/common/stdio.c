#include <config.h>
#include <common.h>
#include <dm.h>
#include <errno.h>
#include <stdarg.h>
#include <malloc.h>
#include <stdio_dev.h>
#include <serial.h>
#include <splash.h>
#if defined(CONFIG_SYS_I2C)
#include <i2c.h>
#endif
#include <dm/device-internal.h>
#if defined(CONFIG_SPLASH_SCREEN) && !defined(CONFIG_SYS_DEVICE_NULLDEV)
#define	CONFIG_SYS_DEVICE_NULLDEV	1
#endif
#if CONFIG_IS_ENABLED(SYS_STDIO_DEREGISTER)
#define	CONFIG_SYS_DEVICE_NULLDEV	1
#endif
#ifdef CONFIG_SYS_DEVICE_NULLDEV
#endif
#ifdef CONFIG_SYS_DEVICE_NULLDEV
#endif
#ifdef CONFIG_DM_VIDEO
#endif
#ifdef CONFIG_DM_VIDEO
#endif
#if CONFIG_IS_ENABLED(SYS_STDIO_DEREGISTER)
#endif /* CONFIG_IS_ENABLED(SYS_STDIO_DEREGISTER) */
#if defined(CONFIG_NEEDS_MANUAL_RELOC)
#endif /* CONFIG_NEEDS_MANUAL_RELOC */
#ifdef CONFIG_DM_KEYBOARD
#endif
#ifdef CONFIG_SYS_I2C
#else
#endif
#ifdef CONFIG_DM_VIDEO
#ifndef CONFIG_SYS_CONSOLE_IS_IN_ENV
# ifndef CONFIG_DM_KEYBOARD
# endif
#endif /* !CONFIG_SYS_CONSOLE_IS_IN_ENV */
#if defined(CONFIG_SPLASH_SCREEN) && defined(CONFIG_CMD_BMP)
#endif /* CONFIG_SPLASH_SCREEN && CONFIG_CMD_BMP */
#else
# if defined(CONFIG_LCD)
# endif
# if defined(CONFIG_VIDEO) || defined(CONFIG_CFB_CONSOLE)
# endif
#endif /* CONFIG_DM_VIDEO */
#if defined(CONFIG_KEYBOARD) && !defined(CONFIG_DM_KEYBOARD)
#endif
#ifdef CONFIG_USB_TTY
#endif
#ifdef CONFIG_NETCONSOLE
#endif
#ifdef CONFIG_JTAG_CONSOLE
#endif
#ifdef CONFIG_CBMEM_CONSOLE
#endif
