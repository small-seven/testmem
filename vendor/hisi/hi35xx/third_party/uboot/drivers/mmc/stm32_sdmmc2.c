#include <common.h>
#include <clk.h>
#include <cpu_func.h>
#include <dm.h>
#include <fdtdec.h>
#include <linux/libfdt.h>
#include <mmc.h>
#include <reset.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <linux/iopoll.h>
#include <watchdog.h>
#define SDMMC_POWER		0x00	/* SDMMC power control             */
#define SDMMC_CLKCR		0x04	/* SDMMC clock control             */
#define SDMMC_ARG		0x08	/* SDMMC argument                  */
#define SDMMC_CMD		0x0C	/* SDMMC command                   */
#define SDMMC_RESP1		0x14	/* SDMMC response 1                */
#define SDMMC_RESP2		0x18	/* SDMMC response 2                */
#define SDMMC_RESP3		0x1C	/* SDMMC response 3                */
#define SDMMC_RESP4		0x20	/* SDMMC response 4                */
#define SDMMC_DTIMER		0x24	/* SDMMC data timer                */
#define SDMMC_DLEN		0x28	/* SDMMC data length               */
#define SDMMC_DCTRL		0x2C	/* SDMMC data control              */
#define SDMMC_DCOUNT		0x30	/* SDMMC data counter              */
#define SDMMC_STA		0x34	/* SDMMC status                    */
#define SDMMC_ICR		0x38	/* SDMMC interrupt clear           */
#define SDMMC_MASK		0x3C	/* SDMMC mask                      */
#define SDMMC_IDMACTRL		0x50	/* SDMMC DMA control               */
#define SDMMC_IDMABASE0		0x58	/* SDMMC DMA buffer 0 base address */
#define SDMMC_POWER_PWRCTRL_MASK	GENMASK(1, 0)
#define SDMMC_POWER_PWRCTRL_OFF		0
#define SDMMC_POWER_PWRCTRL_CYCLE	2
#define SDMMC_POWER_PWRCTRL_ON		3
#define SDMMC_POWER_VSWITCH		BIT(2)
#define SDMMC_POWER_VSWITCHEN		BIT(3)
#define SDMMC_POWER_DIRPOL		BIT(4)
#define SDMMC_CLKCR_CLKDIV		GENMASK(9, 0)
#define SDMMC_CLKCR_CLKDIV_MAX		SDMMC_CLKCR_CLKDIV
#define SDMMC_CLKCR_PWRSAV		BIT(12)
#define SDMMC_CLKCR_WIDBUS_4		BIT(14)
#define SDMMC_CLKCR_WIDBUS_8		BIT(15)
#define SDMMC_CLKCR_NEGEDGE		BIT(16)
#define SDMMC_CLKCR_HWFC_EN		BIT(17)
#define SDMMC_CLKCR_DDR			BIT(18)
#define SDMMC_CLKCR_BUSSPEED		BIT(19)
#define SDMMC_CLKCR_SELCLKRX_MASK	GENMASK(21, 20)
#define SDMMC_CLKCR_SELCLKRX_CK		0
#define SDMMC_CLKCR_SELCLKRX_CKIN	BIT(20)
#define SDMMC_CLKCR_SELCLKRX_FBCK	BIT(21)
#define SDMMC_CMD_CMDINDEX		GENMASK(5, 0)
#define SDMMC_CMD_CMDTRANS		BIT(6)
#define SDMMC_CMD_CMDSTOP		BIT(7)
#define SDMMC_CMD_WAITRESP		GENMASK(9, 8)
#define SDMMC_CMD_WAITRESP_0		BIT(8)
#define SDMMC_CMD_WAITRESP_1		BIT(9)
#define SDMMC_CMD_WAITINT		BIT(10)
#define SDMMC_CMD_WAITPEND		BIT(11)
#define SDMMC_CMD_CPSMEN		BIT(12)
#define SDMMC_CMD_DTHOLD		BIT(13)
#define SDMMC_CMD_BOOTMODE		BIT(14)
#define SDMMC_CMD_BOOTEN		BIT(15)
#define SDMMC_CMD_CMDSUSPEND		BIT(16)
#define SDMMC_DCTRL_DTEN		BIT(0)
#define SDMMC_DCTRL_DTDIR		BIT(1)
#define SDMMC_DCTRL_DTMODE		GENMASK(3, 2)
#define SDMMC_DCTRL_DBLOCKSIZE		GENMASK(7, 4)
#define SDMMC_DCTRL_DBLOCKSIZE_SHIFT	4
#define SDMMC_DCTRL_RWSTART		BIT(8)
#define SDMMC_DCTRL_RWSTOP		BIT(9)
#define SDMMC_DCTRL_RWMOD		BIT(10)
#define SDMMC_DCTRL_SDMMCEN		BIT(11)
#define SDMMC_DCTRL_BOOTACKEN		BIT(12)
#define SDMMC_DCTRL_FIFORST		BIT(13)
#define SDMMC_STA_CCRCFAIL		BIT(0)
#define SDMMC_STA_DCRCFAIL		BIT(1)
#define SDMMC_STA_CTIMEOUT		BIT(2)
#define SDMMC_STA_DTIMEOUT		BIT(3)
#define SDMMC_STA_TXUNDERR		BIT(4)
#define SDMMC_STA_RXOVERR		BIT(5)
#define SDMMC_STA_CMDREND		BIT(6)
#define SDMMC_STA_CMDSENT		BIT(7)
#define SDMMC_STA_DATAEND		BIT(8)
#define SDMMC_STA_DHOLD			BIT(9)
#define SDMMC_STA_DBCKEND		BIT(10)
#define SDMMC_STA_DABORT		BIT(11)
#define SDMMC_STA_DPSMACT		BIT(12)
#define SDMMC_STA_CPSMACT		BIT(13)
#define SDMMC_STA_TXFIFOHE		BIT(14)
#define SDMMC_STA_RXFIFOHF		BIT(15)
#define SDMMC_STA_TXFIFOF		BIT(16)
#define SDMMC_STA_RXFIFOF		BIT(17)
#define SDMMC_STA_TXFIFOE		BIT(18)
#define SDMMC_STA_RXFIFOE		BIT(19)
#define SDMMC_STA_BUSYD0		BIT(20)
#define SDMMC_STA_BUSYD0END		BIT(21)
#define SDMMC_STA_SDMMCIT		BIT(22)
#define SDMMC_STA_ACKFAIL		BIT(23)
#define SDMMC_STA_ACKTIMEOUT		BIT(24)
#define SDMMC_STA_VSWEND		BIT(25)
#define SDMMC_STA_CKSTOP		BIT(26)
#define SDMMC_STA_IDMATE		BIT(27)
#define SDMMC_STA_IDMABTC		BIT(28)
#define SDMMC_ICR_CCRCFAILC		BIT(0)
#define SDMMC_ICR_DCRCFAILC		BIT(1)
#define SDMMC_ICR_CTIMEOUTC		BIT(2)
#define SDMMC_ICR_DTIMEOUTC		BIT(3)
#define SDMMC_ICR_TXUNDERRC		BIT(4)
#define SDMMC_ICR_RXOVERRC		BIT(5)
#define SDMMC_ICR_CMDRENDC		BIT(6)
#define SDMMC_ICR_CMDSENTC		BIT(7)
#define SDMMC_ICR_DATAENDC		BIT(8)
#define SDMMC_ICR_DHOLDC		BIT(9)
#define SDMMC_ICR_DBCKENDC		BIT(10)
#define SDMMC_ICR_DABORTC		BIT(11)
#define SDMMC_ICR_BUSYD0ENDC		BIT(21)
#define SDMMC_ICR_SDMMCITC		BIT(22)
#define SDMMC_ICR_ACKFAILC		BIT(23)
#define SDMMC_ICR_ACKTIMEOUTC		BIT(24)
#define SDMMC_ICR_VSWENDC		BIT(25)
#define SDMMC_ICR_CKSTOPC		BIT(26)
#define SDMMC_ICR_IDMATEC		BIT(27)
#define SDMMC_ICR_IDMABTCC		BIT(28)
#define SDMMC_ICR_STATIC_FLAGS		((GENMASK(28, 21)) | (GENMASK(11, 0)))
#define SDMMC_MASK_CCRCFAILIE		BIT(0)
#define SDMMC_MASK_DCRCFAILIE		BIT(1)
#define SDMMC_MASK_CTIMEOUTIE		BIT(2)
#define SDMMC_MASK_DTIMEOUTIE		BIT(3)
#define SDMMC_MASK_TXUNDERRIE		BIT(4)
#define SDMMC_MASK_RXOVERRIE		BIT(5)
#define SDMMC_MASK_CMDRENDIE		BIT(6)
#define SDMMC_MASK_CMDSENTIE		BIT(7)
#define SDMMC_MASK_DATAENDIE		BIT(8)
#define SDMMC_MASK_DHOLDIE		BIT(9)
#define SDMMC_MASK_DBCKENDIE		BIT(10)
#define SDMMC_MASK_DABORTIE		BIT(11)
#define SDMMC_MASK_TXFIFOHEIE		BIT(14)
#define SDMMC_MASK_RXFIFOHFIE		BIT(15)
#define SDMMC_MASK_RXFIFOFIE		BIT(17)
#define SDMMC_MASK_TXFIFOEIE		BIT(18)
#define SDMMC_MASK_BUSYD0ENDIE		BIT(21)
#define SDMMC_MASK_SDMMCITIE		BIT(22)
#define SDMMC_MASK_ACKFAILIE		BIT(23)
#define SDMMC_MASK_ACKTIMEOUTIE		BIT(24)
#define SDMMC_MASK_VSWENDIE		BIT(25)
#define SDMMC_MASK_CKSTOPIE		BIT(26)
#define SDMMC_MASK_IDMABTCIE		BIT(28)
#define SDMMC_IDMACTRL_IDMAEN		BIT(0)
#define SDMMC_CMD_TIMEOUT		0xFFFFFFFF
#define SDMMC_BUSYD0END_TIMEOUT_US	2000000
#define IS_RISING_EDGE(reg) (reg & SDMMC_CLKCR_NEGEDGE ? 0 : 1)