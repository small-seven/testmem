#include <common.h>
#include <ahci.h>
#include <spl.h>
#include <asm/omap_common.h>
#include <asm/arch/omap.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/sys_proto.h>
#include <watchdog.h>
#include <scsi.h>
#include <i2c.h>
#ifdef BOOT_DEVICE_NAND_I2C
#endif
#ifdef BOOT_DEVICE_QSPI_4
#endif
#ifdef CONFIG_TI816X
#endif
#if defined(BOOT_DEVICE_UART) && !defined(CONFIG_SPL_YMODEM_SUPPORT)
#endif
#if defined(BOOT_DEVICE_USB) && !defined(CONFIG_SPL_USB_STORAGE)
#endif
#if defined(BOOT_DEVICE_USBETH) && !defined(CONFIG_SPL_USB_ETHER)
#endif
#if defined(BOOT_DEVICE_CPGMAC) && !defined(CONFIG_SPL_ETH_SUPPORT)
#endif
#if defined(BOOT_DEVICE_DFU) && !defined(CONFIG_SPL_DFU)
#endif
#ifdef CONFIG_OMAP34XX
#else
#ifdef CONFIG_SUPPORT_EMMC_BOOT
#else
#endif
#endif
#if !defined(CONFIG_TI814X) && !defined(CONFIG_TI816X) && \
#endif
#ifdef CONFIG_SPL_BUILD
#ifdef CONFIG_SPL_SERIAL_SUPPORT
#endif
#if defined(CONFIG_SPL_NAND_SUPPORT) || defined(CONFIG_SPL_ONENAND_SUPPORT)
#endif
#if defined(CONFIG_SPL_I2C_SUPPORT) && !defined(CONFIG_DM_I2C)
#endif
#if defined(CONFIG_AM33XX) && defined(CONFIG_SPL_MUSB_NEW_SUPPORT)
#endif
#if defined(CONFIG_HW_WATCHDOG) || defined(CONFIG_WATCHDOG)
#endif
#ifdef CONFIG_AM33XX
#endif
	typedef void __noreturn (*image_entry_noargs_t)(u32 *);
	image_entry_noargs_t image_entry =
			(image_entry_noargs_t) spl_image->entry_point;

	u32 boot_params = *((u32 *)OMAP_SRAM_SCRATCH_BOOT_PARAMS);

	debug("image entry point: 0x%lX\n", spl_image->entry_point);
	/* Pass the saved boot_params from rom code */
	image_entry((u32 *)boot_params);
}
#endif
#ifdef CONFIG_SCSI_AHCI_PLAT
#endif
