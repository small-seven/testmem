#include <asm/io.h>
#include <common.h>
#include <fsl_dcu_fb.h>
#include <i2c.h>
#include <linux/fb.h>
#define PIXEL_CLK_LSB_REG		0x00
#define PIXEL_CLK_MSB_REG		0x01
#define VERT_FREQ_LSB_REG		0x02
#define VERT_FREQ_MSB_REG		0x03
#define TOTAL_PIXELS_LSB_REG		0x04
#define TOTAL_PIXELS_MSB_REG		0x05
#define TOTAL_LINES_LSB_REG		0x06
#define TOTAL_LINES_MSB_REG		0x07
#define TPI_INBUS_FMT_REG		0x08
#define TPI_INPUT_FMT_REG		0x09
#define TPI_OUTPUT_FMT_REG		0x0A
#define TPI_SYS_CTRL_REG		0x1A
#define TPI_PWR_STAT_REG		0x1E
#define TPI_AUDIO_HANDING_REG		0x25
#define TPI_AUDIO_INTF_REG		0x26
#define TPI_AUDIO_FREQ_REG		0x27
#define TPI_SET_PAGE_REG		0xBC
#define TPI_SET_OFFSET_REG		0xBD
#define TPI_RW_ACCESS_REG		0xBE
#define TPI_TRANS_MODE_REG		0xC7
#define TPI_INBUS_CLOCK_RATIO_1		(1 << 6)
#define TPI_INBUS_FULL_PIXEL_WIDE	(1 << 5)
#define TPI_INBUS_RISING_EDGE		(1 << 4)
#define TPI_INPUT_CLR_DEPTH_8BIT	(0 << 6)
#define TPI_INPUT_VRANGE_EXPAN_AUTO	(0 << 2)
#define TPI_INPUT_CLR_RGB		(0 << 0)
#define TPI_OUTPUT_CLR_DEPTH_8BIT	(0 << 6)
#define TPI_OUTPUT_VRANGE_COMPRE_AUTO	(0 << 2)
#define TPI_OUTPUT_CLR_HDMI_RGB		(0 << 0)
#define TPI_SYS_TMDS_OUTPUT		(0 << 4)
#define TPI_SYS_AV_NORAML		(0 << 3)
#define TPI_SYS_AV_MUTE			(1 << 3)
#define TPI_SYS_DVI_MODE		(0 << 0)
#define TPI_SYS_HDMI_MODE		(1 << 0)
#define TPI_PWR_STAT_MASK		(3 << 0)
#define TPI_PWR_STAT_D0			(0 << 0)
#define TPI_AUDIO_PASS_BASIC		(0 << 0)
#define TPI_AUDIO_INTF_I2S		(2 << 6)
#define TPI_AUDIO_INTF_NORMAL		(0 << 4)
#define TPI_AUDIO_TYPE_PCM		(1 << 0)
#define TPI_AUDIO_SAMP_SIZE_16BIT	(1 << 6)
#define TPI_AUDIO_SAMP_FREQ_44K		(2 << 3)
#define TPI_SET_PAGE_SII9022A		0x01
#define TPI_SET_OFFSET_SII9022A		0x82
#define TPI_RW_EN_SRC_TERMIN		(1 << 0)
#define TPI_TRANS_MODE_ENABLE		(0 << 7)
