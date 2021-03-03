#include <common.h>
#include <dm.h>
#include <i2c.h>
#include <fsl_ddr_sdram.h>
#include <fsl_ddr.h>
#ifndef CONFIG_SYS_FSL_DDR_SDRAM_BASE_PHY
#ifdef CONFIG_MPC83xx
#define CONFIG_SYS_FSL_DDR_SDRAM_BASE_PHY CONFIG_SYS_SDRAM_BASE
#else
#define CONFIG_SYS_FSL_DDR_SDRAM_BASE_PHY CONFIG_SYS_DDR_SDRAM_BASE
#endif
#endif
#ifdef CONFIG_PPC
#include <asm/fsl_law.h>
#endif
#if defined(SPD_EEPROM_ADDRESS) || \
#if (CONFIG_SYS_NUM_DDR_CTLRS == 1) && (CONFIG_DIMM_SLOTS_PER_CTLR == 1)
#elif (CONFIG_SYS_NUM_DDR_CTLRS == 1) && (CONFIG_DIMM_SLOTS_PER_CTLR == 2)
#elif (CONFIG_SYS_NUM_DDR_CTLRS == 2) && (CONFIG_DIMM_SLOTS_PER_CTLR == 1)
#elif (CONFIG_SYS_NUM_DDR_CTLRS == 2) && (CONFIG_DIMM_SLOTS_PER_CTLR == 2)
#elif (CONFIG_SYS_NUM_DDR_CTLRS == 3) && (CONFIG_DIMM_SLOTS_PER_CTLR == 1)
#elif (CONFIG_SYS_NUM_DDR_CTLRS == 3) && (CONFIG_DIMM_SLOTS_PER_CTLR == 2)
#endif
#if defined(CONFIG_DM_I2C)
#define DEV_TYPE struct udevice
#else
#define DEV_TYPE struct ludevice
#endif
#define SPD_SPA0_ADDRESS	0x36
#define SPD_SPA1_ADDRESS	0x37
#ifdef CONFIG_DM_I2C
#else
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#ifdef CONFIG_DM_I2C
#else
#endif
#endif
#if defined(CONFIG_DM_I2C)
#else /* Non DM I2C support - will be removed */
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#ifdef SPD_EEPROM_ADDRESS
#elif defined(SPD_EEPROM_ADDRESS1)
#endif
#else
#endif /* SPD_EEPROM_ADDRESSx */
#if defined(CONFIG_DDR_SPD) || defined(CONFIG_SPD_EEPROM)
#ifdef CONFIG_SYS_DDR_RAW_TIMING
#else
#endif
#elif defined(CONFIG_SYS_DDR_RAW_TIMING)
#endif
#ifdef CONFIG_PPC
#endif
#ifdef CONFIG_FSL_DDR_INTERACTIVE
#endif
#ifdef CONFIG_FSL_DDR_SYNC_REFRESH
#endif
#ifdef CONFIG_PPC
#if CONFIG_SYS_NUM_DDR_CTLRS > 3
#endif
#endif
#if !defined(CONFIG_PHYS_64BIT)
#endif
#ifdef CONFIG_SYS_FSL_OTHER_DDR_NUM_CTRLS
#endif
