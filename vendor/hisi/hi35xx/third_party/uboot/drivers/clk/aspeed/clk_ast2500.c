#include <common.h>
#include <clk-uclass.h>
#include <dm.h>
#include <asm/io.h>
#include <asm/arch/scu_ast2500.h>
#include <dm/lists.h>
#include <dt-bindings/clock/ast2500-scu.h>
#define RGMII_TXCLK_ODLY		8
#define RMII_RXCLK_IDLY		2
#define RGMII2_TXCK_DUTY	0x66
#define RGMII1_TXCK_DUTY	0x64
#define D2PLL_DEFAULT_RATE	(250 * 1000 * 1000)
