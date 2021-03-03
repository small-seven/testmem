#ifdef USE_HOSTCC
#include <arpa/inet.h>
#else
#include <common.h>
#endif
#include <u-boot/crc.h>
#define POLY	(0x1070U << 3)
