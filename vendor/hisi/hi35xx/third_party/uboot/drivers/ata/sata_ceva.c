#include <common.h>
#include <dm.h>
#include <ahci.h>
#include <scsi.h>
#include <asm/io.h>
#include <linux/ioport.h>
#define AHCI_VEND_PCFG  0xA4
#define AHCI_VEND_PPCFG 0xA8
#define AHCI_VEND_PP2C  0xAC
#define AHCI_VEND_PP3C  0xB0
#define AHCI_VEND_PP4C  0xB4
#define AHCI_VEND_PP5C  0xB8
#define AHCI_VEND_AXICC 0xBc
#define AHCI_VEND_PAXIC 0xC0
#define AHCI_VEND_PTC   0xC8
#define PAXIC_ADBW_BW64 0x1
#define PAXIC_MAWIDD	(1 << 8)
#define PAXIC_MARIDD	(1 << 16)
#define PAXIC_OTL	(0x4 << 20)
#define PCFG_TPSS_VAL	(0x32 << 16)
#define PCFG_TPRS_VAL	(0x2 << 12)
#define PCFG_PAD_VAL	0x2
#define PPCFG_TTA	0x1FFFE
#define PPCFG_PSSO_EN	(1 << 28)
#define PPCFG_PSS_EN	(1 << 29)
#define PPCFG_ESDF_EN	(1 << 31)
#define PP2C_CIBGMN	0x0F
#define PP2C_CIBGMX	(0x25 << 8)
#define PP2C_CIBGN	(0x18 << 16)
#define PP2C_CINMP	(0x29 << 24)
#define PP3C_CWBGMN	0x04
#define PP3C_CWBGMX	(0x0B << 8)
#define PP3C_CWBGN	(0x08 << 16)
#define PP3C_CWNMP	(0x0F << 24)
#define PP4C_BMX	0x0a
#define PP4C_BNM	(0x08 << 8)
#define PP4C_SFD	(0x4a << 16)
#define PP4C_PTST	(0x06 << 24)
#define PP5C_RIT	0x60216
#define PP5C_RCT	(0x7f0 << 20)
#define PTC_RX_WM_VAL	0x40
#define PTC_RSVD	(1 << 27)
#define PORT0_BASE	0x100
#define PORT1_BASE	0x180
#define PORT_SCTL_SPD_GEN3	(0x3 << 4)
#define PORT_SCTL_SPD_GEN2	(0x2 << 4)
#define PORT_SCTL_SPD_GEN1	(0x1 << 4)
#define PORT_SCTL_IPM		(0x3 << 8)
#define PORT_BASE	0x100
#define PORT_OFFSET	0x80
#define NR_PORTS	2
#define DRV_NAME	"ahci-ceva"
#define CEVA_FLAG_BROKEN_GEN2	1
#define FLAG_COHERENT	1
#define CEVA_PHY1_CFG	0xa003fffe
#define CEVA_PHY2_CFG	0x28184d1f
#define CEVA_PHY3_CFG	0x0e081509
#define CEVA_TRANS_CFG	0x08000029
#define CEVA_AXICC_CFG	0x3fffffff
#define LS1021_AHCI_VEND_AXICC	0xC0
#define LS1021_CEVA_PHY2_CFG	0x28183414
#define LS1021_CEVA_PHY3_CFG	0x0e080e06
#define LS1021_CEVA_PHY4_CFG	0x064a080b
#define LS1021_CEVA_PHY5_CFG	0x2aa86470
#define ECC_DIS_VAL_CH1		0x00020000
#define ECC_DIS_VAL_CH2		0x80000000
#define ECC_DIS_VAL_CH3		0x40000000
