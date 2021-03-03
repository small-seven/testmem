#include <common.h>
#include <cpu_func.h>
#include <spi_flash.h>
#include <malloc.h>
#define ESPI_BOOT_IMAGE_SIZE	0x48
#define ESPI_BOOT_IMAGE_ADDR	0x50
#define CONFIG_CFG_DATA_SECTOR	0
#ifndef CONFIG_FSL_CORENET
#endif
#ifdef CONFIG_FSL_CORENET
#else
#endif
