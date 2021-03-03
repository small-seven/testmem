#include <config.h>
#include <common.h>
#include <api_public.h>
#if defined(CONFIG_CMD_USB) && defined(CONFIG_USB_STORAGE)
#include <usb.h>
#endif
#define DEBUG
#undef DEBUG
#ifdef DEBUG
#define debugf(fmt, args...) do { printf("%s(): ", __func__); printf(fmt, ##args); } while (0)
#else
#define debugf(fmt, args...)
#endif
#define errf(fmt, args...) do { printf("ERROR @ %s(): ", __func__); printf(fmt, ##args); } while (0)
#define ENUM_IDE	0
#define ENUM_USB	1
#define ENUM_SCSI	2
#define ENUM_MMC	3
#define ENUM_SATA	4
#define ENUM_MAX	5
#ifndef CONFIG_SYS_MMC_MAX_DEVICE
#define CONFIG_SYS_MMC_MAX_DEVICE	1
#endif
#if defined(CONFIG_IDE)
#endif
#if defined(CONFIG_CMD_MMC)
#endif
#if defined(CONFIG_SATA)
#endif
#if defined(CONFIG_SCSI)
#endif
#if defined(CONFIG_CMD_USB) && defined(CONFIG_USB_STORAGE)
#endif
#ifdef CONFIG_BLK
#else
#endif	/* defined(CONFIG_BLK) */
#ifdef CONFIG_BLK
#else
#endif	/* defined(CONFIG_BLK) */
