#include <common.h>
#include <dm.h>
#include <log.h>
#include <tee.h>
#include <linux/arm-smccc.h>
#include <linux/io.h>
#include "optee_smc.h"
#include "optee_msg.h"
#include "optee_private.h"
#define PAGELIST_ENTRIES_PER_PAGE \
typedef void (optee_invoke_fn)(unsigned long, unsigned long, unsigned long,
			       unsigned long, unsigned long, unsigned long,
			       unsigned long, unsigned long,
			       struct arm_smccc_res *);

struct optee_pdata {
	optee_invoke_fn *invoke_fn;
};
