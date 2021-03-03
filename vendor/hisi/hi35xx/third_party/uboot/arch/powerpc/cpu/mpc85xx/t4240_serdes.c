#include <common.h>
#include <asm/fsl_serdes.h>
#include <asm/processor.h>
#include <asm/io.h>
#include "fsl_corenet2_serdes.h"
#ifdef CONFIG_ARCH_T4240
#elif defined(CONFIG_ARCH_T4160)
#else
#error "Need to define SerDes protocol"
#endif
