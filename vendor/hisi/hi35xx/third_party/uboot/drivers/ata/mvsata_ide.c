#include <common.h>
#include <asm/io.h>
#if defined(CONFIG_ORION5X)
#include <asm/arch/orion5x.h>
#elif defined(CONFIG_KIRKWOOD)
#include <asm/arch/soc.h>
#elif defined(CONFIG_ARCH_MVEBU)
#include <linux/mbus.h>
#endif
#if !defined(CONFIG_SYS_ATA_BASE_ADDR)
#error CONFIG_SYS_ATA_BASE_ADDR must be defined
#elif !defined(CONFIG_SYS_ATA_IDE0_OFFSET) \
#error CONFIG_SYS_ATA_IDE0_OFFSET or CONFIG_SYS_ATA_IDE1_OFFSET \
#elif !defined(CONFIG_IDE_PREINIT)
#error CONFIG_IDE_PREINIT must be defined
#endif
#define MVSATA_EDMA_CMD_ATA_RST		0x00000004
#define MVSATA_SCONTROL_DET_MASK		0x0000000F
#define MVSATA_SCONTROL_DET_NONE		0x00000000
#define MVSATA_SCONTROL_DET_INIT		0x00000001
#define MVSATA_SCONTROL_IPM_MASK		0x00000F00
#define MVSATA_SCONTROL_IPM_NO_LP_ALLOWED	0x00000300
#define MVSATA_SCONTROL_MASK \
#define MVSATA_PORT_INIT \
#define MVSATA_PORT_USE \
#define MVSATA_SSTATUS_DET_MASK			0x0000000F
#define MVSATA_SSTATUS_DET_DEVCOMM		0x00000003
#define MVSATA_STATUS_OK	0
#define MVSATA_STATUS_TIMEOUT	-1
#define MVSATA_WIN_CONTROL(w)	(MVEBU_AXP_SATA_BASE + 0x30 + ((w) << 4))
#define MVSATA_WIN_BASE(w)	(MVEBU_AXP_SATA_BASE + 0x34 + ((w) << 4))
#ifdef CONFIG_ARCH_MVEBU
#endif
#ifdef CONFIG_ARCH_MVEBU
#endif
#if defined(CONFIG_SYS_ATA_IDE0_OFFSET)
#endif
#if defined(CONFIG_SYS_ATA_IDE1_OFFSET)
#endif
