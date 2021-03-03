#include <common.h>
#include <command.h>
#include <init.h>
#include <pci.h>
#include <asm/fsl_pci.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <asm/fsl_serdes.h>
#include <linux/errno.h>
#include "kmp204x.h"
#define PROM_SEL_L	11
#define CONF_SEL_L	10
#define FPGA_PROG_L	19
#define FPGA_DONE	18
#define FPGA_INIT_L	17
#define PCIE_SW_RST	14
#define PEXHC_RST	13
#define HOOPER_RST	12
