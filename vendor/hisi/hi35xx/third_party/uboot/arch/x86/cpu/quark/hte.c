#include <common.h>
#include <asm/arch/mrc.h>
#include <asm/arch/msg_port.h>
#include "mrc_util.h"
#include "hte.h"
u32 hte_mem_init(struct mrc_params *mrc_params, u8 flag)
{
	u32 offset;
	int test_num;
	int i;

	/*
	 * Clear out the error registers at the start of each memory
	 * init or memory test run.
	 */
	hte_clear_error_regs();

	msg_port_write(HTE, 0x00020062, 0x00000015);

	for (offset = 0x80; offset <= 0x8f; offset++)
		msg_port_write(HTE, offset, ((offset & 1) ? 0xa55a : 0x5aa5));

	msg_port_write(HTE, 0x00020021, 0x00000000);
	msg_port_write(HTE, 0x00020022, (mrc_params->mem_size >> 6) - 1);
	msg_port_write(HTE, 0x00020063, 0xaaaaaaaa);
	msg_port_write(HTE, 0x00020064, 0xcccccccc);
	msg_port_write(HTE, 0x00020065, 0xf0f0f0f0);
	msg_port_write(HTE, 0x00020066, 0x03000000);

	switch (flag) {
	case MRC_MEM_INIT:
		/*
		 * Only 1 write pass through memory is needed
		 * to initialize ECC
		 */
		test_num = 1;
		break;
	case MRC_MEM_TEST:
		/* Write/read then write/read with inverted pattern */
		test_num = 4;
		break;
	default:
		DPF(D_INFO, "Unknown parameter for flag: %d\n", flag);
		return 0xffffffff;
	}

	DPF(D_INFO, "hte_mem_init");

	for (i = 0; i < test_num; i++) {
		DPF(D_INFO, ".");

		if (i == 0) {
			msg_port_write(HTE, 0x00020061, 0x00000000);
			msg_port_write(HTE, 0x00020020, 0x00110010);
		} else if (i == 1) {
			msg_port_write(HTE, 0x00020061, 0x00000000);
			msg_port_write(HTE, 0x00020020, 0x00010010);
		} else if (i == 2) {
			msg_port_write(HTE, 0x00020061, 0x00010100);
			msg_port_write(HTE, 0x00020020, 0x00110010);
		} else {
			msg_port_write(HTE, 0x00020061, 0x00010100);
			msg_port_write(HTE, 0x00020020, 0x00010010);
		}

		msg_port_write(HTE, 0x00020011, 0x00111000);
		msg_port_write(HTE, 0x00020011, 0x00111100);

		hte_wait_for_complete();

		/* If this is a READ pass, check for errors at the end */
		if ((i % 2) == 1) {
			/* Return immediately if error */
			if (hte_check_errors())
				break;
		}
	}

	DPF(D_INFO, "done\n");

	return hte_check_errors();
}
