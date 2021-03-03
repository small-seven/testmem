#include <common.h>
#include <usb.h>
#include <asm/io.h>
#include <hwconfig.h>
#include <fsl_errata.h>
#include <fsl_usb.h>
#include <fdt_support.h>
#ifndef CONFIG_USB_MAX_CONTROLLER_COUNT
#define CONFIG_USB_MAX_CONTROLLER_COUNT 1
#endif
#define FSL_USB2_MPH	"fsl-usb2-mph"
#define FSL_USB2_DR	"fsl-usb2-dr"
#define CHIPIDEA_USB2	"chipidea,usb2"
#define SNPS_DWC3	"snps,dwc3"
