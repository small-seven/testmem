#include "mipi_tx_hal.h"
#include <common.h>
#include <asm/io.h>
#include <malloc.h>
#include "type.h"
#include "mipi_tx_reg.h"
#define MIPI_TX_REGS_ADDR 0x11170000
#define MIPI_TX_REGS_SIZE 0x10000
#define MIPI_TX_CRG 0x1201011C
#ifndef HI_FPGA
#define MIPI_TX_IO_CONFIG 0x1F001088
#define MIPI_TX_GPIO0_0   0x12140010
#define MIPI_TX_GPIO0_1   0x12140400
#define MIPI_TX_GPIO6_0   0x12146004
#define MIPI_TX_GPIO6_1   0x12146400
#endif
#define MIPI_TX_REF_CLK 27
#define TLPX          60
#define TCLK_PREPARE  60
#define TCLK_ZERO     250
#define TCLK_TRAIL    80
#define TPRE_DELAY    100
#define THS_PREPARE   80
#define THS_ZERO      180
#define THS_TRAIL     110
#define PLL_SET0 0x14
#define PLL_SET1 0x15
#define PLL_SET2 0x16
#ifdef HI_FPGA
#define PLL_SET3 0x17
#endif
#define PLL_SET4  0x1E
#define PLL_SET12 0x12
#define PLL_SET13 0x13
#define DATA0_TPRE_DELAY 0x30
#define DATA1_TPRE_DELAY 0x40
#define DATA2_TPRE_DELAY 0x50
#define DATA3_TPRE_DELAY 0x60
#define CLK_TLPX         0x22
#define CLK_TCLK_PREPARE 0x23
#define CLK_TCLK_ZERO    0x24
#define CLK_TCLK_TRAIL   0x25
#define DATA0_TLPX        0x32
#define DATA0_THS_PREPARE 0x33
#define DATA0_THS_ZERO    0x34
#define DATA0_THS_TRAIL   0x35
#define DATA1_TLPX        0x42
#define DATA1_THS_PREPARE 0x43
#define DATA1_THS_ZERO    0x44
#define DATA1_THS_TRAIL   0x45
#define DATA2_TLPX        0x52
#define DATA2_THS_PREPARE 0x53
#define DATA2_THS_ZERO    0x54
#define DATA2_THS_TRAIL   0x55
#define DATA3_TLPX        0x62
#define DATA3_THS_PREPARE 0x63
#define DATA3_THS_ZERO    0x64
#define DATA3_THS_TRAIL   0x65
#define MIPI_TX_READ_TIMEOUT_CNT 1000
#define MIPI_TX_MAX_RESET_PHY_TIMES 10
#define PREPARE_COMPENSATE 10
#define ROUNDUP_VALUE 7999
#define INNER_PEROID 8000 /* 8 * 1000 ,1000 is 1us = 1000ns, 8 is division ratio */
#define IO_ADDRESS(x) (x)
#if MIPI_TX_DEBUG
#endif
#ifdef HI_FPGA
#endif
#ifndef HI_FPGA
#else
#endif
#ifndef HI_FPGA
#else
#endif
#ifdef HI_FPGA
#endif
#ifdef MIPI_TX_DEBUG
#endif
#ifdef MIPI_TX_DEBUG
#endif
#ifdef MIPI_TX_DEBUG
#endif
#ifdef MIPI_TX_DEBUG
#endif
#ifndef HI_FPGA
#endif
