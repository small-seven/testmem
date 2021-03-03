#include <common.h>
#include <ide.h>
#include <init.h>
#include <netdev.h>
#include <asm/processor.h>
#include <asm/io.h>
#define FPGA_BASE		0xA4000000
#define FPGA_CFCTL		(FPGA_BASE + 0x04)
#define CFCTL_EN		(0x432)
#define FPGA_CFPOW		(FPGA_BASE + 0x06)
#define CFPOW_ON		(0x02)
#define FPGA_CFCDINTCLR	(FPGA_BASE + 0x2A)
#define CFCDINTCLR_EN	(0x01)
