#include <common.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/spr_misc.h>
#if defined(CONFIG_SPEAR3XX)
#elif defined(CONFIG_SPEAR600)
#endif
#if defined(CONFIG_PL011_SERIAL)
#endif
#if defined(CONFIG_ETH_DESIGNWARE)
#endif
#if defined(CONFIG_DW_UDC)
#endif
#if defined(CONFIG_SYS_I2C_DW)
#endif
#if defined(CONFIG_ST_SMI)
#endif
#if defined(CONFIG_NAND_FSMC)
#endif
#if defined(CONFIG_USB_EHCI_SPEAR)
#endif
#if defined(CONFIG_SPEAR_GPIO)
#endif
#if defined(CONFIG_PL022_SPI)
#endif
#ifdef CONFIG_DISPLAY_CPUINFO
#ifdef CONFIG_SPEAR300
#elif defined(CONFIG_SPEAR310)
#elif defined(CONFIG_SPEAR320)
#elif defined(CONFIG_SPEAR600)
#else
#error CPU not supported in spear platform
#endif
#endif
#if !defined(CONFIG_SPL_BUILD) && defined(CONFIG_NAND_ECC_BCH) && defined(CONFIG_NAND_FSMC)
#endif
