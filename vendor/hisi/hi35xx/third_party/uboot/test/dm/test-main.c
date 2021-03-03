#include <common.h>
#include <command.h>
#include <console.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <asm/state.h>
#include <dm/test.h>
#include <dm/root.h>
#include <dm/uclass-internal.h>
#include <test/ut.h>
#ifdef CONFIG_OF_LIVE
#endif
static int dm_test_destroy(struct unit_test_state *uts)
{
	int id;

	for (id = 0; id < UCLASS_COUNT; id++) {
		struct uclass *uc;

		/*
		 * If the uclass doesn't exist we don't want to create it. So
		 * check that here before we call uclass_find_device().
		 */
		uc = uclass_find(id);
		if (!uc)
			continue;
		ut_assertok(uclass_destroy(uc));
	}

	return 0;
}
#ifdef CONFIG_OF_LIVE
#endif
#ifdef CONFIG_OF_LIVE
#endif
