#include <common.h>
#include <dm.h>
#include <linux/unaligned/be_byteshift.h>
#include <tpm-v1.h>
#include <tpm-v2.h>
#include "tpm_internal.h"
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
