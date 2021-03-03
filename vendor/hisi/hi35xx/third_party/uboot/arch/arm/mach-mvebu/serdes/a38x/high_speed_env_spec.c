#include <common.h>
#include <spl.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include "high_speed_env_spec.h"
#include "sys_env_lib.h"
#include "ctrl_pex.h"
#if defined(CONFIG_ARMADA_38X)
#elif defined(CONFIG_ARMADA_39X)
#else
#error "No device is defined"
#endif
#define	SERDES_VERSION		"2.0"
#define ENDED_OK		"High speed PHY - Ended Successfully\n"
#define LINK_WAIT_CNTR		100
#define LINK_WAIT_SLEEP		100
#define MAX_UNIT_NUMB		4
#define TOPOLOGY_TEST_OK	0
#define WRONG_NUMBER_OF_UNITS	1
#define SERDES_ALREADY_IN_USE	2
#define UNIT_NUMBER_VIOLATION	3
#ifdef CONFIG_ARMADA_39X
#endif
#ifdef CONFIG_ARMADA_38X
#endif
#ifdef CONFIG_ARMADA_39X
#endif
#ifdef CONFIG_ARMADA_39X
#endif
#ifdef CONFIG_ARMADA_39X
#endif
#ifdef CONFIG_ARMADA_39X
#endif
