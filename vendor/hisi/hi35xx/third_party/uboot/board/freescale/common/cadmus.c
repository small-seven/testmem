#include <common.h>
#ifndef CONFIG_SYS_CADMUS_BASE_REG
#define CONFIG_SYS_CADMUS_BASE_REG	(CADMUS_BASE_ADDR + 0x4000)
#endif
typedef struct cadmus_reg {
    u_char cm_ver;		/* Board version */
    u_char cm_csr;		/* General control/status */
    u_char cm_rst;		/* Reset control */
    u_char cm_hsclk;		/* High speed clock */
    u_char cm_hsxclk;		/* High speed clock extended */
    u_char cm_led;		/* LED data */
    u_char cm_pci;		/* PCI control/status */
    u_char cm_dma;		/* DMA control */
    u_char cm_reserved[248];	/* Total 256 bytes */
} cadmus_reg_t;
