#include <hi_flashboot.h>
#include <boot_start.h>
#include <hi_boot_rom.h>
#include "main.h"
#ifdef CONFIG_FLASH_ENCRYPT_SUPPORT
#include <crypto.h>
#endif
#define KERNEL_START_ADDR   0x40D3C0
#define FLASHBOOT_UART_DEFAULT_PARAM    {115200, 8, 1, 0, 0, 0, 2, 1, 4}
#define XTAL_DS     0x7
#define OSC_DRV_CTL 0x2
#ifndef CONFIG_QUICK_SEND_MODE
#else
#ifdef CHIP_HI3861L
#endif
#endif
