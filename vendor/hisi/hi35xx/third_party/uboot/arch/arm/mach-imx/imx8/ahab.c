#include <common.h>
#include <errno.h>
#include <asm/io.h>
#include <asm/arch/sci/sci.h>
#include <asm/mach-imx/sys_proto.h>
#include <asm/arch-imx/cpu.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/image.h>
#include <console.h>
#define SEC_SECURE_RAM_BASE             (0x31800000UL)
#define SEC_SECURE_RAM_END_BASE         (SEC_SECURE_RAM_BASE + 0xFFFFUL)
#define SECO_LOCAL_SEC_SEC_SECURE_RAM_BASE  (0x60000000UL)
#define SECO_PT                 2U
#define AHAB_AUTH_CONTAINER_REQ 0x87
#define AHAB_VERIFY_IMAGE_REQ 0x88
#define AHAB_NO_AUTHENTICATION_IND 0xee
#define AHAB_BAD_KEY_HASH_IND 0xfa
#define AHAB_INVALID_KEY_IND 0xf9
#define AHAB_BAD_SIGNATURE_IND 0xf0
#define AHAB_BAD_HASH_IND 0xf1
