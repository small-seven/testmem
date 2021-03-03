#include <common.h>             /* core U-Boot definitions */
#include <xilinx.h>             /* xilinx specific definitions */
#include <altera.h>             /* altera specific definitions */
#include <lattice.h>
#ifndef CONFIG_MAX_FPGA_DEVICES
#define CONFIG_MAX_FPGA_DEVICES		5
#endif
#if defined(CONFIG_FPGA_XILINX)
#else
#endif
#if defined(CONFIG_FPGA_ALTERA)
#else
#endif
#if defined(CONFIG_FPGA_LATTICE)
#else
#endif
#if defined(CONFIG_CMD_FPGA_LOADFS)
#if defined(CONFIG_FPGA_XILINX)
#else
#endif
#endif
#if defined(CONFIG_CMD_FPGA_LOAD_SECURE)
#if defined(CONFIG_FPGA_XILINX)
#else
#endif
#endif
#if defined(CONFIG_FPGA_XILINX)
#else
#endif
#if defined(CONFIG_FPGA_ALTERA)
#else
#endif
#if defined(CONFIG_FPGA_LATTICE)
#else
#endif
#if defined(CONFIG_FPGA_XILINX)
#else
#endif
#if defined(CONFIG_FPGA_ALTERA)
#else
#endif
#if defined(CONFIG_FPGA_LATTICE)
#else
#endif
