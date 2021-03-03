#include <common.h>
#include <asm/io.h>
#include <asm/types.h>
#include <mach/tlb.h>
#include <mach/ddr.h>
#if CONFIG_SYS_SDRAM_SIZE <= SZ_64M
#define MSCC_RAM_TLB_SIZE   SZ_64M
#define MSCC_ATTRIB2   MMU_REGIO_INVAL
#elif CONFIG_SYS_SDRAM_SIZE <= SZ_128M
#define MSCC_RAM_TLB_SIZE   SZ_64M
#define MSCC_ATTRIB2   MMU_REGIO_RW
#elif CONFIG_SYS_SDRAM_SIZE <= SZ_256M
#define MSCC_RAM_TLB_SIZE   SZ_256M
#define MSCC_ATTRIB2   MMU_REGIO_INVAL
#elif CONFIG_SYS_SDRAM_SIZE <= SZ_512M
#define MSCC_RAM_TLB_SIZE   SZ_256M
#define MSCC_ATTRIB2   MMU_REGIO_RW
#else
#define MSCC_RAM_TLB_SIZE   SZ_512M
#define MSCC_ATTRIB2   MMU_REGIO_RW
#endif
#ifdef CONFIG_SOC_LUTON
#endif
#if  CONFIG_SYS_TEXT_BASE == MSCC_FLASH_TO
#endif /* CONFIG_SYS_TEXT_BASE */
#ifdef CONFIG_SOC_LUTON
#else
#if defined(CONFIG_SOC_OCELOT) || defined(CONFIG_SOC_SERVAL)
#endif
#if defined(CONFIG_SOC_JR2) || defined(CONFIG_SOC_SERVALT)
#endif
#endif
