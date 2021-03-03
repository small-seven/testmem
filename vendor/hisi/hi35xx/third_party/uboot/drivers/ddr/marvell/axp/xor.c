#include <common.h>
#include <i2c.h>
#include <spl.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include "xor.h"
#include "xor_regs.h"
int mv_xor_mem_init(u32 chan, u32 start_ptr, u32 block_size, u32 init_val_high,
		    u32 init_val_low)
{
	u32 tmp;

	/* Parameter checking */
	if (chan >= MV_XOR_MAX_CHAN)
		return MV_BAD_PARAM;

	if (MV_ACTIVE == mv_xor_state_get(chan))
		return MV_BUSY;

	if ((block_size < XEXBSR_BLOCK_SIZE_MIN_VALUE) ||
	    (block_size > XEXBSR_BLOCK_SIZE_MAX_VALUE))
		return MV_BAD_PARAM;

	/* Set the operation mode to Memory Init */
	tmp = reg_read(XOR_CONFIG_REG(XOR_UNIT(chan), XOR_CHAN(chan)));
	tmp &= ~XEXCR_OPERATION_MODE_MASK;
	tmp |= XEXCR_OPERATION_MODE_MEM_INIT;
	reg_write(XOR_CONFIG_REG(XOR_UNIT(chan), XOR_CHAN(chan)), tmp);

	/*
	 * Update the start_ptr field in XOR Engine [0..1] Destination Pointer
	 * Register (XExDPR0)
	 */
	reg_write(XOR_DST_PTR_REG(XOR_UNIT(chan), XOR_CHAN(chan)), start_ptr);

	/*
	 * Update the BlockSize field in the XOR Engine[0..1] Block Size
	 * Registers (XExBSR)
	 */
	reg_write(XOR_BLOCK_SIZE_REG(XOR_UNIT(chan), XOR_CHAN(chan)),
		  block_size);

	/*
	 * Update the field InitValL in the XOR Engine Initial Value Register
	 * Low (XEIVRL)
	 */
	reg_write(XOR_INIT_VAL_LOW_REG(XOR_UNIT(chan)), init_val_low);

	/*
	 * Update the field InitValH in the XOR Engine Initial Value Register
	 * High (XEIVRH)
	 */
	reg_write(XOR_INIT_VAL_HIGH_REG(XOR_UNIT(chan)), init_val_high);

	/* Start transfer */
	reg_bit_set(XOR_ACTIVATION_REG(XOR_UNIT(chan), XOR_CHAN(chan)),
		    XEXACTR_XESTART_MASK);

	return MV_OK;
}
