#include <common.h>
#include <config.h>
#include <time.h>
#include <asm/fsl_law.h>
#include <asm/fsl_serdes.h>
#include <asm/fsl_srio.h>
#include <linux/errno.h>
#ifdef CONFIG_SRIO_PCIE_BOOT_MASTER
#define SRIO_PORT_ACCEPT_ALL 0x10000001
#define SRIO_IB_ATMU_AR 0x80f55000
#define SRIO_OB_ATMU_AR_MAINT 0x80077000
#define SRIO_OB_ATMU_AR_RW 0x80045000
#define SRIO_LCSBA1CSR_OFFSET 0x5c
#define SRIO_MAINT_WIN_SIZE 0x1000000 /* 16M */
#define SRIO_RW_WIN_SIZE 0x100000 /* 1M */
#define SRIO_LCSBA1CSR 0x60000000
#endif
#if defined(CONFIG_FSL_CORENET)
#ifdef CONFIG_SYS_FSL_QORIQ_CHASSIS2
#else
#endif
#elif defined(CONFIG_MPC85xx)
#elif defined(CONFIG_MPC86xx)
#else
#error "No defines for DEVDISR_SRIO"
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_SRIO_A004034
#endif
#ifdef CONFIG_SYS_FSL_QORIQ_CHASSIS2
#else
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_SRIO_A004034
#endif
#ifdef CONFIG_SRIO2
#ifdef CONFIG_SYS_FSL_ERRATUM_SRIO_A004034
#endif
#endif
#ifdef CONFIG_FSL_CORENET
#endif
#ifdef CONFIG_SRIO_PCIE_BOOT_MASTER
#endif
