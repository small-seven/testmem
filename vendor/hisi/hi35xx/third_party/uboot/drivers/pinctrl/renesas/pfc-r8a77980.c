#include <common.h>
#include <dm.h>
#include <errno.h>
#include <dm/pinctrl.h>
#include <linux/kernel.h>
#include "sh_pfc.h"
#define CPU_ALL_PORT(fn, sfx)	\
#define GPSR0_21	F_(DU_EXODDF_DU_ODDF_DISP_CDE,	IP2_23_20)
#define GPSR0_20	F_(DU_EXVSYNC_DU_VSYNC,		IP2_19_16)
#define GPSR0_19	F_(DU_EXHSYNC_DU_HSYNC,		IP2_15_12)
#define GPSR0_18	F_(DU_DOTCLKOUT,		IP2_11_8)
#define GPSR0_17	F_(DU_DB7,			IP2_7_4)
#define GPSR0_16	F_(DU_DB6,			IP2_3_0)
#define GPSR0_15	F_(DU_DB5,			IP1_31_28)
#define GPSR0_14	F_(DU_DB4,			IP1_27_24)
#define GPSR0_13	F_(DU_DB3,			IP1_23_20)
#define GPSR0_12	F_(DU_DB2,			IP1_19_16)
#define GPSR0_11	F_(DU_DG7,			IP1_15_12)
#define GPSR0_10	F_(DU_DG6,			IP1_11_8)
#define GPSR0_9		F_(DU_DG5,			IP1_7_4)
#define GPSR0_8		F_(DU_DG4,			IP1_3_0)
#define GPSR0_7		F_(DU_DG3,			IP0_31_28)
#define GPSR0_6		F_(DU_DG2,			IP0_27_24)
#define GPSR0_5		F_(DU_DR7,			IP0_23_20)
#define GPSR0_4		F_(DU_DR6,			IP0_19_16)
#define GPSR0_3		F_(DU_DR5,			IP0_15_12)
#define GPSR0_2		F_(DU_DR4,			IP0_11_8)
#define GPSR0_1		F_(DU_DR3,			IP0_7_4)
#define GPSR0_0		F_(DU_DR2,			IP0_3_0)
#define GPSR1_27	F_(DIGRF_CLKOUT,	IP8_31_28)
#define GPSR1_26	F_(DIGRF_CLKIN,		IP8_27_24)
#define GPSR1_25	F_(CANFD_CLK_A,		IP8_23_20)
#define GPSR1_24	F_(CANFD1_RX,		IP8_19_16)
#define GPSR1_23	F_(CANFD1_TX,		IP8_15_12)
#define GPSR1_22	F_(CANFD0_RX_A,		IP8_11_8)
#define GPSR1_21	F_(CANFD0_TX_A,		IP8_7_4)
#define GPSR1_20	F_(AVB_AVTP_CAPTURE,	IP8_3_0)
#define GPSR1_19	F_(AVB_AVTP_MATCH,	IP7_31_28)
#define GPSR1_18	FM(AVB_LINK)
#define GPSR1_17	FM(AVB_PHY_INT)
#define GPSR1_16	FM(AVB_MAGIC)
#define GPSR1_15	FM(AVB_MDC)
#define GPSR1_14	FM(AVB_MDIO)
#define GPSR1_13	FM(AVB_TXCREFCLK)
#define GPSR1_12	FM(AVB_TD3)
#define GPSR1_11	FM(AVB_TD2)
#define GPSR1_10	FM(AVB_TD1)
#define GPSR1_9		FM(AVB_TD0)
#define GPSR1_8		FM(AVB_TXC)
#define GPSR1_7		FM(AVB_TX_CTL)
#define GPSR1_6		FM(AVB_RD3)
#define GPSR1_5		FM(AVB_RD2)
#define GPSR1_4		FM(AVB_RD1)
#define GPSR1_3		FM(AVB_RD0)
#define GPSR1_2		FM(AVB_RXC)
#define GPSR1_1		FM(AVB_RX_CTL)
#define GPSR1_0		F_(IRQ0,		IP2_27_24)
#define GPSR2_29	F_(FSO_TOE_N,  		IP10_19_16)
#define GPSR2_28	F_(FSO_CFE_1_N,		IP10_15_12)
#define GPSR2_27	F_(FSO_CFE_0_N,		IP10_11_8)
#define GPSR2_26	F_(SDA3,		IP10_7_4)
#define GPSR2_25	F_(SCL3,		IP10_3_0)
#define GPSR2_24	F_(MSIOF0_SS2,		IP9_31_28)
#define GPSR2_23	F_(MSIOF0_SS1,		IP9_27_24)
#define GPSR2_22	F_(MSIOF0_SYNC,		IP9_23_20)
#define GPSR2_21	F_(MSIOF0_SCK,		IP9_19_16)
#define GPSR2_20	F_(MSIOF0_TXD,		IP9_15_12)
#define GPSR2_19	F_(MSIOF0_RXD,		IP9_11_8)
#define GPSR2_18	F_(IRQ5,		IP9_7_4)
#define GPSR2_17	F_(IRQ4,		IP9_3_0)
#define GPSR2_16	F_(VI0_FIELD,		IP4_31_28)
#define GPSR2_15	F_(VI0_DATA11,		IP4_27_24)
#define GPSR2_14	F_(VI0_DATA10,		IP4_23_20)
#define GPSR2_13	F_(VI0_DATA9,		IP4_19_16)
#define GPSR2_12	F_(VI0_DATA8,		IP4_15_12)
#define GPSR2_11	F_(VI0_DATA7,		IP4_11_8)
#define GPSR2_10	F_(VI0_DATA6,		IP4_7_4)
#define GPSR2_9		F_(VI0_DATA5,		IP4_3_0)
#define GPSR2_8		F_(VI0_DATA4,		IP3_31_28)
#define GPSR2_7		F_(VI0_DATA3,		IP3_27_24)
#define GPSR2_6		F_(VI0_DATA2,		IP3_23_20)
#define GPSR2_5		F_(VI0_DATA1,		IP3_19_16)
#define GPSR2_4		F_(VI0_DATA0,		IP3_15_12)
#define GPSR2_3		F_(VI0_VSYNC_N,		IP3_11_8)
#define GPSR2_2		F_(VI0_HSYNC_N,		IP3_7_4)
#define GPSR2_1		F_(VI0_CLKENB,		IP3_3_0)
#define GPSR2_0		F_(VI0_CLK,		IP2_31_28)
#define GPSR3_16	F_(VI1_FIELD,		IP7_3_0)
#define GPSR3_15	F_(VI1_DATA11,		IP6_31_28)
#define GPSR3_14	F_(VI1_DATA10,		IP6_27_24)
#define GPSR3_13	F_(VI1_DATA9,		IP6_23_20)
#define GPSR3_12	F_(VI1_DATA8,		IP6_19_16)
#define GPSR3_11	F_(VI1_DATA7,		IP6_15_12)
#define GPSR3_10	F_(VI1_DATA6,		IP6_11_8)
#define GPSR3_9		F_(VI1_DATA5,		IP6_7_4)
#define GPSR3_8		F_(VI1_DATA4,		IP6_3_0)
#define GPSR3_7		F_(VI1_DATA3,		IP5_31_28)
#define GPSR3_6		F_(VI1_DATA2,		IP5_27_24)
#define GPSR3_5		F_(VI1_DATA1,		IP5_23_20)
#define GPSR3_4		F_(VI1_DATA0,		IP5_19_16)
#define GPSR3_3		F_(VI1_VSYNC_N,		IP5_15_12)
#define GPSR3_2		F_(VI1_HSYNC_N,		IP5_11_8)
#define GPSR3_1		F_(VI1_CLKENB,		IP5_7_4)
#define GPSR3_0		F_(VI1_CLK,		IP5_3_0)
#define GPSR4_24	FM(GETHER_LINK_A)
#define GPSR4_23	FM(GETHER_PHY_INT_A)
#define GPSR4_22	FM(GETHER_MAGIC)
#define GPSR4_21	FM(GETHER_MDC_A)
#define GPSR4_20	FM(GETHER_MDIO_A)
#define GPSR4_19	FM(GETHER_TXCREFCLK_MEGA)
#define GPSR4_18	FM(GETHER_TXCREFCLK)
#define GPSR4_17	FM(GETHER_TD3)
#define GPSR4_16	FM(GETHER_TD2)
#define GPSR4_15	FM(GETHER_TD1)
#define GPSR4_14	FM(GETHER_TD0)
#define GPSR4_13	FM(GETHER_TXC)
#define GPSR4_12	FM(GETHER_TX_CTL)
#define GPSR4_11	FM(GETHER_RD3)
#define GPSR4_10	FM(GETHER_RD2)
#define GPSR4_9		FM(GETHER_RD1)
#define GPSR4_8		FM(GETHER_RD0)
#define GPSR4_7		FM(GETHER_RXC)
#define GPSR4_6		FM(GETHER_RX_CTL)
#define GPSR4_5		F_(SDA2,		IP7_27_24)
#define GPSR4_4		F_(SCL2,		IP7_23_20)
#define GPSR4_3		F_(SDA1,		IP7_19_16)
#define GPSR4_2		F_(SCL1,		IP7_15_12)
#define GPSR4_1		F_(SDA0,		IP7_11_8)
#define GPSR4_0		F_(SCL0,		IP7_7_4)
#define GPSR5_14	FM(RPC_INT_N)
#define GPSR5_13	FM(RPC_WP_N)
#define GPSR5_12	FM(RPC_RESET_N)
#define GPSR5_11	FM(QSPI1_SSL)
#define GPSR5_10	FM(QSPI1_IO3)
#define GPSR5_9		FM(QSPI1_IO2)
#define GPSR5_8		FM(QSPI1_MISO_IO1)
#define GPSR5_7		FM(QSPI1_MOSI_IO0)
#define GPSR5_6		FM(QSPI1_SPCLK)
#define GPSR5_5		FM(QSPI0_SSL)
#define GPSR5_4		FM(QSPI0_IO3)
#define GPSR5_3		FM(QSPI0_IO2)
#define GPSR5_2		FM(QSPI0_MISO_IO1)
#define GPSR5_1		FM(QSPI0_MOSI_IO0)
#define GPSR5_0		FM(QSPI0_SPCLK)
#define IP0_3_0		FM(DU_DR2)			FM(SCK4)		FM(GETHER_RMII_CRS_DV)	FM(A0)		F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP0_7_4		FM(DU_DR3)			FM(RX4)			FM(GETHER_RMII_RX_ER)	FM(A1)		F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP0_11_8	FM(DU_DR4)			FM(TX4)			FM(GETHER_RMII_RXD0)	FM(A2)		F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP0_15_12	FM(DU_DR5)			FM(CTS4_N)		FM(GETHER_RMII_RXD1)	FM(A3)		F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP0_19_16	FM(DU_DR6)			FM(RTS4_N)		FM(GETHER_RMII_TXD_EN)	FM(A4)		F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP0_23_20	FM(DU_DR7)			F_(0, 0)		FM(GETHER_RMII_TXD0)	FM(A5)		F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP0_27_24	FM(DU_DG2)			F_(0, 0)		FM(GETHER_RMII_TXD1)	FM(A6)		F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP0_31_28	FM(DU_DG3)			FM(CPG_CPCKOUT)		FM(GETHER_RMII_REFCLK)	FM(A7)		FM(PWMFSW0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP1_3_0		FM(DU_DG4)			FM(SCL5)		F_(0, 0)		FM(A8)		F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP1_7_4		FM(DU_DG5)			FM(SDA5)		FM(GETHER_MDC_B)	FM(A9)		F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP1_11_8	FM(DU_DG6)			FM(SCIF_CLK_A)		FM(GETHER_MDIO_B)	FM(A10)		F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP1_15_12	FM(DU_DG7)			FM(HRX0_A)		F_(0, 0)		FM(A11)		F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP1_19_16	FM(DU_DB2)			FM(HSCK0_A)		F_(0, 0)		FM(A12)		FM(IRQ1)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP1_23_20	FM(DU_DB3)			FM(HRTS0_N_A)		F_(0, 0)		FM(A13)		FM(IRQ2)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP1_27_24	FM(DU_DB4)			FM(HCTS0_N_A)		F_(0, 0)		FM(A14)		FM(IRQ3)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP1_31_28	FM(DU_DB5)			FM(HTX0_A)		FM(PWM0_A)		FM(A15)		F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP2_3_0		FM(DU_DB6)			FM(MSIOF3_RXD)		F_(0, 0)		FM(A16)		F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP2_7_4		FM(DU_DB7)			FM(MSIOF3_TXD)		F_(0, 0)		FM(A17)		F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP2_11_8	FM(DU_DOTCLKOUT)		FM(MSIOF3_SS1)		FM(GETHER_LINK_B)	FM(A18)		F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP2_15_12	FM(DU_EXHSYNC_DU_HSYNC)		FM(MSIOF3_SS2)		FM(GETHER_PHY_INT_B)	FM(A19)		FM(FXR_TXENA_N)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP2_19_16	FM(DU_EXVSYNC_DU_VSYNC)		FM(MSIOF3_SCK)		F_(0, 0)		F_(0, 0)	FM(FXR_TXENB_N)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP2_23_20	FM(DU_EXODDF_DU_ODDF_DISP_CDE)	FM(MSIOF3_SYNC)		F_(0, 0)		F_(0, 0)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP2_27_24	FM(IRQ0)			F_(0, 0)		F_(0, 0)		F_(0, 0)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP2_31_28	FM(VI0_CLK)			FM(MSIOF2_SCK)		FM(SCK3)		F_(0, 0)	FM(HSCK3)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP3_3_0		FM(VI0_CLKENB)			FM(MSIOF2_RXD)		FM(RX3)			FM(RD_WR_N)	FM(HCTS3_N)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP3_7_4		FM(VI0_HSYNC_N)			FM(MSIOF2_TXD)		FM(TX3)			F_(0, 0)	FM(HRTS3_N)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP3_11_8	FM(VI0_VSYNC_N)			FM(MSIOF2_SYNC)		FM(CTS3_N)		F_(0, 0)	FM(HTX3)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP3_15_12	FM(VI0_DATA0)			FM(MSIOF2_SS1)		FM(RTS3_N)		F_(0, 0)	FM(HRX3)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP3_19_16	FM(VI0_DATA1)			FM(MSIOF2_SS2)		FM(SCK1)		F_(0, 0)	FM(SPEEDIN_A)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP3_23_20	FM(VI0_DATA2)			FM(AVB_AVTP_PPS)	F_(0, 0)		F_(0, 0)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP3_27_24	FM(VI0_DATA3)			FM(HSCK1)		F_(0, 0)		F_(0, 0)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP3_31_28	FM(VI0_DATA4)			FM(HRTS1_N)		FM(RX1_A)		F_(0, 0)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP4_3_0		FM(VI0_DATA5)			FM(HCTS1_N)		FM(TX1_A)		F_(0, 0)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP4_7_4		FM(VI0_DATA6)			FM(HTX1)		FM(CTS1_N)		F_(0, 0)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP4_11_8	FM(VI0_DATA7)			FM(HRX1)		FM(RTS1_N)		F_(0, 0)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP4_15_12	FM(VI0_DATA8)			FM(HSCK2)		F_(0, 0)		F_(0, 0)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP4_19_16	FM(VI0_DATA9)			FM(HCTS2_N)		FM(PWM1_A)		F_(0, 0)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP4_23_20	FM(VI0_DATA10)			FM(HRTS2_N)		FM(PWM2_A)		F_(0, 0)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP4_27_24	FM(VI0_DATA11)			FM(HTX2)		FM(PWM3_A)		F_(0, 0)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP4_31_28	FM(VI0_FIELD)			FM(HRX2)		FM(PWM4_A)		FM(CS1_N)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP5_3_0		FM(VI1_CLK)			FM(MSIOF1_RXD)		F_(0, 0)		FM(CS0_N)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP5_7_4		FM(VI1_CLKENB)			FM(MSIOF1_TXD)		F_(0, 0)		FM(D0)		F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP5_11_8	FM(VI1_HSYNC_N)			FM(MSIOF1_SCK)		F_(0, 0)		FM(D1)		F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP5_15_12	FM(VI1_VSYNC_N)			FM(MSIOF1_SYNC)		F_(0, 0)		FM(D2)		F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP5_19_16	FM(VI1_DATA0)			FM(MSIOF1_SS1)		F_(0, 0)		FM(D3)		FM(MMC_WP)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP5_23_20	FM(VI1_DATA1)			FM(MSIOF1_SS2)		F_(0, 0)		FM(D4)		FM(MMC_CD)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP5_27_24	FM(VI1_DATA2)			FM(CANFD0_TX_B)		F_(0, 0)		FM(D5)		FM(MMC_DS)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP5_31_28	FM(VI1_DATA3)			FM(CANFD0_RX_B)		F_(0, 0)		FM(D6)		FM(MMC_CMD)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP6_3_0		FM(VI1_DATA4)			FM(CANFD_CLK_B)		F_(0, 0)		FM(D7)		FM(MMC_D0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP6_7_4		FM(VI1_DATA5)			F_(0, 0)		F_(0, 0)		FM(D8)		FM(MMC_D1)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP6_11_8	FM(VI1_DATA6)			F_(0, 0)		F_(0, 0)		FM(D9)		FM(MMC_D2)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP6_15_12	FM(VI1_DATA7)			F_(0, 0)		F_(0, 0)		FM(D10)		FM(MMC_D3)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP6_19_16	FM(VI1_DATA8)			F_(0, 0)		F_(0, 0)		FM(D11)		FM(MMC_CLK)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP6_23_20	FM(VI1_DATA9)			FM(TCLK1_A)		F_(0, 0)		FM(D12)		FM(MMC_D4)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP6_27_24	FM(VI1_DATA10)			FM(TCLK2_A)		F_(0, 0)		FM(D13)		FM(MMC_D5)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP6_31_28	FM(VI1_DATA11)			FM(SCL4)		F_(0, 0)		FM(D14)		FM(MMC_D6)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP7_3_0		FM(VI1_FIELD)			FM(SDA4)		F_(0, 0)		FM(D15)		FM(MMC_D7)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP7_7_4		FM(SCL0)			F_(0, 0)		F_(0, 0)		FM(CLKOUT)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP7_11_8	FM(SDA0)			F_(0, 0)		F_(0, 0)		FM(BS_N)	FM(SCK0)	FM(HSCK0_B)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP7_15_12	FM(SCL1)			F_(0, 0)		FM(TPU0TO2)		FM(RD_N)	FM(CTS0_N)	FM(HCTS0_N_B)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP7_19_16	FM(SDA1)			F_(0, 0)		FM(TPU0TO3)		FM(WE0_N)	FM(RTS0_N)	FM(HRTS0_N_B)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP7_23_20	FM(SCL2)			F_(0, 0)		F_(0, 0)		FM(WE1_N)	FM(RX0)		FM(HRX0_B)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP7_27_24	FM(SDA2)			F_(0, 0)		F_(0, 0)		FM(EX_WAIT0)	FM(TX0)		FM(HTX0_B)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP7_31_28	FM(AVB_AVTP_MATCH)		FM(TPU0TO0)		F_(0, 0)		F_(0, 0)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP8_3_0		FM(AVB_AVTP_CAPTURE)		FM(TPU0TO1)		F_(0, 0)		F_(0, 0)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP8_7_4		FM(CANFD0_TX_A)			FM(FXR_TXDA)		FM(PWM0_B)		FM(DU_DISP)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP8_11_8	FM(CANFD0_RX_A)			FM(RXDA_EXTFXR)		FM(PWM1_B)		FM(DU_CDE)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP8_15_12	FM(CANFD1_TX)			FM(FXR_TXDB)		FM(PWM2_B)		FM(TCLK1_B)	FM(TX1_B)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP8_19_16	FM(CANFD1_RX)			FM(RXDB_EXTFXR)		FM(PWM3_B)		FM(TCLK2_B)	FM(RX1_B)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP8_23_20	FM(CANFD_CLK_A) 		FM(CLK_EXTFXR)		FM(PWM4_B)		FM(SPEEDIN_B)	FM(SCIF_CLK_B)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP8_27_24	FM(DIGRF_CLKIN)			FM(DIGRF_CLKEN_IN)	F_(0, 0)		F_(0, 0)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP8_31_28	FM(DIGRF_CLKOUT)		FM(DIGRF_CLKEN_OUT)	F_(0, 0)		F_(0, 0)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP9_3_0		FM(IRQ4)			F_(0, 0)		F_(0, 0)		FM(VI0_DATA12)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP9_7_4 	FM(IRQ5)			F_(0, 0)		F_(0, 0)		FM(VI0_DATA13)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP9_11_8	FM(MSIOF0_RXD)			FM(DU_DR0)		F_(0, 0)		FM(VI0_DATA14)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP9_15_12	FM(MSIOF0_TXD)			FM(DU_DR1)		F_(0, 0)		FM(VI0_DATA15)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP9_19_16	FM(MSIOF0_SCK)			FM(DU_DG0)		F_(0, 0)		FM(VI0_DATA16)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP9_23_20	FM(MSIOF0_SYNC)			FM(DU_DG1)		F_(0, 0)		FM(VI0_DATA17)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP9_27_24	FM(MSIOF0_SS1)			FM(DU_DB0)		FM(TCLK3)		FM(VI0_DATA18)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP9_31_28	FM(MSIOF0_SS2)			FM(DU_DB1)		FM(TCLK4)		FM(VI0_DATA19)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP10_3_0	FM(SCL3)			F_(0, 0)		F_(0, 0)		FM(VI0_DATA20)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP10_7_4	FM(SDA3)			F_(0, 0)		F_(0, 0)		FM(VI0_DATA21)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP10_11_8	FM(FSO_CFE_0_N)			F_(0, 0)		F_(0, 0)		FM(VI0_DATA22)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP10_15_12	FM(FSO_CFE_1_N)			F_(0, 0)		F_(0, 0)		FM(VI0_DATA23)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP10_19_16	FM(FSO_TOE_N)			F_(0, 0)		F_(0, 0)		F_(0, 0)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP10_23_20	F_(0, 0)			F_(0, 0)		F_(0, 0)		F_(0, 0)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP10_27_24	F_(0, 0)			F_(0, 0)		F_(0, 0)		F_(0, 0)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define IP10_31_28	F_(0, 0)			F_(0, 0)		F_(0, 0)		F_(0, 0)	F_(0, 0)	F_(0, 0)	F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0) F_(0, 0)
#define PINMUX_GPSR	\
#define PINMUX_IPSR	\
#define MOD_SEL0_11	FM(SEL_CANFD0_0)	FM(SEL_CANFD0_1)
#define MOD_SEL0_10	FM(SEL_GETHER_0)	FM(SEL_GETHER_1)
#define MOD_SEL0_9	FM(SEL_HSCIF0_0)	FM(SEL_HSCIF0_1)
#define MOD_SEL0_8	FM(SEL_PWM0_0)		FM(SEL_PWM0_1)
#define MOD_SEL0_7	FM(SEL_PWM1_0)		FM(SEL_PWM1_1)
#define MOD_SEL0_6	FM(SEL_PWM2_0)		FM(SEL_PWM2_1)
#define MOD_SEL0_5	FM(SEL_PWM3_0)		FM(SEL_PWM3_1)
#define MOD_SEL0_4	FM(SEL_PWM4_0)		FM(SEL_PWM4_1)
#define MOD_SEL0_2	FM(SEL_RSP_0)		FM(SEL_RSP_1)
#define MOD_SEL0_1	FM(SEL_SCIF1_0)		FM(SEL_SCIF1_1)
#define MOD_SEL0_0	FM(SEL_TMU_0)		FM(SEL_TMU_1)
#define PINMUX_MOD_SELS \
#define F_(x, y)
#define FM(x)   FN_##x,
#undef F_
#undef FM
#define F_(x, y)
#define FM(x)	x##_MARK,
#undef F_
#undef FM
#define F_(x, y)	FN_##y
#define FM(x)		FN_##x
#undef F_
#undef FM
#define F_(x, y)	x,
#define FM(x)		FN_##x,
#undef F_
#undef FM
#define F_(x, y)	x,
#define FM(x)		FN_##x,
