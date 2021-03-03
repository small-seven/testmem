#include <common.h>
#include <ata.h>
#include <dm.h>
#include <ide.h>
#include <watchdog.h>
#include <asm/io.h>
#ifdef __PPC__
# define EIEIO		__asm__ volatile ("eieio")
# define SYNC		__asm__ volatile ("sync")
#else
# define EIEIO		/* nothing */
# define SYNC		/* nothing */
#endif
#if defined(CONFIG_SYS_ATA_IDE0_OFFSET)
#endif
#if defined(CONFIG_SYS_ATA_IDE1_OFFSET) && (CONFIG_SYS_IDE_MAXBUS > 1)
#endif
#define IDE_TIME_OUT	2000	/* 2 sec timeout */
#define ATAPI_TIME_OUT	7000	/* 7 sec timeout (5 sec seems to work...) */
#define IDE_SPIN_UP_TIME_OUT 5000 /* 5 sec spin-up timeout */
#ifndef CONFIG_SYS_ATA_PORT_ADDR
#define CONFIG_SYS_ATA_PORT_ADDR(port) (port)
#endif
#ifdef CONFIG_IDE_RESET
#else
#define ide_reset()	/* dummy */
#endif /* CONFIG_IDE_RESET */
#ifdef CONFIG_ATAPI
#if defined(CONFIG_IDE_SWAP_IO)
#else  /* ! CONFIG_IDE_SWAP_IO */
#endif /* CONFIG_IDE_SWAP_IO */
#define ATAPI_DRIVE_NOT_READY	100
#define ATAPI_UNIT_ATTN		10
#define ATAPI_READ_MAX_BYTES	2048	/* we read max 2kbytes */
#define ATAPI_READ_BLOCK_SIZE	2048	/* assuming CD part */
#define ATAPI_READ_MAX_BLOCK	(ATAPI_READ_MAX_BYTES/ATAPI_READ_BLOCK_SIZE)
#ifndef CONFIG_BLK
#endif
#ifdef CONFIG_LBA48
#endif
#endif /* CONFIG_ATAPI */
#ifdef CONFIG_ATAPI
#endif
#ifdef CONFIG_ATAPI
#endif
#ifdef CONFIG_ATAPI
#else
#endif
#ifdef CONFIG_ATAPI
#endif
#ifdef __LITTLE_ENDIAN
#endif /* __LITTLE_ENDIAN */
#ifdef CONFIG_ATAPI
#endif /* CONFIG_ATAPI */
#ifdef __BIG_ENDIAN
#else  /* ! __BIG_ENDIAN */
#endif /* __BIG_ENDIAN */
#ifdef CONFIG_LBA48
#endif /* CONFIG_LBA48 */
#if 0				/* only used to test the powersaving mode,
#endif
#if defined(CONFIG_IDE_AHB)
#else
#endif
#if defined(CONFIG_IDE_AHB)
#else
#endif
#ifdef CONFIG_IDE_PREINIT
#endif /* CONFIG_IDE_PREINIT */
#ifndef CONFIG_ATAPI		/* ATAPI Devices do not set DRDY */
#endif
#ifndef CONFIG_BLK
#endif
#ifndef CONFIG_BLK
#endif
#ifdef CONFIG_BLK
#endif
#if defined(__LITTLE_ENDIAN)
#else
#ifdef __MIPS__
#else
#endif /* !MIPS */
#endif /* __LITTLE_ENDIAN */
#if defined(CONFIG_IDE_SWAP_IO)
#else  /* ! CONFIG_IDE_SWAP_IO */
#if defined(CONFIG_IDE_AHB)
#else
#endif
#endif /* CONFIG_IDE_SWAP_IO */
#if defined(CONFIG_IDE_SWAP_IO)
#else  /* ! CONFIG_IDE_SWAP_IO */
#if defined(CONFIG_IDE_AHB)
#else
#endif
#endif /* CONFIG_IDE_SWAP_IO */
#ifdef CONFIG_BLK
#else
#endif
#ifdef CONFIG_BLK
#endif
#ifdef CONFIG_LBA48
#endif
#ifdef CONFIG_LBA48
#ifdef CONFIG_SYS_64BIT_LBA
#else
#endif
#endif
#ifdef CONFIG_LBA48
#endif
#ifdef CONFIG_BLK
#else
#endif
#ifdef CONFIG_BLK
#endif
#ifdef CONFIG_LBA48
#endif
#ifdef CONFIG_LBA48
#ifdef CONFIG_SYS_64BIT_LBA
#else
#endif
#endif
#ifdef CONFIG_LBA48
#endif
#if defined(CONFIG_OF_IDE_FIXUP)
#endif
#ifdef CONFIG_BLK
#else
#endif
