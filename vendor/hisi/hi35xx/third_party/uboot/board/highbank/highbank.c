#include <common.h>
#include <ahci.h>
#include <cpu_func.h>
#include <env.h>
#include <netdev.h>
#include <scsi.h>
#include <linux/sizes.h>
#include <asm/io.h>
#define HB_AHCI_BASE			0xffe08000
#define HB_SCU_A9_PWR_STATUS		0xfff10008
#define HB_SREG_A9_PWR_REQ		0xfff3cf00
#define HB_SREG_A9_BOOT_SRC_STAT	0xfff3cf04
#define HB_SREG_A9_PWRDOM_STAT		0xfff3cf20
#define HB_SREG_A15_PWR_CTRL		0xfff3c200
#define HB_PWR_SUSPEND			0
#define HB_PWR_SOFT_RESET		1
#define HB_PWR_HARD_RESET		2
#define HB_PWR_SHUTDOWN			3
#define PWRDOM_STAT_SATA		0x80000000
#define PWRDOM_STAT_PCI			0x40000000
#define PWRDOM_STAT_EMMC		0x20000000
#define HB_SCU_A9_PWR_NORMAL		0
#define HB_SCU_A9_PWR_DORMANT		2
#define HB_SCU_A9_PWR_OFF		3
#ifdef CONFIG_CALXEDA_XGMAC
#endif
#ifdef CONFIG_SCSI_AHCI_PLAT
#endif
#ifdef CONFIG_MISC_INIT_R
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#endif
