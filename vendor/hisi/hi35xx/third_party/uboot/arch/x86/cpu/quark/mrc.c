#include <common.h>
#include <version.h>
#include <asm/arch/mrc.h>
#include <asm/arch/msg_port.h>
#include "mrc_util.h"
#include "smc.h"
static void mrc_mem_init(struct mrc_params *mrc_params)
{
	int i;

	ENTERFN();

	/* MRC started */
	mrc_post_code(0x01, 0x00);

	if (mrc_params->boot_mode != BM_COLD) {
		if (mrc_params->ddr_speed != mrc_params->timings.ddr_speed) {
			/* full training required as frequency changed */
			mrc_params->boot_mode = BM_COLD;
		}
	}

	for (i = 0; i < ARRAY_SIZE(init); i++) {
		uint64_t my_tsc;

		if (mrc_params->boot_mode & init[i].boot_path) {
			uint8_t major = init[i].post_code >> 8 & 0xff;
			uint8_t minor = init[i].post_code >> 0 & 0xff;
			mrc_post_code(major, minor);

			my_tsc = rdtsc();
			init[i].init_fn(mrc_params);
			DPF(D_TIME, "Execution time %llx", rdtsc() - my_tsc);
		}
	}

	/* display the timings */
	print_timings(mrc_params);

	/* MRC complete */
	mrc_post_code(0x01, 0xff);

	LEAVEFN();
}
