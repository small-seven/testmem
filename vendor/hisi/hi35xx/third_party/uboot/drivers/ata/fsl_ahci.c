#include <common.h>
#include <cpu_func.h>
#include <asm/fsl_serdes.h>
#include <dm/lists.h>
#include <dm.h>
#include <ahci.h>
#include <scsi.h>
#include <libata.h>
#include <sata.h>
#include <malloc.h>
#include <memalign.h>
#include <fis.h>
#include "fsl_sata.h"
#ifdef CONFIG_MPC85xx
#endif
#ifdef CONFIG_LBA48
#endif
#ifdef DEBUG
#endif
