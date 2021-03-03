#include <common.h>
#include <console.h>
#include <cpu_func.h>
#include <asm/io.h>
#include <fs.h>
#include <zynqpl.h>
#include <linux/sizes.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sys_proto.h>
#define DEVCFG_CTRL_PCFG_PROG_B		0x40000000
#define DEVCFG_CTRL_PCFG_AES_EFUSE_MASK	0x00001000
#define DEVCFG_CTRL_PCAP_RATE_EN_MASK	0x02000000
#define DEVCFG_ISR_FATAL_ERROR_MASK	0x00740040
#define DEVCFG_ISR_ERROR_FLAGS_MASK	0x00340840
#define DEVCFG_ISR_RX_FIFO_OV		0x00040000
#define DEVCFG_ISR_DMA_DONE		0x00002000
#define DEVCFG_ISR_PCFG_DONE		0x00000004
#define DEVCFG_STATUS_DMA_CMD_Q_F	0x80000000
#define DEVCFG_STATUS_DMA_CMD_Q_E	0x40000000
#define DEVCFG_STATUS_DMA_DONE_CNT_MASK	0x30000000
#define DEVCFG_STATUS_PCFG_INIT		0x00000010
#define DEVCFG_MCTRL_PCAP_LPBK		0x00000010
#define DEVCFG_MCTRL_RFIFO_FLUSH	0x00000002
#define DEVCFG_MCTRL_WFIFO_FLUSH	0x00000001
#ifndef CONFIG_SYS_FPGA_WAIT
#define CONFIG_SYS_FPGA_WAIT CONFIG_SYS_HZ/100	/* 10 ms */
#endif
#ifndef CONFIG_SYS_FPGA_PROG_TIME
#define CONFIG_SYS_FPGA_PROG_TIME	(CONFIG_SYS_HZ * 4) /* 4 s */
#endif
#define DUMMY_WORD	0xffffffff
#define SWAP_NO		1
#define SWAP_DONE	2
#if defined(CONFIG_CMD_FPGA_LOADFS) && !defined(CONFIG_SPL_BUILD)
#endif
#if defined(CONFIG_CMD_FPGA_LOADFS) && !defined(CONFIG_SPL_BUILD)
#endif
#ifdef CONFIG_CMD_ZYNQ_AES
#endif
