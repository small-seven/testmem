#include <common.h>
#include <asm/io.h>
#include <asm/arch/base.h>
#include <asm/arch/wdog.h>
#include <efi_loader.h>
#define RESET_TIMEOUT 10
#define BCM2835_WDOG_RSTS_RASPBERRYPI_HALT	0x555
#define BCM2835_WDOG_MAX_TIMEOUT	0x000fffff
#ifdef CONFIG_EFI_LOADER
#endif
