#include <common.h>
#include <mpc83xx.h>
#include <ioports.h>
#include <asm/io.h>
#include <asm/processor.h>
#ifdef CONFIG_USB_EHCI_FSL
#include <usb/ehci-ci.h>
#endif
#include "lblaw/lblaw.h"
#include "elbc/elbc.h"
#include "sysio/sysio.h"
#include "arbiter/arbiter.h"
#include "initreg/initreg.h"
#ifdef CONFIG_QE
#endif
#ifdef CONFIG_SYS_SCCR_ENCCM /* Encryption clock mode */
#endif
#ifdef CONFIG_SYS_SCCR_PCICM /* PCI & DMA clock mode */
#endif
#ifdef CONFIG_SYS_SCCR_PCIEXP1CM	/* PCIE1 clock mode */
#endif
#ifdef CONFIG_SYS_SCCR_PCIEXP2CM	/* PCIE2 clock mode */
#endif
#ifdef CONFIG_SYS_SCCR_TSECCM /* all TSEC's clock mode */
#endif
#ifdef CONFIG_SYS_SCCR_TSEC1CM /* TSEC1 clock mode */
#endif
#ifdef CONFIG_SYS_SCCR_TSEC2CM /* TSEC2 clock mode */
#endif
#ifdef CONFIG_SYS_SCCR_TSEC1ON /* TSEC1 clock switch */
#endif
#ifdef CONFIG_SYS_SCCR_TSEC2ON /* TSEC2 clock switch */
#endif
#ifdef CONFIG_SYS_SCCR_USBMPHCM /* USB MPH clock mode */
#endif
#ifdef CONFIG_SYS_SCCR_USBDRCM /* USB DR clock mode */
#endif
#ifdef CONFIG_SYS_SCCR_SATACM /* SATA controller clock mode */
#endif
#ifdef CONFIG_SYS_SCCR_ENCCM /* Encryption clock mode */
#endif
#ifdef CONFIG_SYS_SCCR_PCICM /* PCI & DMA clock mode */
#endif
#ifdef CONFIG_SYS_SCCR_PCIEXP1CM	/* PCIE1 clock mode */
#endif
#ifdef CONFIG_SYS_SCCR_PCIEXP2CM	/* PCIE2 clock mode */
#endif
#ifdef CONFIG_SYS_SCCR_TSECCM /* all TSEC's clock mode */
#endif
#ifdef CONFIG_SYS_SCCR_TSEC1CM /* TSEC1 clock mode */
#endif
#ifdef CONFIG_SYS_SCCR_TSEC2CM /* TSEC2 clock mode */
#endif
#ifdef CONFIG_SYS_SCCR_TSEC1ON /* TSEC1 clock switch */
#endif
#ifdef CONFIG_SYS_SCCR_TSEC2ON /* TSEC2 clock switch */
#endif
#ifdef CONFIG_SYS_SCCR_USBMPHCM /* USB MPH clock mode */
#endif
#ifdef CONFIG_SYS_SCCR_USBDRCM /* USB DR clock mode */
#endif
#ifdef CONFIG_SYS_SCCR_SATACM /* SATA controller clock mode */
#endif
#ifdef CONFIG_SYS_SICRH
#if defined(CONFIG_ARCH_MPC834X) || defined(CONFIG_ARCH_MPC8313)
#else
#endif
#endif
#ifdef CONFIG_SYS_SICRL
#endif
#ifdef CONFIG_SYS_GPR1
#endif
#ifdef CONFIG_SYS_DDRCDR /* DDR control driver register */
#endif
#ifdef CONFIG_SYS_OBIR /* Output buffer impedance register */
#endif
#ifdef CONFIG_QE
#endif
#if defined(CONFIG_SYS_LBLAWBAR0_PRELIM) && defined(CONFIG_SYS_LBLAWAR0_PRELIM)
#else
#error	CONFIG_SYS_LBLAWBAR0_PRELIM & CONFIG_SYS_LBLAWAR0_PRELIM must be defined
#endif
#if defined(CONFIG_SYS_LBLAWBAR1_PRELIM) && defined(CONFIG_SYS_LBLAWAR1_PRELIM)
#endif
#if defined(CONFIG_SYS_LBLAWBAR2_PRELIM) && defined(CONFIG_SYS_LBLAWAR2_PRELIM)
#endif
#if defined(CONFIG_SYS_LBLAWBAR3_PRELIM) && defined(CONFIG_SYS_LBLAWAR3_PRELIM)
#endif
#if defined(CONFIG_SYS_LBLAWBAR4_PRELIM) && defined(CONFIG_SYS_LBLAWAR4_PRELIM)
#endif
#if defined(CONFIG_SYS_LBLAWBAR5_PRELIM) && defined(CONFIG_SYS_LBLAWAR5_PRELIM)
#endif
#if defined(CONFIG_SYS_LBLAWBAR6_PRELIM) && defined(CONFIG_SYS_LBLAWAR6_PRELIM)
#endif
#if defined(CONFIG_SYS_LBLAWBAR7_PRELIM) && defined(CONFIG_SYS_LBLAWAR7_PRELIM)
#endif
#ifdef CONFIG_SYS_GPIO1_PRELIM
#endif
#ifdef CONFIG_SYS_GPIO2_PRELIM
#endif
#if defined(CONFIG_USB_EHCI_FSL) && defined(CONFIG_ARCH_MPC831X)
#endif
#ifdef CONFIG_QE
#endif
#if defined(CONFIG_DISPLAY_AER_FULL)
#elif defined(CONFIG_DISPLAY_AER_BRIEF)
#endif /* CONFIG_DISPLAY_AER_xxxx */
#ifndef CONFIG_CPU_MPC83XX
#if defined(CONFIG_DISPLAY_AER_FULL) || defined(CONFIG_DISPLAY_AER_BRIEF)
#endif
#endif
