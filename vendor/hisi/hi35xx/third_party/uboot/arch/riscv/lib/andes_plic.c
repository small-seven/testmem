#include <common.h>
#include <dm.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <dm/uclass-internal.h>
#include <regmap.h>
#include <syscon.h>
#include <asm/io.h>
#include <asm/syscon.h>
#include <cpu.h>
#define PENDING_REG(base, hart)	((ulong)(base) + 0x1000 + ((hart) / 4) * 4)
#define ENABLE_REG(base, hart)	((ulong)(base) + 0x2000 + (hart) * 0x80)
#define CLAIM_REG(base, hart)	((ulong)(base) + 0x200004 + (hart) * 0x1000)
#define ENABLE_HART_IPI         (0x80808080)
#define SEND_IPI_TO_HART(hart)  (0x80 >> (hart))
#define PLIC_BASE_GET(void)						\
