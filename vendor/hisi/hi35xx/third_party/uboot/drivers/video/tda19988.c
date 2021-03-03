#include <common.h>
#include <dm.h>
#include <display.h>
#include <i2c.h>
#define REG(page, addr)		(((page) << 8) | (addr))
#define REG2ADDR(reg)		((reg) & 0xff)
#define REG2PAGE(reg)		(((reg) >> 8) & 0xff)
#define REG_CURRENT_PAGE		0xff
#define REG_VERSION_LSB		REG(0x00, 0x00)     /* read */
#define REG_MAIN_CNTRL0		REG(0x00, 0x01)     /* read/write */
#define  MAIN_CNTRL0_SR		BIT(0)
#define  MAIN_CNTRL0_DECS	BIT(1)
#define  MAIN_CNTRL0_DEHS	BIT(2)
#define  MAIN_CNTRL0_CECS	BIT(3)
#define  MAIN_CNTRL0_CEHS	BIT(4)
#define  MAIN_CNTRL0_SCALER	BIT(7)
#define REG_VERSION_MSB		REG(0x00, 0x02)     /* read */
#define REG_SOFTRESET		REG(0x00, 0x0a)     /* write */
#define  SOFTRESET_AUDIO	BIT(0)
#define  SOFTRESET_I2C_MASTER	BIT(1)
#define REG_DDC_DISABLE		REG(0x00, 0x0b)     /* read/write */
#define REG_I2C_MASTER		REG(0x00, 0x0d)     /* read/write */
#define  I2C_MASTER_DIS_MM	BIT(0)
#define  I2C_MASTER_DIS_FILT	BIT(1)
#define  I2C_MASTER_APP_STRT_LAT BIT(2)
#define REG_FEAT_POWERDOWN	REG(0x00, 0x0e)     /* read/write */
#define  FEAT_POWERDOWN_PREFILT	BIT(0)
#define  FEAT_POWERDOWN_CSC	BIT(1)
#define  FEAT_POWERDOWN_SPDIF	BIT(3)
#define REG_INT_FLAGS_0		REG(0x00, 0x0f)     /* read/write */
#define REG_INT_FLAGS_1		REG(0x00, 0x10)     /* read/write */
#define REG_INT_FLAGS_2		REG(0x00, 0x11)     /* read/write */
#define  INT_FLAGS_2_EDID_BLK_RD  BIT(1)
#define REG_ENA_VP_0		REG(0x00, 0x18)     /* read/write */
#define REG_ENA_VP_1		REG(0x00, 0x19)     /* read/write */
#define REG_ENA_VP_2		REG(0x00, 0x1a)     /* read/write */
#define REG_ENA_AP		REG(0x00, 0x1e)     /* read/write */
#define REG_VIP_CNTRL_0		REG(0x00, 0x20)     /* write */
#define  VIP_CNTRL_0_MIRR_A	BIT(7)
#define  VIP_CNTRL_0_SWAP_A(x)	(((x) & 7) << 4)
#define  VIP_CNTRL_0_MIRR_B	BIT(3)
#define  VIP_CNTRL_0_SWAP_B(x)	(((x) & 7) << 0)
#define REG_VIP_CNTRL_1		REG(0x00, 0x21)     /* write */
#define  VIP_CNTRL_1_MIRR_C	BIT(7)
#define  VIP_CNTRL_1_SWAP_C(x)	(((x) & 7) << 4)
#define  VIP_CNTRL_1_MIRR_D	BIT(3)
#define  VIP_CNTRL_1_SWAP_D(x)	(((x) & 7) << 0)
#define REG_VIP_CNTRL_2		REG(0x00, 0x22)     /* write */
#define  VIP_CNTRL_2_MIRR_E	BIT(7)
#define  VIP_CNTRL_2_SWAP_E(x)	(((x) & 7) << 4)
#define  VIP_CNTRL_2_MIRR_F	BIT(3)
#define  VIP_CNTRL_2_SWAP_F(x)	(((x) & 7) << 0)
#define REG_VIP_CNTRL_3		REG(0x00, 0x23)     /* write */
#define  VIP_CNTRL_3_X_TGL	BIT(0)
#define  VIP_CNTRL_3_H_TGL	BIT(1)
#define  VIP_CNTRL_3_V_TGL	BIT(2)
#define  VIP_CNTRL_3_EMB	BIT(3)
#define  VIP_CNTRL_3_SYNC_DE	BIT(4)
#define  VIP_CNTRL_3_SYNC_HS	BIT(5)
#define  VIP_CNTRL_3_DE_INT	BIT(6)
#define  VIP_CNTRL_3_EDGE	BIT(7)
#define REG_VIP_CNTRL_4		REG(0x00, 0x24)     /* write */
#define  VIP_CNTRL_4_BLC(x)	(((x) & 3) << 0)
#define  VIP_CNTRL_4_BLANKIT(x)	(((x) & 3) << 2)
#define  VIP_CNTRL_4_CCIR656	BIT(4)
#define  VIP_CNTRL_4_656_ALT	BIT(5)
#define  VIP_CNTRL_4_TST_656	BIT(6)
#define  VIP_CNTRL_4_TST_PAT	BIT(7)
#define REG_VIP_CNTRL_5		REG(0x00, 0x25)     /* write */
#define  VIP_CNTRL_5_CKCASE	BIT(0)
#define  VIP_CNTRL_5_SP_CNT(x)	(((x) & 3) << 1)
#define REG_MUX_VP_VIP_OUT	REG(0x00, 0x27)     /* read/write */
#define REG_MAT_CONTRL		REG(0x00, 0x80)     /* write */
#define  MAT_CONTRL_MAT_SC(x)	(((x) & 3) << 0)
#define  MAT_CONTRL_MAT_BP	BIT(2)
#define REG_VIDFORMAT		REG(0x00, 0xa0)     /* write */
#define REG_REFPIX_MSB		REG(0x00, 0xa1)     /* write */
#define REG_REFPIX_LSB		REG(0x00, 0xa2)     /* write */
#define REG_REFLINE_MSB		REG(0x00, 0xa3)     /* write */
#define REG_REFLINE_LSB		REG(0x00, 0xa4)     /* write */
#define REG_NPIX_MSB		REG(0x00, 0xa5)     /* write */
#define REG_NPIX_LSB		REG(0x00, 0xa6)     /* write */
#define REG_NLINE_MSB		REG(0x00, 0xa7)     /* write */
#define REG_NLINE_LSB		REG(0x00, 0xa8)     /* write */
#define REG_VS_LINE_STRT_1_MSB	REG(0x00, 0xa9)     /* write */
#define REG_VS_LINE_STRT_1_LSB	REG(0x00, 0xaa)     /* write */
#define REG_VS_PIX_STRT_1_MSB	REG(0x00, 0xab)     /* write */
#define REG_VS_PIX_STRT_1_LSB	REG(0x00, 0xac)     /* write */
#define REG_VS_LINE_END_1_MSB	REG(0x00, 0xad)     /* write */
#define REG_VS_LINE_END_1_LSB	REG(0x00, 0xae)     /* write */
#define REG_VS_PIX_END_1_MSB	REG(0x00, 0xaf)     /* write */
#define REG_VS_PIX_END_1_LSB	REG(0x00, 0xb0)     /* write */
#define REG_VS_LINE_STRT_2_MSB	REG(0x00, 0xb1)     /* write */
#define REG_VS_LINE_STRT_2_LSB	REG(0x00, 0xb2)     /* write */
#define REG_VS_PIX_STRT_2_MSB	REG(0x00, 0xb3)     /* write */
#define REG_VS_PIX_STRT_2_LSB	REG(0x00, 0xb4)     /* write */
#define REG_VS_LINE_END_2_MSB	REG(0x00, 0xb5)     /* write */
#define REG_VS_LINE_END_2_LSB	REG(0x00, 0xb6)     /* write */
#define REG_VS_PIX_END_2_MSB	REG(0x00, 0xb7)     /* write */
#define REG_VS_PIX_END_2_LSB	REG(0x00, 0xb8)     /* write */
#define REG_HS_PIX_START_MSB	REG(0x00, 0xb9)     /* write */
#define REG_HS_PIX_START_LSB	REG(0x00, 0xba)     /* write */
#define REG_HS_PIX_STOP_MSB	REG(0x00, 0xbb)     /* write */
#define REG_HS_PIX_STOP_LSB	REG(0x00, 0xbc)     /* write */
#define REG_VWIN_START_1_MSB	REG(0x00, 0xbd)     /* write */
#define REG_VWIN_START_1_LSB	REG(0x00, 0xbe)     /* write */
#define REG_VWIN_END_1_MSB	REG(0x00, 0xbf)     /* write */
#define REG_VWIN_END_1_LSB	REG(0x00, 0xc0)     /* write */
#define REG_VWIN_START_2_MSB	REG(0x00, 0xc1)     /* write */
#define REG_VWIN_START_2_LSB	REG(0x00, 0xc2)     /* write */
#define REG_VWIN_END_2_MSB	REG(0x00, 0xc3)     /* write */
#define REG_VWIN_END_2_LSB	REG(0x00, 0xc4)     /* write */
#define REG_DE_START_MSB	REG(0x00, 0xc5)     /* write */
#define REG_DE_START_LSB	REG(0x00, 0xc6)     /* write */
#define REG_DE_STOP_MSB		REG(0x00, 0xc7)     /* write */
#define REG_DE_STOP_LSB		REG(0x00, 0xc8)     /* write */
#define REG_TBG_CNTRL_0		REG(0x00, 0xca)     /* write */
#define  TBG_CNTRL_0_TOP_TGL	BIT(0)
#define  TBG_CNTRL_0_TOP_SEL	BIT(1)
#define  TBG_CNTRL_0_DE_EXT	BIT(2)
#define  TBG_CNTRL_0_TOP_EXT	BIT(3)
#define  TBG_CNTRL_0_FRAME_DIS	BIT(5)
#define  TBG_CNTRL_0_SYNC_MTHD	BIT(6)
#define  TBG_CNTRL_0_SYNC_ONCE	BIT(7)
#define REG_TBG_CNTRL_1		REG(0x00, 0xcb)     /* write */
#define  TBG_CNTRL_1_H_TGL	BIT(0)
#define  TBG_CNTRL_1_V_TGL	BIT(1)
#define  TBG_CNTRL_1_TGL_EN	BIT(2)
#define  TBG_CNTRL_1_X_EXT	BIT(3)
#define  TBG_CNTRL_1_H_EXT	BIT(4)
#define  TBG_CNTRL_1_V_EXT	BIT(5)
#define  TBG_CNTRL_1_DWIN_DIS	BIT(6)
#define REG_ENABLE_SPACE	REG(0x00, 0xd6)     /* write */
#define REG_HVF_CNTRL_0		REG(0x00, 0xe4)     /* write */
#define  HVF_CNTRL_0_SM		BIT(7)
#define  HVF_CNTRL_0_RWB	BIT(6)
#define  HVF_CNTRL_0_PREFIL(x)	(((x) & 3) << 2)
#define  HVF_CNTRL_0_INTPOL(x)	(((x) & 3) << 0)
#define REG_HVF_CNTRL_1		REG(0x00, 0xe5)     /* write */
#define  HVF_CNTRL_1_FOR	BIT(0)
#define  HVF_CNTRL_1_YUVBLK	BIT(1)
#define  HVF_CNTRL_1_VQR(x)	(((x) & 3) << 2)
#define  HVF_CNTRL_1_PAD(x)	(((x) & 3) << 4)
#define REG_RPT_CNTRL		REG(0x00, 0xf0)     /* write */
#define REG_AIP_CLKSEL		REG(0x00, 0xfd)     /* write */
#define  AIP_CLKSEL_AIP_SPDIF	(0 << 3)
#define  AIP_CLKSEL_AIP_I2S	BIT(3)
#define  AIP_CLKSEL_FS_ACLK	(0 << 0)
#define  AIP_CLKSEL_FS_MCLK	BIT(0)
#define REG_PLL_SERIAL_1	REG(0x02, 0x00)     /* read/write */
#define  PLL_SERIAL_1_SRL_FDN	   BIT(0)
#define  PLL_SERIAL_1_SRL_IZ(x)	   (((x) & 3) << 1)
#define  PLL_SERIAL_1_SRL_MAN_IZ   BIT(6)
#define REG_PLL_SERIAL_2	REG(0x02, 0x01)     /* read/write */
#define  PLL_SERIAL_2_SRL_NOSC(x)  ((x) << 0)
#define  PLL_SERIAL_2_SRL_PR(x)	   (((x) & 0xf) << 4)
#define REG_PLL_SERIAL_3	REG(0x02, 0x02)     /* read/write */
#define  PLL_SERIAL_3_SRL_CCIR	   BIT(0)
#define  PLL_SERIAL_3_SRL_DE	   BIT(2)
#define  PLL_SERIAL_3_SRL_PXIN_SEL BIT(4)
#define REG_SERIALIZER		REG(0x02, 0x03)     /* read/write */
#define REG_BUFFER_OUT		REG(0x02, 0x04)     /* read/write */
#define REG_PLL_SCG1		REG(0x02, 0x05)     /* read/write */
#define REG_PLL_SCG2		REG(0x02, 0x06)     /* read/write */
#define REG_PLL_SCGN1		REG(0x02, 0x07)     /* read/write */
#define REG_PLL_SCGN2		REG(0x02, 0x08)     /* read/write */
#define REG_PLL_SCGR1		REG(0x02, 0x09)     /* read/write */
#define REG_PLL_SCGR2		REG(0x02, 0x0a)     /* read/write */
#define REG_AUDIO_DIV		REG(0x02, 0x0e)     /* read/write */
#define  AUDIO_DIV_SERCLK_1	0
#define  AUDIO_DIV_SERCLK_2	1
#define  AUDIO_DIV_SERCLK_4	2
#define  AUDIO_DIV_SERCLK_8	3
#define  AUDIO_DIV_SERCLK_16	4
#define  AUDIO_DIV_SERCLK_32	5
#define REG_SEL_CLK		REG(0x02, 0x11)     /* read/write */
#define  SEL_CLK_SEL_CLK1	BIT(0)
#define  SEL_CLK_SEL_VRF_CLK(x)	(((x) & 3) << 1)
#define  SEL_CLK_ENA_SC_CLK	BIT(3)
#define REG_ANA_GENERAL		REG(0x02, 0x12)     /* read/write */
#define REG_EDID_DATA_0		REG(0x09, 0x00)     /* read */
#define REG_EDID_CTRL		REG(0x09, 0xfa)     /* read/write */
#define REG_DDC_ADDR		REG(0x09, 0xfb)     /* read/write */
#define REG_DDC_OFFS		REG(0x09, 0xfc)     /* read/write */
#define REG_DDC_SEGM_ADDR	REG(0x09, 0xfd)     /* read/write */
#define REG_DDC_SEGM		REG(0x09, 0xfe)     /* read/write */
#define REG_AIP_CNTRL_0		REG(0x11, 0x00)     /* read/write */
#define  AIP_CNTRL_0_RST_FIFO	BIT(0)
#define REG_ENC_CNTRL		REG(0x11, 0x0d)     /* read/write */
#define  ENC_CNTRL_RST_ENC	BIT(0)
#define  ENC_CNTRL_RST_SEL	BIT(1)
#define  ENC_CNTRL_CTL_CODE(x)	(((x) & 3) << 2)
#define REG_TX3			REG(0x12, 0x9a)     /* read/write */
#define REG_TX4			REG(0x12, 0x9b)     /* read/write */
#define  TX4_PD_RAM		BIT(1)
#define REG_TX33		REG(0x12, 0xb8)     /* read/write */
#define  TX33_HDMI		BIT(1)
#define REG_CEC_FRO_IM_CLK_CTRL		0xfb	    /* read/write */
#define  CEC_FRO_IM_CLK_CTRL_GHOST_DIS	BIT(7)
#define  CEC_FRO_IM_CLK_CTRL_ENA_OTP	BIT(6)
#define  CEC_FRO_IM_CLK_CTRL_IMCLK_SEL	BIT(1)
#define  CEC_FRO_IM_CLK_CTRL_FRO_DIV	BIT(0)
#define REG_CEC_RXSHPDINTENA		0xfc	    /* read/write */
#define REG_CEC_RXSHPDINT		0xfd	    /* read */
#define  CEC_RXSHPDINT_RXSENS		BIT(0)
#define  CEC_RXSHPDINT_HPD		BIT(1)
#define TDA19988_CEC_ENAMODS		0xff	    /* read/write */
#define  CEC_ENAMODS_EN_RXSENS		BIT(2)
#define  CEC_ENAMODS_EN_HDMI		BIT(1)
#define  CEC_ENAMODS_EN_CEC		BIT(0)
#define TDA9989N2	0x0101
#define TDA19989	0x0201
#define TDA19989N2	0x0202
#define TDA19988	0x0301
