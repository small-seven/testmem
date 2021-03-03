#include <common.h>
#include <dm.h>
#include <reset-uclass.h>
#include <linux/bitops.h>
#include <linux/io.h>
#include <linux/sizes.h>
#define UNIPHIER_RESET_ACTIVE_LOW		BIT(0)
#define UNIPHIER_RESET_ID_END		(unsigned int)(-1)
#define UNIPHIER_RESET_END				\
#define UNIPHIER_RESET(_id, _reg, _bit)			\
#define UNIPHIER_RESETX(_id, _reg, _bit)		\
#define UNIPHIER_MIO_RESET_SD(id, ch)			\
#define UNIPHIER_MIO_RESET_SD_BRIDGE(id, ch)		\
#define UNIPHIER_MIO_RESET_EMMC_HW_RESET(id, ch)	\
#define UNIPHIER_MIO_RESET_USB2(id, ch)			\
#define UNIPHIER_MIO_RESET_USB2_BRIDGE(id, ch)		\
#define UNIPHIER_MIO_RESET_DMAC(id)			\
#define UNIPHIER_PERI_RESET_UART(id, ch)		\
#define UNIPHIER_PERI_RESET_I2C(id, ch)			\
#define UNIPHIER_PERI_RESET_FI2C(id, ch)		\
static int uniphier_reset_free(struct reset_ctl *reset_ctl)
{
	return 0;
}
