#include <common.h>
#include <bootretry.h>
#include <cli.h>
#include <command.h>
#include <console.h>
#include <dm.h>
#include <edid.h>
#include <errno.h>
#include <i2c.h>
#include <malloc.h>
#include <asm/byteorder.h>
#include <linux/compiler.h>
#include <u-boot/crc.h>
#if defined(CONFIG_SYS_I2C_NOPROBES)
#if defined(CONFIG_SYS_I2C) || defined(CONFIG_I2C_MULTI_BUS)
#define GET_BUS_NUM	i2c_get_bus_num()
#define COMPARE_BUS(b,i)	(i2c_no_probes[(i)].bus == (b))
#define COMPARE_ADDR(a,i)	(i2c_no_probes[(i)].addr == (a))
#define NO_PROBE_ADDR(i)	i2c_no_probes[(i)].addr
#else		/* single bus */
#define GET_BUS_NUM	0
#define COMPARE_BUS(b,i)	((b) == 0)	/* Make compiler happy */
#define COMPARE_ADDR(a,i)	(i2c_no_probes[(i)] == (a))
#define NO_PROBE_ADDR(i)	i2c_no_probes[(i)]
#endif	/* defined(CONFIG_SYS_I2C) */
#endif
#define DISP_LINE_LEN	16
#ifdef CONFIG_DM_I2C
#define DEFAULT_ADDR_LEN	(-1)
#else
#define DEFAULT_ADDR_LEN	1
#endif
#ifdef CONFIG_DM_I2C
#ifdef CONFIG_I2C_SET_DEFAULT_BUS_NUM
#endif
#endif
#if !defined(CONFIG_SYS_I2C) && !defined(CONFIG_DM_I2C) && !defined(CONFIG_I2C_HIBVT)
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#if !defined(CONFIG_SYS_I2C_FRAM)
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#if !defined(CONFIG_SYS_I2C_FRAM)
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_BOOT_RETRY_TIME
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_SYS_EEPROM_PAGE_WRITE_DELAY_MS
#endif
#if defined(CONFIG_SYS_I2C_NOPROBES)
#endif	/* NOPROBES */
#ifdef CONFIG_DM_I2C
#endif
#if defined(CONFIG_SYS_I2C_NOPROBES)
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#if defined(CONFIG_SYS_I2C_NOPROBES)
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#if defined(CONFIG_CMD_SDRAM)
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#endif
#if defined(CONFIG_I2C_EDID)
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#endif /* CONFIG_I2C_EDID */
#ifdef CONFIG_DM_I2C
#endif
#if defined(CONFIG_SYS_I2C) || defined(CONFIG_DM_I2C)
#ifdef CONFIG_DM_I2C
#else
#ifndef CONFIG_SYS_I2C_DIRECT_BUS
#endif
#endif
#ifdef CONFIG_DM_I2C
#else
#ifndef CONFIG_SYS_I2C_DIRECT_BUS
#endif
#endif
#endif
#if defined(CONFIG_SYS_I2C) || defined(CONFIG_I2C_MULTI_BUS) || \
#ifdef CONFIG_DM_I2C
#else
#endif
#if defined(CONFIG_SYS_I2C)
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#endif  /* defined(CONFIG_SYS_I2C) */
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_I2C_HIBVT
#else
#if defined(CONFIG_DM_I2C)
#elif defined(CONFIG_SYS_I2C)
#else
#endif
#endif /* CONFIG_I2C_HIBVT */
#if defined(CONFIG_SYS_I2C) || defined(CONFIG_DM_I2C)
#endif
#if defined(CONFIG_SYS_I2C) || \
#endif  /* CONFIG_I2C_MULTI_BUS */
#if defined(CONFIG_I2C_EDID)
#endif  /* CONFIG_I2C_EDID */
#ifdef CONFIG_DM_I2C
#endif
#if defined(CONFIG_CMD_SDRAM)
#endif
#ifdef CONFIG_NEEDS_MANUAL_RELOC
#endif
#ifdef CONFIG_SYS_LONGHELP
#if defined(CONFIG_SYS_I2C) || defined(CONFIG_DM_I2C)
#endif
#if defined(CONFIG_SYS_I2C) || \
#endif  /* CONFIG_I2C_MULTI_BUS */
#if defined(CONFIG_I2C_EDID)
#endif  /* CONFIG_I2C_EDID */
#ifdef CONFIG_DM_I2C
#endif
#if defined(CONFIG_CMD_SDRAM)
#endif
#endif
