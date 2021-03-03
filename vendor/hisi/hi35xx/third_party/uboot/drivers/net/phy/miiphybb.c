#include <common.h>
#include <ioports.h>
#include <ppc_asm.tmpl>
#include <miiphy.h>
#define BB_MII_RELOCATE(v,off) (v += (v?off:0))
#ifndef CONFIG_BITBANGMII_MULTI
#ifdef MII_INIT
#endif
#ifdef MDIO_DECLARE
#endif
#ifdef MDIO_DECLARE
#endif
#ifdef MDIO_DECLARE
#endif
#ifdef MDIO_DECLARE
#endif
#ifdef MDC_DECLARE
#endif
#endif
#if defined(CONFIG_NEEDS_MANUAL_RELOC)
#endif
#ifdef CONFIG_BITBANGMII_MULTI
#else
#endif
#ifdef DEBUG
#endif
