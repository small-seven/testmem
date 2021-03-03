#include <common.h>
#include <pci.h>
#include <asm/io.h>
#include <linux/sizes.h>
#include <errno.h>
#define PERI_CRG_BASE       0x12010000
#define CONF_BASE_ADDR  0x12200000
#define PCIE_EP_CONF_BASE   0x20000000
#define PCI_MEM_ADDR        0x30000000
#define __128MB__   0x8000000
#define PCI_MEM_SIZE    0x8000000
#define PCIE_SYS_STATE0 0xf00
#define PCIE_XMLH_LINK_UP   15
#define PCIE_RDLH_LINK_UP   5
#define pcie_cfg_reg(reg)   ((reg) & 0xffc)   /* set dword align */
#define PCIE_SYS_CTRL7      0xc1c
#define PCIE_APP_LTSSM_ENBALE   11
#define PERI_CRG44      0x18c
#define PCIE_X2_SRST_REQ    2
#define PCI_CARD        0x44
#define PCIE_SYS_CTRL0      0xc00
#define PCIE_DEVICE_TYPE    28
#define PCIE_WM_RC      0x4
#define PCIE_X2_AUX_CKEN    7
#define PCIE_X2_PIPE_CKEN   6
#define PCIE_X2_SYS_CKEN    5
#define PCIE_X2_BUS_CKEN    4
#define PCI_CLASS_REVISION  0x08
#define PCI_COMMAND     0x04
