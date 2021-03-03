#include <common.h>
#include <i2c.h>
#include <linux/errno.h>
#define KM_XLX_PROGRAM_B_PIN    39
#define BOCO_ADDR	0x10
#define ID_REG		0x00
#define BOCO2_ID	0x5b
#define SPI_REG		0x06
#define CFG_EEPROM	0x02
#define FPGA_PROG	0x04
#define FPGA_INIT_B	0x10
#define FPGA_DONE	0x20
#if defined(KM_PCIE_RESET_MPP7)
#define KM_PEX_RST_GPIO_PIN	7
#else
#define PRST1		0x4
#define PCIE_RST	0x10
#define TRAFFIC_RST	0x04
#endif
