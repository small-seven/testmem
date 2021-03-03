#include <common.h>
#include <dm.h>
#include <errno.h>
#include <i2c.h>
#include <misc.h>
#include <sysreset.h>
#include <time.h>
#include <dm/device.h>
#include <dm/lists.h>
#include <power/pmic.h>
#include <power/stpmic1.h>
#define STPMIC1_NUM_OF_REGS 0x100
#define STPMIC1_NVM_SIZE 8
#define STPMIC1_NVM_POLL_TIMEOUT 100000
#define STPMIC1_NVM_START_ADDRESS 0xf8
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif /* DM_REGULATOR */
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif /* DM_REGULATOR */
#ifndef CONFIG_SPL_BUILD
#endif /* CONFIG_SPL_BUILD */
#ifdef CONFIG_SYSRESET
#endif
