#include <common.h>
#include <netdev.h>
#include <asm/fsl_serdes.h>
#include <fm_eth.h>
#include <fsl_mdio.h>
#include <malloc.h>
#include <fdt_support.h>
#include <fsl_dtsec.h>
#ifdef CONFIG_FMAN_ENET
#define FIRST_PORT_ADDR 3
#define SECOND_PORT_ADDR 7
#ifdef CONFIG_ARCH_P5040
#define FIRST_PORT FM1_DTSEC5
#define SECOND_PORT FM2_DTSEC5
#else
#define FIRST_PORT FM1_DTSEC4
#define SECOND_PORT FM1_DTSEC5
#endif
#define IS_VALID_PORT(p)  ((p) == FIRST_PORT || (p) == SECOND_PORT)
#endif
#ifdef CONFIG_FMAN_ENET
#ifdef CONFIG_ARCH_P5040
#endif
#endif
