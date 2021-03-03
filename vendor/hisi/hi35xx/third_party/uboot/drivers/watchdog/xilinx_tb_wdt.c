#include <common.h>
#include <dm.h>
#include <wdt.h>
#include <linux/io.h>
#define XWT_CSR0_WRS_MASK	0x00000008 /* Reset status Mask */
#define XWT_CSR0_WDS_MASK	0x00000004 /* Timer state Mask */
#define XWT_CSR0_EWDT1_MASK	0x00000002 /* Enable bit 1 Mask*/
#define XWT_CSRX_EWDT2_MASK	0x00000001 /* Enable bit 2 Mask */
