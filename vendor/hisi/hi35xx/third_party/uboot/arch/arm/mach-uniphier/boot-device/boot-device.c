#include <common.h>
#include <spl.h>
#include <stdio.h>
#include <linux/io.h>
#include <linux/log2.h>
#include "../init.h"
#include "../sbc/sbc-regs.h"
#include "../sg-regs.h"
#include "../soc-info.h"
#include "boot-device.h"
#if defined(CONFIG_ARCH_UNIPHIER_LD4)
#endif
#if defined(CONFIG_ARCH_UNIPHIER_PRO4)
#endif
#if defined(CONFIG_ARCH_UNIPHIER_SLD8)
#endif
#if defined(CONFIG_ARCH_UNIPHIER_PRO5)
#endif
#if defined(CONFIG_ARCH_UNIPHIER_PXS2)
#endif
#if defined(CONFIG_ARCH_UNIPHIER_LD6B)
#endif
#if defined(CONFIG_ARCH_UNIPHIER_LD11)
#endif
#if defined(CONFIG_ARCH_UNIPHIER_LD20)
#endif
#if defined(CONFIG_ARCH_UNIPHIER_PXS3)
#endif
#ifndef CONFIG_SPL_BUILD
#endif /* !CONFIG_SPL_BUILD */
