#include <common.h>
#include <linux/libfdt.h>
#include <linux/libfdt_env.h>
#include <fdt_support.h>
#include <fm_eth.h>
#ifdef CONFIG_FSL_LAYERSCAPE
#include <asm/arch/fsl_serdes.h>
#else
#include <asm/fsl_serdes.h>
#endif
