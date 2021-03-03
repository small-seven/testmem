#include <asm/unaligned.h>
#include <common.h>
#include <command.h>
#include <mach/mon.h>
#include <spl.h>
#ifdef CONFIG_TI_SECURE_DEVICE
#define KS2_HS_SEC_HEADER_LEN	0x60
#define KS2_HS_SEC_TAG_OFFSET	0x34
#define KS2_AUTH_CMD		130
#endif
