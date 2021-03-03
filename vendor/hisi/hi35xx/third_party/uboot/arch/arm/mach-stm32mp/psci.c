#include <config.h>
#include <common.h>
#include <asm/armv7.h>
#include <asm/gic.h>
#include <asm/io.h>
#include <asm/psci.h>
#include <asm/secure.h>
#define BOOT_API_A7_CORE0_MAGIC_NUMBER	0xCA7FACE0
#define BOOT_API_A7_CORE1_MAGIC_NUMBER	0xCA7FACE1
#define MPIDR_AFF0			GENMASK(7, 0)
#define RCC_MP_GRSTCSETR		(STM32_RCC_BASE + 0x0404)
#define RCC_MP_GRSTCSETR_MPUP1RST	BIT(5)
#define RCC_MP_GRSTCSETR_MPUP0RST	BIT(4)
#define RCC_MP_GRSTCSETR_MPSYSRST	BIT(0)
#define STM32MP1_PSCI_NR_CPUS		2
#if STM32MP1_PSCI_NR_CPUS > CONFIG_ARMV7_PSCI_NR_CPUS
#error "invalid value for CONFIG_ARMV7_PSCI_NR_CPUS"
#endif
