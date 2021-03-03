#include <common.h>
#include <env.h>
#include <pci.h>
#include <usb.h>
#include <asm/io.h>
#include <usb/ehci-ci.h>
#include <hwconfig.h>
#include <fsl_usb.h>
#include <fdt_support.h>
#include <dm.h>
#include "ehci.h"
#ifndef CONFIG_USB_MAX_CONTROLLER_COUNT
#define CONFIG_USB_MAX_CONTROLLER_COUNT 1
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#else
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#ifdef CONFIG_PPC
#else
#endif
#ifdef CONFIG_PPC
#else
#endif
#else
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#else
#endif
#if !CONFIG_IS_ENABLED(DM_USB)
#endif
#ifdef CONFIG_SYS_FSL_USB_INTERNAL_UTMI_PHY
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#else
#endif
#ifdef CONFIG_SYS_FSL_USB_INTERNAL_UTMI_PHY
#else
#endif
#if defined(CONFIG_SYS_FSL_USB_INTERNAL_UTMI_PHY)
#endif
