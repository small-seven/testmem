#include "ddr3_init.h"
#include "mv_ddr_common.h"
#include "xor_regs.h"
#ifdef MV_DEBUG
#define DB(x)	x
#else
#define DB(x)
#endif
int mv_xor_mem_init(u32 chan, u32 start_ptr, unsigned long long block_size,
		    u32 init_val_high, u32 init_val_low)
{
	u32 temp;

	if (block_size == _4G)
		block_size -= 1;

	/* Parameter checking */
	if (chan >= MV_XOR_MAX_CHAN)
		return MV_BAD_PARAM;

	if (MV_ACTIVE == mv_xor_state_get(chan))
		return MV_BUSY;

	if ((block_size < XEXBSR_BLOCK_SIZE_MIN_VALUE) ||
	    (block_size > XEXBSR_BLOCK_SIZE_MAX_VALUE))
		return MV_BAD_PARAM;

	/* set the operation mode to Memory Init */
	temp = reg_read(XOR_CONFIG_REG(XOR_UNIT(chan), XOR_CHAN(chan)));
	temp &= ~XEXCR_OPERATION_MODE_MASK;
	temp |= XEXCR_OPERATION_MODE_MEM_INIT;
	reg_write(XOR_CONFIG_REG(XOR_UNIT(chan), XOR_CHAN(chan)), temp);

	/*
	 * update the start_ptr field in XOR Engine [0..1] Destination Pointer
	 * Register
	 */
	reg_write(XOR_DST_PTR_REG(XOR_UNIT(chan), XOR_CHAN(chan)), start_ptr);

	/*
	 * update the Block_size field in the XOR Engine[0..1] Block Size
	 * Registers
	 */
	reg_write(XOR_BLOCK_SIZE_REG(XOR_UNIT(chan), XOR_CHAN(chan)),
		  block_size);

	/*
	 * update the field Init_val_l in the XOR Engine Initial Value Register
	 * Low (XEIVRL)
	 */
	reg_write(XOR_INIT_VAL_LOW_REG(XOR_UNIT(chan)), init_val_low);

	/*
	 * update the field Init_val_h in the XOR Engine Initial Value Register
	 * High (XEIVRH)
	 */
	reg_write(XOR_INIT_VAL_HIGH_REG(XOR_UNIT(chan)), init_val_high);

	/* start transfer */
	reg_bit_set(XOR_ACTIVATION_REG(XOR_UNIT(chan), XOR_CHAN(chan)),
		    XEXACTR_XESTART_MASK);

	return MV_OK;
}
#if defined(CONFIG_ARMADA_38X) || defined(CONFIG_ARMADA_39X)
#endif
