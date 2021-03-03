#include <common.h>
#include <errno.h>
#include <asm/intel_regs.h>
#include <asm/io.h>
#include <asm/arch/pch.h>
#define IOBP_RETRY 1000
#define IOBPIRI		0x2330
#define IOBPD		0x2334
#define IOBPS		0x2338
#define  IOBPS_READY	0x0001
#define  IOBPS_TX_MASK	0x0006
#define  IOBPS_MASK     0xff00
#define  IOBPS_READ     0x0600
#define  IOBPS_WRITE	0x0700
#define IOBPU		0x233a
#define  IOBPU_MAGIC	0xf000
#define  IOBP_PCICFG_READ	0x0400
#define  IOBP_PCICFG_WRITE	0x0500
