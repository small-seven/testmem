#include <common.h>
#include <env.h>
#include "fsl_8xxx_misc.h"
#ifdef CONFIG_SYS_FORM_CUSTOM
#elif CONFIG_SYS_FORM_6U_CPCI
#elif CONFIG_SYS_FORM_ATCA_PMC
#elif CONFIG_SYS_FORM_ATCA_AMC
#elif CONFIG_SYS_FORM_VME
#elif CONFIG_SYS_FORM_6U_VPX
#elif CONFIG_SYS_FORM_PMC
#elif CONFIG_SYS_FORM_PCI
#elif CONFIG_SYS_FORM_3U_CPCI
#elif CONFIG_SYS_FORM_AMC
#elif CONFIG_SYS_FORM_XMC
#elif CONFIG_SYS_FORM_PMC_XMC
#elif CONFIG_SYS_FORM_PCI_EXPRESS
#elif CONFIG_SYS_FORM_3U_VPX
#else
#error "Form factor not defined"
#endif
