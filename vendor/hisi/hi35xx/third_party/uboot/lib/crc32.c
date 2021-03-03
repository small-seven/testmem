#ifdef USE_HOSTCC
#include <arpa/inet.h>
#include <u-boot/crc.h>
#else
#include <common.h>
#include <efi_loader.h>
#endif
#include <compiler.h>
#include <u-boot/crc.h>
#if defined(CONFIG_HW_WATCHDOG) || defined(CONFIG_WATCHDOG)
#include <watchdog.h>
#endif
#include "u-boot/zlib.h"
#ifdef USE_HOSTCC
#define __efi_runtime
#define __efi_runtime_data
#endif
#define tole(x) cpu_to_le32(x)
#ifdef CONFIG_DYNAMIC_CRC_TABLE
#else
#endif
#if 0
#ifdef CONFIG_DYNAMIC_CRC_TABLE
#endif
#endif
# if __BYTE_ORDER == __LITTLE_ENDIAN
#  define DO_CRC(x) crc = tab[(crc ^ (x)) & 255] ^ (crc >> 8)
# else
#  define DO_CRC(x) crc = tab[((crc >> 24) ^ (x)) & 255] ^ (crc << 8)
# endif
#ifdef CONFIG_DYNAMIC_CRC_TABLE
#endif
#undef DO_CRC
#if defined(CONFIG_HW_WATCHDOG) || defined(CONFIG_WATCHDOG)
#else
#endif
