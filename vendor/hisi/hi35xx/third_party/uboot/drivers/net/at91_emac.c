#include <common.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/at91_emac.h>
#include <asm/arch/clk.h>
#include <asm/arch/at91_pio.h>
#include <net.h>
#include <netdev.h>
#include <malloc.h>
#include <miiphy.h>
#include <linux/mii.h>
#undef MII_DEBUG
#undef ET_DEBUG
#if (CONFIG_SYS_RX_ETH_BUFFER > 1024)
#error AT91 EMAC supports max 1024 RX buffers. \
#endif
#ifndef CONFIG_DRIVER_AT91EMAC_PHYADDR
#define CONFIG_DRIVER_AT91EMAC_PHYADDR	0
#endif
#if (AT91C_MASTER_CLOCK > 80000000)
#elif (AT91C_MASTER_CLOCK > 40000000)
#elif (AT91C_MASTER_CLOCK > 20000000)
#else
#endif
#ifdef ET_DEBUG
#define DEBUG_AT91EMAC	1
#else
#define DEBUG_AT91EMAC	0
#endif
#ifdef MII_DEBUG
#define DEBUG_AT91PHY	1
#else
#define DEBUG_AT91PHY	0
#endif
#ifndef CONFIG_DRIVER_AT91EMAC_QUIET
#define VERBOSEP	1
#else
#define VERBOSEP	0
#endif
#define RBF_ADDR      0xfffffffc
#define RBF_OWNER     (1<<0)
#define RBF_WRAP      (1<<1)
#define RBF_BROADCAST (1<<31)
#define RBF_MULTICAST (1<<30)
#define RBF_UNICAST   (1<<29)
#define RBF_EXTERNAL  (1<<28)
#define RBF_UNKNOWN   (1<<27)
#define RBF_SIZE      0x07ff
#define RBF_LOCAL4    (1<<26)
#define RBF_LOCAL3    (1<<25)
#define RBF_LOCAL2    (1<<24)
#define RBF_LOCAL1    (1<<23)
#define RBF_FRAMEMAX CONFIG_SYS_RX_ETH_BUFFER
#define RBF_FRAMELEN 0x600
typedef struct {
	unsigned long addr, size;
} rbf_t;
typedef struct {
	rbf_t 		rbfdt[RBF_FRAMEMAX];
	unsigned long	rbindex;
} emac_device;
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#endif
#ifdef CONFIG_RMII
#else
#endif
#ifdef CONFIG_RMII
#endif
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#endif
