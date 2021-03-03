#if !defined(CONFIG_SPL_BUILD)
#include <common.h>
#include <env.h>
#include <dm.h>
#include <env_internal.h>
#include <i2c.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/sys_proto.h>
#include <asm/unaligned.h>
#include <net.h>
#include <errno.h>
#include <g_dnl.h>
#include "factoryset.h"
#define EEPR_PG_SZ		0x80
#define EEPROM_FATORYSET_OFFSET	0x400
#define OFF_PG            EEPROM_FATORYSET_OFFSET/EEPR_PG_SZ
#define fact_get_char(i) *((char *)&eeprom_buf[i])
#if CONFIG_IS_ENABLED(DM_I2C)
#endif
#if defined(CONFIG_DFU_OVER_USB)
#endif
#if CONFIG_IS_ENABLED(DM_I2C)
#else
#endif
#if CONFIG_IS_ENABLED(DM_I2C)
#else
#endif
#if CONFIG_IS_ENABLED(DM_I2C)
#else
#endif
#if CONFIG_IS_ENABLED(TARGET_GIEDI) || CONFIG_IS_ENABLED(TARGET_DENEB)
#endif
#if defined(CONFIG_DFU_OVER_USB)
#endif
#if defined(CONFIG_VIDEO)
#endif
#ifdef CONFIG_AM33XX
#else
#endif
#if CONFIG_IS_ENABLED(TARGET_GIEDI) || CONFIG_IS_ENABLED(TARGET_DENEB)
#endif
#endif /* defined(CONFIG_SPL_BUILD) */
