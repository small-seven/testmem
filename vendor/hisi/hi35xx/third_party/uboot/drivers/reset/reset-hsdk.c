#include <asm/io.h>
#include <common.h>
#include <dm.h>
#include <linux/iopoll.h>
#include <reset-uclass.h>
#define HSDK_MAX_RESETS			ARRAY_SIZE(rst_map)
#define CGU_SYS_RST_CTRL		0x0
#define CGU_IP_SW_RESET			0x0
#define CGU_IP_SW_RESET_DELAY_SHIFT	16
#define CGU_IP_SW_RESET_DELAY_MASK	GENMASK(31, CGU_IP_SW_RESET_DELAY_SHIFT)
#define CGU_IP_SW_RESET_DELAY		0
#define CGU_IP_SW_RESET_RESET		BIT(0)
#define SW_RESET_TIMEOUT		10000
