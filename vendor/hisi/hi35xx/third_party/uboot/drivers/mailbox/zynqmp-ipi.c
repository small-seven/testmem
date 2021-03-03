#include <common.h>
#include <asm/io.h>
#include <dm.h>
#include <mailbox-uclass.h>
#include <mach/sys_proto.h>
#include <linux/ioport.h>
#include <linux/io.h>
#include <wait_bit.h>
#define IPI_BIT_MASK_PMU0     0x10000
#define IPI_INT_REG_BASE_APU  0xFF300000
#define ipi_int_apu ((struct ipi_int_regs *)IPI_INT_REG_BASE_APU)
