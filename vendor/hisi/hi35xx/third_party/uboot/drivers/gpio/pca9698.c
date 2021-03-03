#include <common.h>
#include <i2c.h>
#include <linux/errno.h>
#include <pca9698.h>
#define PCA9698_REG_INPUT		0x00
#define PCA9698_REG_OUTPUT		0x08
#define PCA9698_REG_POLARITY		0x10
#define PCA9698_REG_CONFIG		0x18
#define PCA9698_BUFFER_SIZE		5
#define PCA9698_GPIO_COUNT		40
void pca9698_free(unsigned gpio)
{
}
