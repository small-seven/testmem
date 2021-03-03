#include <config.h>
#include <common.h>
#include <command.h>
#include <cpu_func.h>
#include <tsec.h>
#include <fm_eth.h>
#include <netdev.h>
#include <asm/cache.h>
#include <asm/io.h>
#include <vsc9953.h>
#if defined(CONFIG_MPC85xx)
#elif defined(CONFIG_MPC86xx)
#endif
#ifdef CONFIG_SYS_FSL_QORIQ_CHASSIS2
#ifdef CONFIG_HETROGENOUS_CLUSTERS
#endif
#else /* CONFIG_SYS_FSL_QORIQ_CHASSIS2 */
#define compute_ppc_cpumask()	1
#define fsl_qoriq_core_to_cluster(x) x
#endif /* CONFIG_SYS_FSL_QORIQ_CHASSIS2 */
#define MPC8xxx_PICFRR_NCPU_MASK  0x00001f00
#define MPC8xxx_PICFRR_NCPU_SHIFT 8
#ifdef CONFIG_HETROGENOUS_CLUSTERS
#endif
#ifdef CONFIG_HETROGENOUS_CLUSTERS
#endif
#if defined(CONFIG_ETHER_ON_FCC)
#endif
#if defined(CONFIG_UEC_ETH)
#endif
#if defined(CONFIG_TSEC_ENET) || defined(CONFIG_MPC85XX_FEC)
#endif
#ifdef CONFIG_FMAN_ENET
#endif
#ifdef CONFIG_VSC9953
#endif
