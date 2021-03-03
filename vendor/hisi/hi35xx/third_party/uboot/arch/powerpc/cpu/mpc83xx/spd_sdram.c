#ifndef CONFIG_MPC83XX_SDRAM
#include <common.h>
#include <cpu_func.h>
#include <vsprintf.h>
#include <asm/processor.h>
#include <asm/io.h>
#include <i2c.h>
#include <spd.h>
#include <asm/mmu.h>
#include <spd_sdram.h>
#if defined(CONFIG_ARCH_MPC8308) || defined(CONFIG_ARCH_MPC831X)
#else
#endif
#if defined(CONFIG_SYS_LB_SDRAM) && defined(CONFIG_SYS_LBC_SDRAM_SIZE)
#endif
#ifdef CONFIG_SPD_EEPROM
#ifndef	CONFIG_SYS_READ_SPD
#define CONFIG_SYS_READ_SPD	i2c_read
#endif
#ifndef SPD_EEPROM_OFFSET
#define SPD_EEPROM_OFFSET	0
#endif
#ifndef SPD_EEPROM_ADDR_LEN
#define SPD_EEPROM_ADDR_LEN     1
#endif
#undef SPD_DEBUG
#ifdef SPD_DEBUG
#endif /* SPD_DEBUG */
#ifdef SPD_DEBUG
#endif
#ifdef CONFIG_SYS_DDRCDR_VALUE
#endif
#ifdef CONFIG_SYS_83XX_DDR_USES_CS0
#else
#endif
#ifdef CONFIG_SYS_DDR_WRITE_DATA_DELAY
#endif
#ifdef CONFIG_SYS_DDR_CPO
#else
#endif
#ifdef CONFIG_SYS_DDR_MODE_WEAK
#endif
#ifndef CONFIG_NEVER_ASSERT_ODT_TO_CPU
#endif
#ifdef CONFIG_SYS_DDR_SDRAM_CLK_CNTL	/* Optional platform specific value */
#endif
#if defined(CONFIG_DDR_ECC)
#endif
#if defined(CONFIG_DDR_2T_TIMING)
#endif
#endif /* CONFIG_SPD_EEPROM */
#if defined(CONFIG_DDR_ECC) && !defined(CONFIG_ECC_INIT_VIA_DDRCONTROLLER)
#if defined(CONFIG_DDR_ECC_INIT_VIA_DMA)
#else
#endif
#endif	/* CONFIG_DDR_ECC */
#endif /* !CONFIG_MPC83XX_SDRAM */
